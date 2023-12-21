#include "List.h"
#include "util.h"
#include <iostream>
#include "test-Tree.h"
#include<fmt/core.h>
#include<fmt/color.h>
#include<fmt/ranges.h>
#include"Tree.h"
#include <assert.h>
using namespace std;


void test_build_empty() {
    fmt::print(fmt::fg(fmt::color::yellow), "TEST_BUILD_EMPTY\n");
    vector<int> data = {};
    TreeNode* root = buildTree(data);
    assert(root == nullptr);
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_EMPTY PASS\n");
}
void test_build_0() {
    fmt::print(fmt::fg(fmt::color::yellow), "TEST_BUILD_0\n");
    vector<int> data = { 0 };
    TreeNode* root = buildTree(data);
    assert(root == nullptr);
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_0 PASS\n");
}
void test_build_root() {
    fmt::print(fmt::fg(fmt::color::yellow), "TEST_BUILD_ROOT\n");

    vector<int>data = { 1 };
    TreeNode* root = buildTree(data);
    assert(root != nullptr);

    assert(root->val == data[0]);

    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_ROOT PASS\n");

}
void test_build_case1() {
    fmt::print(fmt::fg(fmt::color::yellow), "TEST_BUILD_CASE1\n");

    vector<int>data = { 1,2,3 };
    TreeNode* root = buildTree(data);
    assert(root != nullptr);

    assert(root->val == data[0]);
    assert(root->left->val == data[1]);
    assert(root->right->val == data[2]);

    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_CASE1 PASS\n");

}
void test_build_case2() {
    fmt::print(fmt::fg(fmt::color::yellow), "TEST_BUILD_CASE2\n");

    vector<int>data = { 1, NULL, 2, 3 };
    TreeNode* root = buildTree(data);
    assert(root != nullptr);

    assert(root->val == data[0]);
    assert(root->right->val == data[2]);
    assert(root->right->left->val == data[3]);

    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_CASE2 PASS\n");
}
void test_build_case3() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);

    vector<int>data = { 5, 4, 7, 3, NULL, 2, NULL, -1, NULL, 9 };
    /*
          5
         / \
        4   7
       /   /
      3   2
     /   /
    -1  9
    */
    TreeNode* root = buildTree(data);
    assert(root != nullptr);

    assert(root->val == data[0]);
    assert(root->left->val == data[1]);
    assert(root->right->val == data[2]);
    assert(root->left->left->val == data[3]);
    //null
    assert(root->right->left->val == data[5]);
    //null
    assert(root->left->left->left->val == data[7]);
    //null
    assert(root->right->left->left->val == data[9]);


    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "TEST_BUILD_CASE3 PASS\n");
}

void test_to_string_root() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { 5 };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{5}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}
void test_to_string_empty() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}
void test_to_string_0() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { 0 };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}
void test_to_string_simple() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { 1,2,3 };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{1, 2, 3}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}
void test_to_string_1() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { 1,2,3,4,5 };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{1, 2, 3, 4, 5}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}
void test_to_string_2() {
    fmt::print(fmt::fg(fmt::color::yellow), "{}\n", __func__);
    vector<int>data = { 5, 4, 7, 3, null, 2, null, -1, null, 9 };
    TreeNode* root = buildTree(data);
    std::string info = to_string(root);
    fmt::print("info: {}\n", info);
    assert(info == "{5, 4, 7, 3, null, 2, null, -1, null, 9}");
    deleteTree(root);
    fmt::print(fmt::fg(fmt::color::green), "{} PASSED\n", __func__);
}

int main() {


    //构建树的测试用例
    test_build_empty();
    test_build_0();
    test_build_root();
    test_build_case1();
    test_build_case2();
    test_build_case3();
    //输出树的测试用例
    test_to_string_root();
    test_to_string_empty();
    test_to_string_0();
    test_to_string_simple();
    test_to_string_1();
    test_to_string_2();
    return 0;
}
