# PowerShell 7 only
# 设置template变量为"./template"
$template = "./template"
# 输出template变量
echo $template

# 读取第一个参数，赋值给name变量，如果没有参数则输出提示信息并结束
$newDirectory = $args[0]
if ($newDirectory -eq $null) {
	echo "Please input name"
	exit
}
echo $newDirectory

# 如果目录已经存在则输出提示信息并结束
if (Test-Path $newDirectory) {
	echo "Directory already exists"
	exit
}

# 将template目录复制到newDirectory目录
Copy-Item -Path $template -Destination $newDirectory -Recurse

# 将newDirectory目录下的LC-000.cpp改名为$newDirectory.cpp
Rename-Item -Path "$newDirectory/LC-000.cpp" -NewName "$newDirectory.cpp"
# 将newDirectory目录下的LC-000.h改名为$newDirectory.h
Rename-Item -Path "$newDirectory/LC-000.h" -NewName "$newDirectory.h"

# 读取newDirectory目录下的$newDirectory.cpp文件，找到行为"#include "LC-000.h""
# 的行，将其替换为"#include "$newDirectory.h""
$newLine = "$newDirectory.h"
$replacedLine = "LC-000.h"
(Get-Content "$newDirectory/$newDirectory.cpp" -Encoding utf8NoBOM) | Foreach-Object {
	$_ -replace $replacedLine, $newLine
} | Set-Content "$newDirectory/$newDirectory.cpp" -Encoding utf8NoBOM

# 以utf8NoBOM读取newDirectory目录下的CMakeLists.txt文件，找到行为"set(PROJECT_NAME LC-000)"
# 的行，将其替换为"set(PROJECT_NAME $newDirectory)"
$newLine = "$newDirectory"
$replacedLine = "LC-000"
(Get-Content "$newDirectory/CMakeLists.txt" -Encoding utf8NoBOM) | Foreach-Object {
	$_ -replace $replacedLine, $newLine
} | Set-Content "$newDirectory/CMakeLists.txt" -Encoding utf8NoBOM