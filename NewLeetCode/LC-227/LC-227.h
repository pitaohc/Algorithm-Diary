#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>
#include<map>
using namespace std;
class Solution {
    enum Operation {
        NONE,
        ADD,
        SUB,
        MUL,
        DIV
    };
    bool isNumber(char ch) {
        return '0' <= ch && ch <= '9';
    }
    int64_t readNum(string& s,string::iterator& it) {
        int64_t number = 0;
        while (it!=s.end() && isNumber(*it)) {
            number = number * 10 + *it - '0';
            ++it;
        }
        --it;
        return number;
    }
public:
    int calculate(string s) {
        //字符串包含数字和操作符
        //自动机
        //目前数字都是非负整数，不需要考虑负号开头或者中间出现小数点

        //需要一个栈结构处理待计算的数据
        //分为符号栈和操作数栈
        //当遇到优先级更低的操作时，需要将栈内的元素逐渐弹出，直到栈为空或者栈顶优先级比当前栈外优先级更低
        auto it = s.begin();
        stack<int64_t> stackNum;
        stack<Operation> stackOp;
        unordered_map < Operation, function<int64_t(int64_t, int64_t)>> tableOp;
        tableOp[ADD] = [](int64_t left, int64_t right)->int64_t {
            return left + right;
        };
        tableOp[SUB] = [](int64_t left, int64_t right)->int64_t {
            return left - right;
        };
        tableOp[MUL] = [](int64_t left, int64_t right)->int64_t {
            return left * right;
        };
        tableOp[DIV] = [](int64_t left, int64_t right)->int64_t {
            return left / right;
        };


        stackNum.push(0);
        stackOp.push(ADD);
        while (it != s.end()) {
            if (isNumber(*it)) { // 如果读取到数字
                int64_t curNum = readNum(s, it);
                stackNum.push(curNum);
            }
            else if (*it == ' ') {

            }
            else  // 读取到符号
            {
                Operation op = NONE;
                switch (*it) {
                case '+':
                    op = ADD;
                    break;
                case '-':
                    op = SUB;
                    break;
                case '*':
                    op = MUL;
                    break;
                case '/':
                    op = DIV;
                    break;
                }
                if (op == NONE) {
                    throw "Op is illegal";
                }
                int64_t left, right,result;
                if (op == ADD || op == SUB) {
                    while (!stackOp.empty())
                    {
                        right = stackNum.top();
                        stackNum.pop();
                        left = stackNum.top();
                        stackNum.pop();
                        result = tableOp[stackOp.top()](left, right);
                        stackOp.pop();
                        stackNum.push(result);
                    }
                }
                else
                {
                    while (!stackOp.empty() && stackOp.top()!=ADD && stackOp.top()!=SUB)
                    {
                        right = stackNum.top();
                        stackNum.pop();
                        left = stackNum.top();
                        stackNum.pop();
                        result = tableOp[stackOp.top()](left, right);
                        stackOp.pop();
                        stackNum.push(result);
                    }

                }

                stackOp.push(op);
                
            }
            ++it;
#ifdef _DEBUG
            fmt::print("num stack:{}\n"
                , stackNum );
#endif // _DEBUG

        }
        while (!stackOp.empty()) {
            int left, right, result;
            right = stackNum.top();
            stackNum.pop();
            left = stackNum.top();
            stackNum.pop();
            result = tableOp[stackOp.top()](left, right);
            stackOp.pop();
            stackNum.push(result);

        }
        return stackNum.top();
    }
};
