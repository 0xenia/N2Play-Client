set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/client")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/client")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/client")

add_subdirectory(CWebBrowser)
add_subdirectory(EterBase)
add_subdirectory(EterLib)
add_subdirectory(EffectLib)
add_subdirectory(EterGrnLib)
add_subdirectory(EterPythonLib)
add_subdirectory(GameLib)
add_subdirectory(MilesLib)
add_subdirectory(PRTerrainLib)
add_subdirectory(ScriptLib)
add_subdirectory(SpeedTreeLib)
add_subdirectory(SphereLib)
#add_subdirectory(lib)
add_subdirectory(script)
add_subdirectory(Main)

set_target_properties(metin2client_base PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_effects PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_game PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_granny PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_game PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_lib PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_script PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_scriptlib PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_speedtree PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_spherelib PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_terrain PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_ui PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_webview PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_miles PROPERTIES FOLDER Gameclient)
set_target_properties(metin2client_run PROPERTIES FOLDER Gameclient)
