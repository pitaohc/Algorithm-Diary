# ��ȡ��һ������Ϊvcpkg

# ����Ƿ����buildĿ¼�������������ɾ��buildĿ¼
if (Test-Path -Path "./build") {
	Remove-Item -Path "./build" -Recurse -Force
}

# ִ��cmake����
$cmake_command = "cmake -B build -DCMAKE_TOOLCHAIN_FILE=${env:vcpkg}\scripts\buildsystems\vcpkg.cmake"
echo $cmake_command
Invoke-Expression $cmake_command
