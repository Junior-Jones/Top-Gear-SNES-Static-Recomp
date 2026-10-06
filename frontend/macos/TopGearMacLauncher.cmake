# macOS launcher: a native .app bundle that drives the same static core through
# SDL3 (Metal presentation, Core Audio output, keyboard and gamepad input).
# Included from the top-level CMakeLists.txt after SDL3 has been fetched.

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

add_executable(topgear-launcher-macos MACOSX_BUNDLE
    frontend/macos/topgear_app_macos.c
    frontend/windows/topgear_app_core.c
    frontend/common/topgear_time_trial_store.c
    frontend/common/topgear_player_settings_file.c
    frontend/common/topgear_input_latch.c
    ${TOPGEAR_MAC_RESOURCES}
    ${TOPGEAR_MAC_DATA_SEEDS})
set_source_files_properties(${TOPGEAR_MAC_RESOURCES}
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
set_source_files_properties(${TOPGEAR_MAC_DATA_SEEDS}
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources/Data)
target_include_directories(topgear-launcher-macos PRIVATE
    frontend/common
    frontend/windows)
target_compile_definitions(topgear-launcher-macos PRIVATE
    TOPGEAR_APP_VERSION="${PROJECT_VERSION}")
target_link_libraries(topgear-launcher-macos PRIVATE
    topgear-static-recomp SDL3::SDL3-static)
target_compile_options(topgear-launcher-macos PRIVATE
    -Wall -Wextra -Wpedantic -Werror)
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
