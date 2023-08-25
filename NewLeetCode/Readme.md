# 新LeetCode项目架构

公共调式代码放在utils目录下面
每个LC题目建立一个单独的目录，放置测试用例和题解代码

# 相关脚本

## 生成题目目录 create.ps1
务必在powershell7中调用create.ps1脚本，默认的powershell和cmd无法运行脚本

格式：create.ps1 [新题目名称]

例子：create.ps1 [LC-1]

脚本功能：
1. 自动创建题目目录
2. 拷贝template目录到指定目录
3. 自动替换.h和.cpp文件名称为当前题目名称
4. 修改CMakeLists.txt文件，将项目名称改为当前题目名称								
5. 修改.cpp文件中引用的头文件名称为当前题目名称。在上面的例子中，将'include "LC-000.h"'替换为'include "LC-1.h"'

## 构建脚本 build.ps1
请先安装cmake和vcpkg并加入环境变量，使用vcpkg安装fmt，并配置’vcpkg integrate install‘

格式：build.ps1

脚本功能：
1. 自动创建build目录
1. 如果目录已经存在则清空目录
2. 自动调用cmake构建项目
