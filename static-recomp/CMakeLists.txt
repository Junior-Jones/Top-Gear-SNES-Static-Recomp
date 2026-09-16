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
    src/topgear_mod_music.c
    src/topgear_mod_career.c
    src/topgear_mod_progress.c
    src/topgear_mod_insert_audio.c
    src/topgear_mod_menu_remodel.c
    src/topgear_mod_time_trial.c
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
    PROPERTIES COMPILE_OPTIONS
        "$<$<CXX_COMPILER_ID:GNU>:-Wno-class-memaccess>;$<$<CXX_COMPILER_ID:Clang>:-Wno-nested-anon-types>")

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
    if(NOT WIN32)
        find_package(Threads REQUIRED)
        target_link_libraries(topgear-renderer-instances PRIVATE Threads::Threads)
    endif()
    topgear_add_core_test(topgear-hook-contract test_hook_contract.c TRUE)
    topgear_add_core_test(topgear-audio-fifo test_audio_fifo.c TRUE)
    topgear_add_core_test(topgear-generated-dispatch test_generated_dispatch.c TRUE)
    topgear_add_core_test(topgear-snapshot-contract test_snapshot_contract.c TRUE)
    topgear_add_core_test(topgear-rally-qualification test_rally_qualification.c TRUE)
    topgear_add_core_test(topgear-time-trial test_time_trial.c TRUE)
    topgear_add_core_test(topgear-menu-player-summary test_menu_player_summary.c TRUE)
    topgear_add_core_test(topgear-mode-settings-results test_mode_settings_results.c TRUE)
    target_sources(topgear-mode-settings-results PRIVATE ../frontend/common/topgear_player_settings_file.c)
    target_include_directories(topgear-mode-settings-results PRIVATE ../frontend/common)
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
    add_executable(topgear-voice9 tests/test_voice9.c)
    target_include_directories(topgear-voice9 PRIVATE static-audio/topgear-project-dsp/include)
    target_link_libraries(topgear-voice9 PRIVATE topgear-static-recomp)
    add_test(NAME topgear-voice9 COMMAND topgear-voice9)

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
        add_executable(topgear-results-footer-capture tests/test_results_footer_capture.c)
        target_link_libraries(topgear-results-footer-capture PRIVATE topgear-static-recomp)
        target_include_directories(topgear-results-footer-capture PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/internal" "${CMAKE_CURRENT_SOURCE_DIR}/generated"
            "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22" "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry")
        if(MSVC)
            target_compile_options(topgear-results-footer-capture PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-results-footer-capture PRIVATE -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-results-footer-capture COMMAND topgear-results-footer-capture
            "${TOPGEAR_TEST_ROM}" "${CMAKE_BINARY_DIR}/results-footer")
        set_tests_properties(topgear-results-footer-capture PROPERTIES TIMEOUT 600)
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

        add_executable(topgear-music-upload-chains
            tests/test_music_upload_chains.c)
        target_link_libraries(topgear-music-upload-chains PRIVATE
            topgear-static-recomp)
        if(MSVC)
            target_compile_options(topgear-music-upload-chains PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-music-upload-chains PRIVATE
                -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-music-upload-chains
            COMMAND topgear-music-upload-chains "${TOPGEAR_TEST_ROM}")

        add_executable(topgear-sfx-race-audio
            tests/test_sfx_race_audio.c)
        target_link_libraries(topgear-sfx-race-audio PRIVATE
            topgear-static-recomp)
        if(MSVC)
            target_compile_options(topgear-sfx-race-audio PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-sfx-race-audio PRIVATE
                -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-sfx-race-audio
            COMMAND topgear-sfx-race-audio "${TOPGEAR_TEST_ROM}")

        add_executable(topgear-menu-voice9-route tests/test_menu_voice9_route.c)
        target_include_directories(topgear-menu-voice9-route PRIVATE internal generated generated/v22 generated/v22_reentry)
        target_link_libraries(topgear-menu-voice9-route PRIVATE topgear-static-recomp)
        target_compile_definitions(topgear-menu-voice9-route PRIVATE _CRT_SECURE_NO_WARNINGS)
        file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/voice9-route")
        add_test(NAME topgear-menu-voice9-route COMMAND topgear-menu-voice9-route
            "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/voice9-route")
        set_tests_properties(topgear-menu-voice9-route PROPERTIES TIMEOUT 300)
        add_executable(topgear-menu-insert-audio
            tests/test_menu_insert_audio.c)
        target_include_directories(topgear-menu-insert-audio PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/internal"
            "${CMAKE_CURRENT_SOURCE_DIR}/generated"
            "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22"
            "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry")
        target_link_libraries(topgear-menu-insert-audio PRIVATE
            topgear-static-recomp)
        if(MSVC)
            target_compile_definitions(topgear-menu-insert-audio PRIVATE
                _CRT_SECURE_NO_WARNINGS)
            target_compile_options(topgear-menu-insert-audio PRIVATE /W4 /WX)
        else()
            target_compile_options(topgear-menu-insert-audio PRIVATE
                -Wall -Wextra -Wpedantic -Werror)
        endif()
        add_test(NAME topgear-menu-insert-audio
            COMMAND topgear-menu-insert-audio "${TOPGEAR_TEST_ROM}")
    endif()
endif()

# Isolated ROM-derived sequel AOT engines share the current nine-voice DSP.
foreach(game IN ITEMS tg2 tg3)
    set(engine_dir "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/sequel/${game}")
    add_library(topgear-${game}-engine OBJECT
        "${engine_dir}/smp/smp.cpp" "${engine_dir}/dsp/sdsp.cpp"
        "${engine_dir}/${game}_static_apu.cpp" "${engine_dir}/music_runtime.cpp")
    target_include_directories(topgear-${game}-engine PRIVATE
        "${engine_dir}" "${CMAKE_CURRENT_SOURCE_DIR}/static-audio/topgear-project-dsp/include")
    target_compile_definitions(topgear-${game}-engine PRIVATE SC_SMP_AOT=1 SC_STATIC_SDSP_PRIMITIVES)
    target_sources(topgear-static-recomp PRIVATE $<TARGET_OBJECTS:topgear-${game}-engine>)
    if(BUILD_TESTING)
        add_executable(topgear-${game}-qualification "${engine_dir}/qualification.cpp")
        target_include_directories(topgear-${game}-qualification PRIVATE "${engine_dir}")
        target_link_libraries(topgear-${game}-qualification PRIVATE topgear-static-recomp)
    endif()
endforeach()

if(BUILD_TESTING)
 add_executable(topgear-sequel-runtime tests/test_sequel_runtime.cpp)
 target_link_libraries(topgear-sequel-runtime PRIVATE topgear-static-recomp)
 add_test(NAME topgear-sequel-runtime COMMAND topgear-sequel-runtime)
 foreach(track RANGE 1 3)
  add_test(NAME topgear-tg2-gameplay-${track} COMMAND topgear-sequel-runtime 2 ${track} "${CMAKE_CURRENT_BINARY_DIR}/tg2-gameplay-${track}.pcm" 1922400)
 endforeach()
endif()

if(BUILD_TESTING AND TOPGEAR_TEST_ROM)
 foreach(route IN ITEMS menu career)
  add_executable(topgear-music-${route} tests/test_music_${route}.c)
  target_include_directories(topgear-music-${route} PRIVATE internal generated)
  target_link_libraries(topgear-music-${route} PRIVATE topgear-static-recomp)
  target_compile_definitions(topgear-music-${route} PRIVATE _CRT_SECURE_NO_WARNINGS)
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/music-${route}-receipts")
 endforeach()
 add_test(NAME topgear-music-menu COMMAND topgear-music-menu "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/music-menu-receipts")
 add_test(NAME topgear-music-career COMMAND topgear-music-career "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/music-career-receipts" 7)
endif()

if(BUILD_TESTING AND TOPGEAR_TEST_ROM)
 add_executable(topgear-finish-start tests/test_finish_start.c)
 target_include_directories(topgear-finish-start PRIVATE internal generated)
 target_link_libraries(topgear-finish-start PRIVATE topgear-static-recomp)
 target_compile_definitions(topgear-finish-start PRIVATE _CRT_SECURE_NO_WARNINGS)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/finish-start-receipts")
 add_test(NAME topgear-finish-start COMMAND topgear-finish-start "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/finish-start-receipts")
endif()

if(BUILD_TESTING)
 add_executable(topgear-music-shuffle tests/test_music_shuffle.c ../frontend/common/topgear_player_settings_file.c)
 target_include_directories(topgear-music-shuffle PRIVATE internal generated ../frontend/common)
 target_link_libraries(topgear-music-shuffle PRIVATE topgear-static-recomp)
 add_test(NAME topgear-music-shuffle COMMAND topgear-music-shuffle "${CMAKE_CURRENT_BINARY_DIR}/music-shuffle-state.dat")
endif()

if(BUILD_TESTING AND WIN32 AND TOPGEAR_TEST_ROM)
 add_executable(topgear-music-persistence tests/test_music_persistence.c ../frontend/common/topgear_player_settings_file.c ../frontend/common/topgear_time_trial_store.c)
 target_include_directories(topgear-music-persistence PRIVATE internal generated ../frontend/common ../frontend/windows)
 target_compile_definitions(topgear-music-persistence PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-music-persistence PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/music-persistence")
 add_test(NAME topgear-music-persistence COMMAND topgear-music-persistence "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/music-persistence/player-settings.dat")
endif()

if(BUILD_TESTING AND TOPGEAR_TEST_ROM)
 add_executable(topgear-music-mode-routes tests/test_music_mode_routes.c)
 target_include_directories(topgear-music-mode-routes PRIVATE internal generated)
 target_compile_definitions(topgear-music-mode-routes PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-music-mode-routes PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/music-mode-routes")
 add_test(NAME topgear-music-mode-routes COMMAND topgear-music-mode-routes "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/music-mode-routes")
endif()

if(BUILD_TESTING)
 add_executable(topgear-export-music-player tests/export_music_player_transcripts.c)
 target_include_directories(topgear-export-music-player PRIVATE internal generated static-audio/topgear-bapu-aot)
 target_compile_definitions(topgear-export-music-player PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-export-music-player PRIVATE topgear-static-recomp)
endif()

# Music Player's native TG copy uses the same fail-closed AOT source and DSP.
add_library(topgear-tg0-engine OBJECT
 static-audio/topgear-bapu-aot/smp/smp.cpp
 static-audio/topgear-bapu-aot/dsp/sdsp.cpp
 static-audio/topgear-bapu-aot/sc_static_apu.cpp
 static-audio/sequel/tg0/music_runtime.cpp)
target_include_directories(topgear-tg0-engine PRIVATE static-audio/topgear-bapu-aot static-audio/topgear-project-dsp/include)
target_compile_definitions(topgear-tg0-engine PRIVATE SC_SMP_AOT=1 SC_STATIC_SDSP_PRIMITIVES
 SC_STATIC_SNES=TG0_STATIC_SNES
 sc_static_apu_acquire=tg0_static_apu_acquire
 sc_static_apu_cpu_read_port=tg0_static_apu_cpu_read_port
 sc_static_apu_cpu_write_port=tg0_static_apu_cpu_write_port
 sc_static_apu_cue_endx=tg0_static_apu_cue_endx
 sc_static_apu_mod_write_aram=tg0_static_apu_mod_write_aram
 sc_static_apu_mod_write_dsp_register=tg0_static_apu_mod_write_dsp_register
 sc_static_apu_music_volume=tg0_static_apu_music_volume
 sc_static_apu_native_effects=tg0_static_apu_native_effects
 sc_static_apu_pcm_available=tg0_static_apu_pcm_available
 sc_static_apu_pcm_overflow_count=tg0_static_apu_pcm_overflow_count
 sc_static_apu_pcm_read=tg0_static_apu_pcm_read
 sc_static_apu_read_aram=tg0_static_apu_read_aram
 sc_static_apu_read_cue_aram=tg0_static_apu_read_cue_aram
 sc_static_apu_read_dsp_register=tg0_static_apu_read_dsp_register
 sc_static_apu_release=tg0_static_apu_release
 sc_static_apu_reset=tg0_static_apu_reset
 sc_static_apu_set_cpu_port_observer=tg0_static_apu_set_cpu_port_observer
 sc_static_apu_set_sink=tg0_static_apu_set_sink
 sc_static_apu_set_trace_callbacks=tg0_static_apu_set_trace_callbacks
 sc_static_apu_snapshot_load=tg0_static_apu_snapshot_load
 sc_static_apu_snapshot_save=tg0_static_apu_snapshot_save
 sc_static_apu_snapshot_size=tg0_static_apu_snapshot_size
 sc_static_apu_status=tg0_static_apu_status
 sc_static_apu_sync_to_master=tg0_static_apu_sync_to_master
 sc_static_apu_trace_aram_write_event=tg0_static_apu_trace_aram_write_event
 sc_static_apu_trace_dsp_write_event=tg0_static_apu_trace_dsp_write_event
 sc_static_apu_trace_instruction_event=tg0_static_apu_trace_instruction_event
 sc_static_apu_trace_port_event=tg0_static_apu_trace_port_event
 sc_static_sdsp_brr_step=tg0_static_sdsp_brr_step
 sc_static_sdsp_primitive_step=tg0_static_sdsp_primitive_step
 sc_static_sdsp_report_failure=tg0_static_sdsp_report_failure)
target_sources(topgear-static-recomp PRIVATE $<TARGET_OBJECTS:topgear-tg0-engine>)

if(BUILD_TESTING AND TOPGEAR_TEST_ROM)
 add_executable(topgear-definitive-features tests/test_definitive_features.c)
 target_include_directories(topgear-definitive-features PRIVATE internal generated)
 target_compile_definitions(topgear-definitive-features PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-definitive-features PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/definitive-features")
 add_test(NAME topgear-definitive-features COMMAND topgear-definitive-features "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/definitive-features")
 add_executable(topgear-career-v2 tests/test_career_v2.c)
 target_include_directories(topgear-career-v2 PRIVATE internal generated)
 target_compile_definitions(topgear-career-v2 PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-career-v2 PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/career-v2")
 add_test(NAME topgear-career-v2 COMMAND topgear-career-v2 "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/career-v2")
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/career-audio")
 add_test(NAME topgear-career-audio COMMAND topgear-career-v2 "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/career-audio" --audio)
 add_executable(topgear-continues tests/test_continues.c)
 target_include_directories(topgear-continues PRIVATE internal generated)
 target_compile_definitions(topgear-continues PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-continues PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/continues")
 add_test(NAME topgear-continues COMMAND topgear-continues "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/continues")
 add_executable(topgear-rally-event tests/test_rally_event.c)
 target_include_directories(topgear-rally-event PRIVATE internal generated)
 target_compile_definitions(topgear-rally-event PRIVATE _CRT_SECURE_NO_WARNINGS)
 target_link_libraries(topgear-rally-event PRIVATE topgear-static-recomp)
 file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/rally-event")
 add_test(NAME topgear-rally-event COMMAND topgear-rally-event "${TOPGEAR_TEST_ROM}" "${CMAKE_CURRENT_BINARY_DIR}/rally-event")
endif()
