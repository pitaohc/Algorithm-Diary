# 显示帮助信息
function Show-Help {
	@"
用法: .\build.ps1 [-h | --help] [--ide <IDE>]

选项:
  -h, --help    显示此帮助信息并退出
  --ide <IDE>   指定生成后要打开的 IDE，可选值：
                - Visual Studio  生成后打开 Visual Studio 解决方案
                - Rider         生成后打开 JetBrains Rider
                - None          仅执行 CMake 配置，不打开 IDE（默认）

示例:
  .\build.ps1                    # 仅配置 CMake
  .\build.ps1 --ide "Visual Studio"   # 配置后打开 VS
  .\build.ps1 --ide Rider        # 配置后打开 Rider
"@
}

# 处理 -h / --help
if ($args[0] -eq "-h" -or $args[0] -eq "--help") {
	Show-Help
	exit 0
}

# 读取第一个参数为ide
$ide = "None" # Visual Studio, Rider, None
# 参数 --ide [Visual Studio, Rider]
if ($args[0] -eq "--ide") {
	$ide = $args[1]
	echo "IDE: $ide"
}
# 检查是否存在build目录，如果不存在则删除build目录
if (Test-Path -Path "./build") {
	Remove-Item -Path "./build" -Recurse -Force
}

# 执行cmake命令
$cmake_command = "cmake -B build -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
echo $cmake_command
Invoke-Expression $cmake_command
if ($ide -eq "Visual Studio") {
	build/NEW-LeetCode.sln
} elseif ($ide -eq "Rider") {
	rider64.exe ./
} elseif ($ide -eq "None") {
	exit
}
else {
	echo "Invalid IDE"
	exit
}