#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"

using namespace std;
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

string to_string(DLinkedNode* head) {
    if (head == nullptr) {
        return "{}";
    }
    stringstream ss;
    DLinkedNode* node = head;
    while (node->next != nullptr)
    {
        ss << "[" << node->key << ", " << node->value << "]"
            << "<->";
        node = node->next;

    }
    ss << "[" << node->key << ", " << node->value << "]";

    return ss.str();
}
class LRUCache {
private:
    int capacity;
    int size;
    DLinkedNode* head, * tail;
    unordered_map<int, DLinkedNode*> cache; // 加速查找
public:
    LRUCache(int _capacity) :
        capacity(_capacity), size(0), cache(), head(nullptr), tail(nullptr) {
        cout << "cap: " << capacity << endl;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // 检查元素是否在cache中
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // 是，获得值并调整顺序
        DLinkedNode* node = cache[key];
        // 将节点放到头节点后
        // 从当前链表中摘除
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 放入
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
#ifdef _DEBUG
        cout << to_string(head) << endl;
#endif // _DEBUG

        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            //已经存在
            DLinkedNode* node = cache[key];
            node->value = value;
            // 将节点放到头节点后
            // 从当前链表中摘除
            node->prev->next = node->next;
            node->next->prev = node->prev;
            // 放入
            node->next = head->next;
            node->prev = head;
            node->next->prev = node;
            head->next = node;

        }
        else {

            // 插入到头节点
            ++size;
            DLinkedNode* newNode = new DLinkedNode(key, value);
            cache.insert({ key,newNode });
            newNode->prev = head;
            newNode->next = head->next;

            head->next->prev = newNode;
            head->next = newNode;

            if (size > capacity) {
                // 容量无剩余
                --size;
                // 删除队尾节点
                DLinkedNode* node = tail->prev;

                node->prev->next = tail;
                tail->prev = node->prev;
                cache.erase(node->key);
                delete node;
            }

        }
#ifdef _DEBUG
        cout << to_string(head) << endl;
#endif // _DEBUG

    }
    ~LRUCache() {
        for (auto& elem : cache) {
            delete elem.second;
        }
    }
};
