# PowerShell 7 only
# ����template����Ϊ"./template"
$template = "./template"
# ���template����
echo $template

# ��ȡ��һ����������ֵ��name���������û�в����������ʾ��Ϣ������
$newDirectory = $args[0]
if ($newDirectory -eq $null) {
	echo "Please input name"
	exit
}
echo $newDirectory

# ���Ŀ¼�Ѿ������������ʾ��Ϣ������
if (Test-Path $newDirectory) {
	echo "Directory already exists"
	exit
}

# ��templateĿ¼���Ƶ�newDirectoryĿ¼
Copy-Item -Path $template -Destination $newDirectory -Recurse

# ��newDirectoryĿ¼�µ�LC-000.cpp����Ϊ$newDirectory.cpp
Rename-Item -Path "$newDirectory/LC-000.cpp" -NewName "$newDirectory.cpp"
# ��newDirectoryĿ¼�µ�LC-000.h����Ϊ$newDirectory.h
Rename-Item -Path "$newDirectory/LC-000.h" -NewName "$newDirectory.h"

# ��ȡnewDirectoryĿ¼�µ�$newDirectory.cpp�ļ����ҵ���Ϊ"#include "LC-000.h""
# ���У������滻Ϊ"#include "$newDirectory.h""
$newLine = "$newDirectory.h"
$replacedLine = "LC-000.h"
(Get-Content "$newDirectory/$newDirectory.cpp" -Encoding utf8NoBOM) | Foreach-Object {
	$_ -replace $replacedLine, $newLine
} | Set-Content "$newDirectory/$newDirectory.cpp" -Encoding utf8NoBOM

# ��utf8NoBOM��ȡnewDirectoryĿ¼�µ�CMakeLists.txt�ļ����ҵ���Ϊ"set(PROJECT_NAME LC-000)"
# ���У������滻Ϊ"set(PROJECT_NAME $newDirectory)"
$newLine = "$newDirectory"
$replacedLine = "LC-000"
(Get-Content "$newDirectory/CMakeLists.txt" -Encoding utf8NoBOM) | Foreach-Object {
	$_ -replace $replacedLine, $newLine
} | Set-Content "$newDirectory/CMakeLists.txt" -Encoding utf8NoBOM