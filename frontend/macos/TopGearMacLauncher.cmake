# macOS launcher: a native .app bundle that drives the same static core through
# SDL3 (Metal presentation, Core Audio output, keyboard and gamepad input) with
# AppKit menus and dialogs. Included from the top-level CMakeLists.txt after
# SDL3 has been fetched.

enable_language(OBJC)

set(TOPGEAR_MAC_RESOURCES
    "${CMAKE_SOURCE_DIR}/VERSION.txt"
    "${CMAKE_SOURCE_DIR}/THIRD-PARTY-NOTICES.txt"
    "${CMAKE_SOURCE_DIR}/third_party/gamecontrollerdb.txt"
    "${CMAKE_SOURCE_DIR}/third_party/SDL_GameControllerDB-LICENSE.txt")
# Clean-install Data records are copied to the user's Data folder on first run.
set(TOPGEAR_MAC_DATA_SEEDS
    "${CMAKE_SOURCE_DIR}/Data/player-settings.dat"
    "${CMAKE_SOURCE_DIR}/Data/time-trial.dat"
    "${CMAKE_SOURCE_DIR}/Data/README.txt")

# Settings, audio output and host Data code shared by the app and its tests.
add_library(topgear-mac-frontend STATIC
    frontend/macos/topgear_mac_settings.c
    frontend/macos/topgear_audio_output_sdl.c
    frontend/windows/topgear_audio_resampler.c
    frontend/windows/topgear_app_core.c
    frontend/common/topgear_time_trial_store.c
    frontend/common/topgear_player_settings_file.c
    frontend/common/topgear_input_latch.c)
target_include_directories(topgear-mac-frontend PUBLIC
    frontend/macos
    frontend/common
    frontend/windows)
target_link_libraries(topgear-mac-frontend PUBLIC
    topgear-static-recomp SDL3::SDL3-static)
target_compile_options(topgear-mac-frontend PRIVATE
    -Wall -Wextra -Wpedantic -Werror)

add_executable(topgear-launcher-macos MACOSX_BUNDLE
    frontend/macos/topgear_app_macos.c
    frontend/macos/topgear_mac_ui.m
    ${TOPGEAR_MAC_RESOURCES}
    ${TOPGEAR_MAC_DATA_SEEDS})
set_source_files_properties(${TOPGEAR_MAC_RESOURCES}
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
set_source_files_properties(${TOPGEAR_MAC_DATA_SEEDS}
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources/Data)
target_compile_definitions(topgear-launcher-macos PRIVATE
    TOPGEAR_APP_VERSION="${PROJECT_VERSION}")
target_link_libraries(topgear-launcher-macos PRIVATE
    topgear-mac-frontend "-framework Cocoa")
target_compile_options(topgear-launcher-macos PRIVATE
    -Wall -Wextra -Werror
    $<$<COMPILE_LANGUAGE:C>:-Wpedantic>
    $<$<COMPILE_LANGUAGE:OBJC>:-fobjc-arc>)
set_target_properties(topgear-launcher-macos PROPERTIES
    OUTPUT_NAME "Top Gear"
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/frontend/macos/Info.plist.in"
    MACOSX_BUNDLE_BUNDLE_NAME "Top Gear"
    MACOSX_BUNDLE_GUI_IDENTIFIER "io.github.pablovsouza.topgear-static-recomp"
    MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/release")

# Renamed resources cannot use MACOSX_PACKAGE_LOCATION, so copy them here.
add_custom_command(TARGET topgear-launcher-macos POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_SOURCE_DIR}/frontend/macos/Release-README.txt"
        "$<TARGET_BUNDLE_CONTENT_DIR:topgear-launcher-macos>/Resources/README.txt"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${TOPGEAR_SDL_SOURCE_DIR}/LICENSE.txt"
        "$<TARGET_BUNDLE_CONTENT_DIR:topgear-launcher-macos>/Resources/SDL-LICENSE.txt"
    VERBATIM)

if(BUILD_TESTING)
    foreach(test_name IN ITEMS settings-contract audio-output-contract)
        string(REPLACE "-" "_" test_source "${test_name}")
        add_executable(topgear-mac-${test_name}-test
            frontend/macos/topgear_mac_${test_source}_test.c)
        target_link_libraries(topgear-mac-${test_name}-test PRIVATE
            topgear-mac-frontend)
        target_compile_options(topgear-mac-${test_name}-test PRIVATE
            -Wall -Wextra -Wpedantic -Werror)
        add_test(NAME topgear-mac-${test_name}
            COMMAND topgear-mac-${test_name}-test
                "${CMAKE_BINARY_DIR}/topgear-mac-${test_name}.ini")
    endforeach()
    # Exercise the real SDL audio path without needing a sound device.
    set_tests_properties(topgear-mac-audio-output-contract PROPERTIES
        ENVIRONMENT "SDL_AUDIO_DRIVER=dummy")

    # Opens and closes every AppKit dialog; needs a logged-in GUI session.
    add_executable(topgear-mac-ui-smoke
        frontend/macos/topgear_mac_ui_smoke.m
        frontend/macos/topgear_mac_ui.m)
    target_link_libraries(topgear-mac-ui-smoke PRIVATE
        topgear-mac-frontend "-framework Cocoa")
    target_compile_options(topgear-mac-ui-smoke PRIVATE
        -Wall -Wextra -Werror -fobjc-arc)
    option(TOPGEAR_MAC_UI_SMOKE_TEST
        "Run the AppKit dialog smoke test (requires a GUI session)" OFF)
    if(TOPGEAR_MAC_UI_SMOKE_TEST)
        add_test(NAME topgear-mac-ui-smoke
            COMMAND topgear-mac-ui-smoke 0.2 "${CMAKE_BINARY_DIR}")
    endif()
endif()
