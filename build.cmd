@echo off
cls
color 0F
echo.
echo --- Stryxus.Lib.C Dependency Build Tool ---  
echo -----------------------------------
echo IMPORTANT: This tool MUST be opened in Visual Studio's x64 Native Dev Tools Command Prompt!!!
echo This process may take several minutes depending on how powerful your CPU is.
echo.
echo.
cd %~dp0
rd /s /q Build
mkdir Build
cd Build
mkdir Debug
cd Debug
echo.
echo -- Working at %~dp0
echo.
echo -- Running CMakeLists
echo.
cmake ../../
echo.
echo.
echo -- Starting To Build Projects.
echo.
echo.
echo -------------------- BUILDING cJSON --------------------
echo.
echo.
cmake --build . --target %~dp0Build\Debug\cJSON\ALL_BUILD
echo.
echo.
echo.
echo -- Build Finished!
echo.