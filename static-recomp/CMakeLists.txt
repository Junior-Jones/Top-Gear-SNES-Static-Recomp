# Full Static audio is the only runtime audio implementation.
# Historical hybrid/reference backends and generic runtime SPC700 learning paths
# were removed from the core; future AOT gaps are repaired from ROM/ARAM
# provenance and regenerated static authority.
set(TOPGEAR_STATIC_AUDIO_SOURCES
    static-audio/topgear-project-dsp/topgear_dsp.c
    static-audio/topgear-bapu-aot/smp/smp.cpp
    static-audio/topgear-bapu-aot/dsp/sdsp.cpp
    static-audio/topgear-bapu-aot/sc_static_apu.cpp)

file(GLOB TOPGEAR_V22_DISPATCH_GROUPS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22/topgear_v22_group_*.c")
file(GLOB TOPGEAR_V22_REENTRY_GROUPS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry/*.c")

# Current static core only. Historical development-route implementations are
# preserved by earlier research archives, not carried as selectable runtime
# source in this repaired core.
add_library(topgear-static-recomp STATIC
    src/topgear_runtime_api.c
    src/topgear_runtime_compat.c
    src/topgear_snapshot.c
    src/topgear_machine.c
    src/topgear_hash.c
    src/topgear_audio_transport.c
    src/topgear_audio_backend.c
    ${TOPGEAR_STATIC_AUDIO_SOURCES}
    src/topgear_ppu_dma.c
    src/topgear_v22_scheduler.c
    src/topgear_v22_video.c
    src/topgear_v23_scheduler.c
    generated/topgear_v16_nmi_handler.c
    generated/topgear_v18_nmi_optional_dma.c
    generated/topgear_v23_nominal_timing.c
    generated/topgear_v23_wram_epoch2.c
    generated/topgear_v23_wram_epoch3.c
    generated/v22/topgear_v22_dispatch_index.c
    generated/topgear_v22_interrupt_dispatch.c
    generated/topgear_v22_wram_epoch.c
    ${TOPGEAR_V22_DISPATCH_GROUPS}
    ${TOPGEAR_V22_REENTRY_GROUPS})
target_include_directories(topgear-static-recomp
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/internal"
        "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-bapu-aot"
        "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-bapu-aot/smp"
        "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-bapu-aot/dsp"
        "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-project-dsp/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry")
set_target_properties(topgear-static-recomp PROPERTIES OUTPUT_NAME "topgear-static-recomp")
if(MSVC)
    # The generated 65C816 code deliberately narrows complemented 8-bit masks
    # back to uint8_t. MSVC diagnoses that defined truncation as C4310, so keep
    # the strict warning policy while suppressing only this expected warning.
    target_compile_options(topgear-static-recomp PRIVATE /W4 /WX /wd4310)
else()
    target_compile_options(topgear-static-recomp PRIVATE -Wall -Wextra -Wpedantic -Werror -ffunction-sections -fdata-sections)
endif()

# Full Static audio is always fail-closed AOT at runtime. The generic SPC700
# runtime switch and learning build mode were removed from the project.
target_compile_definitions(topgear-static-recomp PRIVATE SC_SMP_AOT=1)
set_source_files_properties(
    static-audio/topgear-bapu-aot/smp/smp.cpp
    static-audio/topgear-bapu-aot/dsp/sdsp.cpp
    static-audio/topgear-bapu-aot/sc_static_apu.cpp
    PROPERTIES COMPILE_DEFINITIONS "SC_STATIC_SDSP_PRIMITIVES")
set_source_files_properties(
    static-audio/topgear-bapu-aot/smp/smp.cpp
    static-audio/topgear-bapu-aot/dsp/sdsp.cpp
    PROPERTIES COMPILE_OPTIONS "$<$<CXX_COMPILER_ID:MSVC>:/W0>$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-w>")
# The snapshot format intentionally serializes the static S-SMP object image and
# restores its ARAM pointer explicitly. GCC's class-memaccess diagnostic is not
# applicable to this build-owned snapshot ABI; keep all other warnings strict.
set_source_files_properties(
    static-audio/topgear-bapu-aot/sc_static_apu.cpp
    PROPERTIES COMPILE_OPTIONS "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-class-memaccess>")

if(BUILD_TESTING)
    function(topgear_add_core_test target source needs_internal)
        add_executable(${target} "tests/${source}")
        target_link_libraries(${target} PRIVATE topgear-static-recomp)
        if(${needs_internal})
            target_include_directories(${target} PRIVATE
                "${CMAKE_CURRENT_SOURCE_DIR}/internal"
                "${CMAKE_CURRENT_SOURCE_DIR}/generated"
                "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22"
                "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry")
        endif()
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4 /WX)
        else()
            target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME ${target} COMMAND ${target})
    endfunction()

    topgear_add_core_test(topgear-api-surface test_api_surface.c FALSE)
    topgear_add_core_test(topgear-diagnostics-surface test_diagnostics_surface.c FALSE)
    topgear_add_core_test(topgear-renderer-instances test_renderer_instances.c TRUE)
    topgear_add_core_test(topgear-hook-contract test_hook_contract.c TRUE)
    topgear_add_core_test(topgear-audio-fifo test_audio_fifo.c TRUE)
    topgear_add_core_test(topgear-generated-dispatch test_generated_dispatch.c TRUE)
    topgear_add_core_test(topgear-snapshot-contract test_snapshot_contract.c TRUE)

    add_executable(topgear-project-dsp-phase
        tests/test_project_dsp_phase.c)
    target_include_directories(topgear-project-dsp-phase PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-project-dsp/include")
    target_link_libraries(topgear-project-dsp-phase PRIVATE
        topgear-static-recomp)
    if(MSVC)
        target_compile_options(topgear-project-dsp-phase PRIVATE /W4 /WX)
    else()
        target_compile_options(topgear-project-dsp-phase PRIVATE
            -Wall -Wextra -Wpedantic -Werror)
    endif()
    add_test(NAME topgear-project-dsp-phase COMMAND topgear-project-dsp-phase)

    find_package(Python3 COMPONENTS Interpreter QUIET)
    if(Python3_Interpreter_FOUND)
        get_filename_component(TOPGEAR_COMPILER_BIN_DIR
            "${CMAKE_CXX_COMPILER}" DIRECTORY)
        set(TOPGEAR_DUMPBIN "${TOPGEAR_COMPILER_BIN_DIR}/dumpbin.exe")
        add_test(NAME topgear-integrity-manifests
            COMMAND "${Python3_EXECUTABLE}" -B
                    "${CMAKE_SOURCE_DIR}/tools/integrity_manifests.py"
                    --root "${CMAKE_SOURCE_DIR}")
        add_test(NAME topgear-static-audio-purity
            COMMAND "${Python3_EXECUTABLE}" -B
                    "${CMAKE_SOURCE_DIR}/tools/audio/verify_static_audio_purity.py"
                    --root "${CMAKE_SOURCE_DIR}"
                    --library "$<TARGET_FILE:topgear-static-recomp>"
                    --dumpbin "${TOPGEAR_DUMPBIN}")
        add_test(NAME topgear-static-audio-authority
            COMMAND "${Python3_EXECUTABLE}" -B
                    "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_static_audio_authority.py"
                    "${CMAKE_SOURCE_DIR}")
    endif()

    if(TOPGEAR_TEST_ROM)
        add_executable(topgear-rom-smoke tests/test_rom_smoke.c)
        target_link_libraries(topgear-rom-smoke PRIVATE topgear-static-recomp)
        if(MSVC)
            target_compile_options(topgear-rom-smoke PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-rom-smoke PRIVATE
                -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-rom-smoke
            COMMAND topgear-rom-smoke "${TOPGEAR_TEST_ROM}")

        add_executable(topgear-audio-snapshot-continuation
            tests/test_audio_snapshot_continuation.c)
        target_compile_definitions(topgear-audio-snapshot-continuation PRIVATE
            TOPGEAR_ENABLE_RESEARCH_API=1)
        target_link_libraries(topgear-audio-snapshot-continuation PRIVATE
            topgear-static-recomp)
        if(MSVC)
            target_compile_definitions(topgear-audio-snapshot-continuation PRIVATE
                _CRT_SECURE_NO_WARNINGS)
            target_compile_options(topgear-audio-snapshot-continuation PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-audio-snapshot-continuation PRIVATE
                -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-audio-snapshot-continuation
            COMMAND topgear-audio-snapshot-continuation
                    "${TOPGEAR_TEST_ROM}"
                    "${CMAKE_CURRENT_BINARY_DIR}/topgear-audio-continuation.tgs")
    endif()
endif()
