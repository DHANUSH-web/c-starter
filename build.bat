@echo off
setlocal enabledelayedexpansion

if "%~1"=="" goto :usage

if "%~1"=="run" (
    if "%~2"=="" goto :run_debug
    if "%~2"=="--debug" goto :run_debug
    if "%~2"=="--release" goto :run_release
    echo Invalid option. Use --debug or --release.
    exit /b 1
)

if "%~1"=="build" (
    if "%~2"=="" goto :build_debug
    if "%~2"=="--debug" goto :build_debug
    if "%~2"=="--release" goto :build_release
    if "%~2"=="--all" goto :build_all
    echo Invalid option. Use --debug or --release or --all.
    exit /b 1
)

if "%~1"=="clean" (
    if "%~2"=="--debug" goto :clean_debug
    if "%~2"=="--release" goto :clean_release
    goto :clean_all
)

if "%~1"=="help" goto :usage

:usage
echo Usage: build.bat [run^|build^|clean^|help] [--debug^|--release^|--all]
exit /b 1

:run_debug
call :build_debug
.\out\win-debug\main.exe
exit /b 0

:run_release
call :build_release
.\out\win-release\main.exe
exit /b 0

:build_debug
echo Building debug version...
cmake --preset win-debug
cmake --build ./out/win-debug
exit /b 0

:build_release
echo Building release version...
cmake --preset win-release
cmake --build ./out/win-release
exit /b 0

:build_all
echo Building both debug and release versions...
call :build_debug
call :build_release
exit /b 0

:clean_debug
if exist ".\out\win-debug" (
    rmdir /s /q ".\out\win-debug"
    echo Cleaned debug build directory.
)
exit /b 0

:clean_release
if exist ".\out\win-release" (
    rmdir /s /q ".\out\win-release"
    echo Cleaned release build directory.
)
exit /b 0

:clean_all
if exist ".\out" (
    rmdir /s /q ".\out"
    echo Cleaned all build directories.
)
exit /b 0 