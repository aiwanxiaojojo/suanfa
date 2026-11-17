param(
    [Parameter(Mandatory = $true)]
    [string]$SourceFile
)

$ErrorActionPreference = 'Stop'

$workspace = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $PSScriptRoot 'build'
$sourceCopy = Join-Path $buildDir 'source.cpp'
$program = Join-Path $buildDir 'program.exe'

New-Item -ItemType Directory -Path $buildDir -Force | Out-Null
Copy-Item -LiteralPath $SourceFile -Destination $sourceCopy -Force

Push-Location $workspace
try {
    & 'D:\c\mingw64\bin\g++.exe' `
        '-fdiagnostics-color=always' `
        '-std=c++17' `
        '-finput-charset=UTF-8' `
        '-fexec-charset=UTF-8' `
        '-static' `
        '-static-libgcc' `
        '-static-libstdc++' `
        '-g' `
        $sourceCopy `
        '-o' `
        $program

    exit $LASTEXITCODE
}
finally {
    Pop-Location
}
