@echo off
cls
color 0F
echo.
echo --- Stryxus.Lib.C Dependency Build Tool ---  
echo -----------------------------------
echo IMPORTANT: This tool MUST be opened in Visual Studio's x64 Native Dev Tools Command Prompt!!!
echo This process may take several minutes depending on how powerful your CPU is.
echo Entering the Visual Studio year version will delete the current /solution/build/ folder and begin the build process.
echo.
echo.
set /p id= -- Enter your Visual Studio year version (2019 etc): 
cd %~dp0
rd /s /q build
rd /s /q %~dp0\libsass\win\bin
mkdir build
cd build
echo.
echo -- Working at %~dp0
echo.
echo -- Running CMakeLists
echo.
cmake ../
echo.
echo.
echo -- Starting To Build Projects.
echo.
echo.
echo -------------------- BUILDING cJSON --------------------
echo.
echo.
cmake --build . --target %~dp0build\cJSON\ALL_BUILD
echo.
echo.
echo.
echo -- Build Finished!
echo.