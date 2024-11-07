@echo off

if "%1" == "" (
  echo Usage: build.bat [-a^|-m^|-r^]
  exit /b 1
)

set "current_dir=%CD%"
cd /d "%~dp0"

if "%1" == "-a" (
  if exist "build" (
    echo # Deleting existing build directory
    pushd "build"
    icacls * /reset /t /c /q
    cd ..
    rmdir /s /q "build"
  )
  echo # Creating new build directory
  mkdir build
  cd build
  echo # Running cmake
  cmake ..
  echo # Building the project
  cmake --build .
) else if "%1" == "-m" (
  cd build
  echo # Building the project
  cmake --build .
) else if "%1" == "-r" (
  cd build\Debug
  echo # Running the project
  .\tp0.exe %2
) else (
  echo Usage: build.bat [-a^|-m^|-r^]
)

cd /d "%current_dir%"