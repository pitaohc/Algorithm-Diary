# 读取第一个参数为vcpkg

# 检查是否存在build目录，如果不存在则删除build目录
if (Test-Path -Path "./build") {
	Remove-Item -Path "./build" -Recurse -Force
}

# 创建构建目录
New-Item -Path "./build" -ItemType "directory"


# 进入build目录
cd ./build

# 执行cmake命令
$cmake_command = "cmake .. -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
echo "cmake .. -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
Invoke-Expression $cmake_command

cd ..