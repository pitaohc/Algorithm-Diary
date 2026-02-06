# powershell
# 显示帮助信息
function Show-Help {
 @"
用法: .\build.ps1 [-h | --help] [--ide <IDE>] [--clean]

选项:
  -h, --help    显示此帮助信息并退出
  --ide <IDE>   指定生成后要打开的 IDE，可选值：
                - Visual Studio  生成后打开 Visual Studio 解决方案
                - Rider         生成后打开 JetBrains Rider
                - None          仅执行 CMake 配置，不打开 IDE（默认）
  --clean       如果存在 `./build` 目录则删除（仅在传入此参数时删除）

示例:
  .\build.ps1                    # 仅配置 CMake
  .\build.ps1 --ide "Visual Studio"   # 配置后打开 VS
  .\build.ps1 --ide Rider --clean     # 删除 build 目录，配置后打开 Rider
"@
}

# 处理帮助
if ($args -contains "-h" -or $args -contains "--help") {
    Show-Help
    exit 0
}

# 默认值
$ide = "None" # Visual Studio, Rider, None
$clean = $false

# 简单解析参数
for ($i = 0; $i -lt $args.Length; $i++) {
    switch ($args[$i]) {
        "--ide" {
            if ($i + 1 -lt $args.Length) {
                $ide = $args[$i + 1]
                $i++
            }
        }
        "--clean" {
            $clean = $true
        }
    }
}

if ($clean) {
    if (Test-Path -Path "./build") {
        Write-Host "Cleaning ./build ..."
        Remove-Item -Path "./build" -Recurse -Force
    } else {
        Write-Host "./build 不存在，跳过清理。"
    }
}

# 执行cmake命令
$cmake_command = "cmake -B build -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
echo $cmake_command
Invoke-Expression $cmake_command

if ($ide -eq "Visual Studio") {
    # 使用 Start-Process 打开解决方案
    $sln = Join-Path -Path (Get-Location) -ChildPath "build\NEW-LeetCode.sln"
    if (Test-Path $sln) {
        Start-Process $sln
    } else {
        Write-Host "找不到解决方案: $sln"
    }
} elseif ($ide -eq "Rider") {
    Start-Process "rider64.exe" -ArgumentList "."
} elseif ($ide -eq "None") {
    exit
} else {
    echo "Invalid IDE"
    exit 1
}
