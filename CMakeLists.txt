cmake_minimum_required(VERSION 3.20)
project(TopGearSNESStaticRecomp VERSION 1.2.0 LANGUAGES C CXX)

include(CTest)
set(TOPGEAR_TEST_ROM "" CACHE FILEPATH
    "Optional exact Top Gear US ROM used only by the CTest ROM smoke test")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build the portable release against the static Visual C++ runtime so a clean
# Windows 10/11 installation does not need a matching redistributable.
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if(NOT WIN32)
    message(FATAL_ERROR "This release contains the Windows frontend and static core.")
endif()

add_subdirectory(static-recomp)

if(BUILD_TESTING)
    add_executable(topgear-headless-audio-test
        frontend/headless/topgear_headless.c)
    target_compile_definitions(topgear-headless-audio-test PRIVATE
        TOPGEAR_ENABLE_RESEARCH_API=1)
    target_link_libraries(topgear-headless-audio-test PRIVATE
        topgear-static-recomp)
    if(MSVC)
        target_compile_definitions(topgear-headless-audio-test PRIVATE
            _CRT_SECURE_NO_WARNINGS)
        target_compile_options(topgear-headless-audio-test PRIVATE /W4 /WX)
    else()
        target_compile_options(topgear-headless-audio-test PRIVATE
            -Wall -Wextra -Wpedantic -Werror)
    endif()
    if(TOPGEAR_TEST_ROM)
        foreach(duration IN ITEMS 60 120 180)
            add_test(NAME topgear-audio-route-${duration}s
                COMMAND topgear-headless-audio-test
                    --headless-v27 "${TOPGEAR_TEST_ROM}" ${duration}
                    "${CMAKE_SOURCE_DIR}/static-recomp/tests/routes/one-player-las-vegas.txt"
                    "${CMAKE_BINARY_DIR}/topgear-audio-route-${duration}s")
            set_tests_properties(topgear-audio-route-${duration}s PROPERTIES
                TIMEOUT 120)
        endforeach()
    endif()
endif()

include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(topgear_sdl
    URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.10.zip"
    URL_HASH "SHA256=30DCE54890B17544A35E4521274762016AF6ED59C2183B896EF5E6693E97FB6C"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(topgear_sdl)
FetchContent_GetProperties(topgear_sdl SOURCE_DIR TOPGEAR_SDL_SOURCE_DIR)

add_executable(topgear-launcher WIN32
    frontend/windows/topgear_app_win32.c
    frontend/windows/topgear_app_core.c
    frontend/windows/launcher_version.rc
    frontend/windows/topgear_audio_output_dsound_win32.c
    frontend/windows/topgear_audio_resampler.c
    frontend/windows/topgear_frontend_settings_win32.c
    frontend/common/topgear_input_latch.c
    third_party/topgear-gamepad/topgear_gamepad_input_win32.c)
target_include_directories(topgear-launcher PRIVATE
    frontend/common
    frontend/windows
    third_party/topgear-gamepad)
target_compile_definitions(topgear-launcher PRIVATE
    UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX)
target_link_libraries(topgear-launcher PRIVATE
    topgear-static-recomp SDL3::SDL3-static
    user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm)
set_target_properties(topgear-launcher PROPERTIES
    OUTPUT_NAME "Launcher"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release")

if(MSVC)
    target_compile_definitions(topgear-launcher PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_options(topgear-launcher PRIVATE /W4 /WX)
else()
    target_compile_options(topgear-launcher PRIVATE
        -Wall -Wextra -Wpedantic -Werror -ffunction-sections -fdata-sections)
endif()

if(BUILD_TESTING)
    add_executable(topgear-audio-resampler-test
        frontend/windows/topgear_audio_resampler_test.c
        frontend/windows/topgear_audio_resampler.c)
    target_include_directories(topgear-audio-resampler-test PRIVATE
        frontend/windows)
    add_test(NAME topgear-audio-resampler
        COMMAND topgear-audio-resampler-test)

    add_executable(topgear-audio-settings-contract-test
        frontend/windows/topgear_audio_settings_contract_test.c
        frontend/windows/topgear_audio_output_dsound_win32.c
        frontend/windows/topgear_audio_resampler.c
        frontend/windows/topgear_app_core.c)
    target_include_directories(topgear-audio-settings-contract-test PRIVATE
        frontend/windows)
    target_compile_definitions(topgear-audio-settings-contract-test PRIVATE
        UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
    target_link_libraries(topgear-audio-settings-contract-test PRIVATE
        topgear-static-recomp user32 dsound dxguid winmm)
    add_test(NAME topgear-audio-settings-contract
        COMMAND topgear-audio-settings-contract-test)

    add_executable(topgear-frontend-settings-contract-test
        frontend/windows/topgear_frontend_settings_contract_test.c
        frontend/windows/topgear_frontend_settings_win32.c
        third_party/topgear-gamepad/topgear_gamepad_input_win32.c)
    target_include_directories(topgear-frontend-settings-contract-test PRIVATE
        frontend/windows third_party/topgear-gamepad)
    target_compile_definitions(topgear-frontend-settings-contract-test PRIVATE
        UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
    target_link_libraries(topgear-frontend-settings-contract-test PRIVATE
        topgear-static-recomp SDL3::SDL3-static user32 comctl32)
    add_test(NAME topgear-frontend-settings-contract
        COMMAND topgear-frontend-settings-contract-test)
    if(MSVC)
        target_compile_options(topgear-audio-resampler-test PRIVATE /W4 /WX)
        target_compile_options(topgear-audio-settings-contract-test PRIVATE /W4 /WX)
        target_compile_options(topgear-frontend-settings-contract-test PRIVATE /W4 /WX)
    endif()
endif()

add_custom_command(TARGET topgear-launcher POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/frontend/windows/Release-README.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/README.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/VERSION.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/VERSION.txt"
    COMMAND "${CMAKE_COMMAND}" -E make_directory
        "$<TARGET_FILE_DIR:topgear-launcher>/Rom"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/Rom/Readme.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/Rom/Readme.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/third_party/gamecontrollerdb.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/gamecontrollerdb.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${TOPGEAR_SDL_SOURCE_DIR}/LICENSE.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/SDL-LICENSE.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/third_party/SDL_GameControllerDB-LICENSE.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/SDL_GameControllerDB-LICENSE.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/THIRD-PARTY-NOTICES.txt"
        "$<TARGET_FILE_DIR:topgear-launcher>/THIRD-PARTY-NOTICES.txt"
    VERBATIM)
