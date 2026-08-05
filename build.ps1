# PowerShell build script for Windows
# Uses $args (not param()) so flags like -d / --debug are not stolen by common parameters.

$Command = if ($args.Count -ge 1) { $args[0] } else { "" }
$Option  = if ($args.Count -ge 2) { $args[1] } else { "" }

function Ensure-Dir {
    param([string]$Path)
    if (-not (Test-Path -LiteralPath $Path)) {
        New-Item -ItemType Directory -Path $Path -Force | Out-Null
    }
}

function Build-Debug {
    Write-Host "Building debug version..." -ForegroundColor Green
    Ensure-Dir "out/debug"

    # main target
    gcc.exe `
        -Iinclude `
        src/core.c src/main.c `
        -o out/debug/main.exe
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

    # test target
    gcc.exe `
        -Iinclude `
        -Iextras/unity/src `
        src/core.c `
        tests/test_core.c `
        extras/unity/src/unity.c `
        -o out/debug/test_main.exe
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

function Build-Release {
    Write-Host "Building release version..." -ForegroundColor Green
    Ensure-Dir "out/release"

    # main target
    gcc.exe `
        -O3 -march=native `
        -Iinclude `
        src/core.c src/main.c `
        -o out/release/main.exe
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

    # test target
    gcc.exe `
        -O3 -march=native `
        -Iinclude `
        -Iextras/unity/src `
        src/core.c `
        tests/test_core.c `
        extras/unity/src/unity.c `
        -o out/release/test_main.exe
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

function Invoke-Exe {
    param(
        [string]$Path,
        [string]$MissingMessage
    )
    if (-not (Test-Path -LiteralPath $Path)) {
        Write-Host $MissingMessage
        return
    }
    & $Path
    if ($null -ne $LASTEXITCODE -and $LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

function Run-Debug {
    Invoke-Exe "out/debug/main.exe" "Debug target not found. Run '.\build.ps1 build' first"
}

function Run-Release {
    Invoke-Exe "out/release/main.exe" "Release target not found. Run '.\build.ps1 build --release' first"
}

function Test-Debug {
    Invoke-Exe "out/debug/test_main.exe" "Debug test target not found. Run '.\build.ps1 build' first"
}

function Test-Release {
    Invoke-Exe "out/release/test_main.exe" "Release test target not found. Run '.\build.ps1 build --release' first"
}

function Clean-Build {
    param([string]$Type)

    switch ($Type) {
        { $_ -in @("--debug", "-d") } {
            Remove-Item -Path "out/debug" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned debug build directory."
        }
        { $_ -in @("--release", "-r") } {
            Remove-Item -Path "out/release" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned release build directory."
        }
        default {
            Remove-Item -Path "out" -Recurse -Force -ErrorAction SilentlyContinue
            Write-Host "Cleaned all build directories."
        }
    }
}

switch ($Command) {
    "run" {
        switch ($Option) {
            { $_ -in @("", "--debug", "-d") } { Run-Debug }
            { $_ -in @("--release", "-r") }   { Run-Release }
            default {
                Write-Host "Invalid option. Use --debug or --release."
                exit 1
            }
        }
    }
    "build" {
        switch ($Option) {
            { $_ -in @("", "--debug", "-d") } {
                Build-Debug
            }
            { $_ -in @("--release", "-r") } {
                Build-Release
            }
            { $_ -in @("--all", "-a") } {
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
    "test" {
        switch ($Option) {
            { $_ -in @("", "--debug", "-d") } { Test-Debug }
            { $_ -in @("--release", "-r") }   { Test-Release }
            default {
                Write-Host "Invalid option. Use --debug or --release."
                exit 1
            }
        }
    }
    "clean" {
        Clean-Build $Option
    }
    "help" {
        Write-Host "Usage: .\build.ps1 [run|build|test|clean|help] [--debug|--release|--all]"
    }
    default {
        Write-Host "Usage: .\build.ps1 [run|build|test|clean|help] [--debug|--release|--all]"
        exit 1
    }
}
