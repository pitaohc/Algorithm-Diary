# ��ȡ��һ������Ϊvcpkg

# ����Ƿ����buildĿ¼�������������ɾ��buildĿ¼
if (Test-Path -Path "./build") {
	Remove-Item -Path "./build" -Recurse -Force
}

# ��������Ŀ¼
New-Item -Path "./build" -ItemType "directory"


# ����buildĿ¼
cd ./build

# ִ��cmake����
$cmake_command = "cmake .. -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
echo "cmake .. -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
Invoke-Expression $cmake_command

cd ..