//
// Created by devcpp on 23-7-25.
//
#include "List.h"
#include "util.h"
#include <iostream>

using namespace std;

int main() {
    ListNode *head = new ListNode(1);
    delete head;

    vector<vector<char>> board = {{'a', 'b', 'c', 'e'},
                                  {'s', 'f', 'c', 's'},
                                  {'a', 'd', 'e', 'e'}};
    cout << board << endl;
    return 0;
}