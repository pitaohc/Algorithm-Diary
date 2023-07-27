#include"stdc++.h"
#include "List.h"
using namespace std;

std::ostream& operator<<(std::ostream& out, ListNode* head)
{
    if (head == NULL)
    {
        out << "[]";
    }
    out << "[";
    ListNode* ptr = head;
    while (ptr != NULL)
    {
        out << ptr->val << "->";
        ptr = ptr->next;
    }
    out << "\b\b] ";
    return out;
}

ListNode* NodeFactory(const std::vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) return nullptr;
    //从后向前建立链表
    ListNode* head = nullptr;
    while (n > 0)
    {
        n--;
        head = new ListNode(nums[n], head);
    }
    return head;
}
