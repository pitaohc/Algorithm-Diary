#include "List.h"
#include "util.h"
#include <iostream>
#include "LC-70.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
#include"Tree.h"
using namespace std;

void treeTest();
int main() {
    Solution sol;
    int caseNum = 1;

    treeTest();



    return 0;
}

void treeTest() {
    std::vector<int> nodes = { 1,2,3,0,5 };
    TreeNode* root = buildTree(nodes);
    printTree(root);
    deleteTree(root);

    root = nullptr;
    printTree(root);
}
