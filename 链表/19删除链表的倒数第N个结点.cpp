// 19删除链表的倒数第N个结点.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :
        val(0), next(nullptr)
    {
    }
    ListNode(int x) :
        val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) :
        val(x), next(next)
    {
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyNode = new ListNode(0, head);
    ListNode* cur = dummyNode;
    ListNode* toDeleted = dummyNode;

    while (cur->next != nullptr)
    {
        cur = cur->next;
        if (n-- <= 0)
        {
            toDeleted = toDeleted->next;
        }
    }

    ListNode* temp = toDeleted->next;

    toDeleted->next = toDeleted->next->next;
    delete temp;
    temp = dummyNode->next;
    delete dummyNode;
    dummyNode = nullptr;
    return temp;
}

int begin()
{
    std::cout << "Hello World!\n";
    return 0;
}


