# Full Static audio is the only runtime audio implementation.
# Historical hybrid/reference backends and generic runtime SPC700 learning paths
# were removed from the core; future AOT gaps are repaired from ROM/ARAM
# provenance and regenerated static authority.
set(TOPGEAR_V27_STATIC_AUDIO_SOURCES
    static-audio/topgear-bapu-aot/smp/smp.cpp
    static-audio/topgear-bapu-aot/dsp/sdsp.cpp
    static-audio/topgear-bapu-aot/sc_static_apu.cpp)

file(GLOB TOPGEAR_V22_DISPATCH_GROUPS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22/topgear_v22_group_*.c")
file(GLOB TOPGEAR_V22_REENTRY_GROUPS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry/*.c")

# Current static core only. Historical Version 01-21 route implementations
# are preserved by the previously released Version 27 archives, not carried as
# selectable runtime source in this repaired core.
add_library(topgear-static-recomp STATIC
    src/topgear_runtime_api.c
    src/topgear_runtime_compat.c
    src/topgear_snapshot.c
    src/topgear_machine.c
    src/topgear_hash.c
    src/topgear_audio_transport.c
    src/topgear_audio_backend.c
    ${TOPGEAR_V27_STATIC_AUDIO_SOURCES}
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
        "${CMAKE_CURRENT_SOURCE_DIR}/generated"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22"
        "${CMAKE_CURRENT_SOURCE_DIR}/generated/v22_reentry")
set_target_properties(topgear-static-recomp PROPERTIES OUTPUT_NAME "topgear-static-recomp-v27")
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
    PROPERTIES COMPILE_DEFINITIONS "SC_STATIC_SDSP_PRIMITIVES;SCStaticSPC_DSP_CUSTOM_RUN=1")
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
