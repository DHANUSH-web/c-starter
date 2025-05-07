# PowerShell build script for Windows

param(
    [Parameter(Position=0)]
    [string]$Command,
    
    [Parameter(Position=1)]
    [string]$Option
)

function Build-Debug {
    Write-Host "Building debug version..." -ForegroundColor Green
    cmake --preset win-debug
    cmake --build ./out/win-debug
}

function Build-Release {
    Write-Host "Building release version..." -ForegroundColor Green
    cmake --preset win-release
    cmake --build ./out/win-release
}

function Run-Debug {
    Build-Debug
    ./out/win-debug/main.exe
}

function Run-Release {
    Build-Release
    ./out/win-release/main.exe
}

function Clean-Build {
    param([string]$Type)
    
    switch ($Type) {
        "--debug" {
            Remove-Item -Path "./out/win-debug" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned debug build directory."
        }
        "--release" {
            Remove-Item -Path "./out/win-release" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned release build directory."
        }
        default {
            Remove-Item -Path "./out" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned all build directories."
        }
    }
}

switch ($Command) {
    "run" {
        switch ($Option) {
            $null { Run-Debug }
            "--debug" { Run-Debug }
            "--release" { Run-Release }
            default {
                Write-Host "Invalid option. Use --debug or --release."
                exit 1
            }
        }
    }
    "build" {
        switch ($Option) {
            $null { Build-Debug }
            "--debug" { Build-Debug }
            "--release" { Build-Release }
            "--all" {
                Write-Host "Building both debug and release versions..."
                Build-Debug
                Build-Release
            }
            default {
                Write-Host "Invalid option. Use --debug or --release or --all."
                exit 1
            }
        }
    }
    "clean" {
        Clean-Build $Option
    }
    "help" {
        Write-Host "Usage: .\build.ps1 [run|build|clean|help] [--debug|--release|--all]"
    }
    default {
        Write-Host "Usage: .\build.ps1 run [--debug|--release]"
        exit 1
    }
}