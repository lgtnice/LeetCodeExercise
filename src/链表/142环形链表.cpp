// 142环形链表.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    //空链表，为特殊情况，加代码
    if (head == nullptr) { return nullptr; }
    ListNode* aim = head;

    aim = aim->next;
    while (aim != nullptr)
    {
        ListNode* temp = head;
        while (temp!=aim)
        {
            //用的笨比方法确认存在环，时间复杂度 n的平方
            if (temp == aim->next)
            {
                return temp;
            }
            temp = temp->next;
        }
        //最后的一个结点的next指向它自己，这是一种特殊情况，要加代码
        if (aim == aim->next) { return aim; }
        aim = aim->next;
    }
    return nullptr;
}


int begin()
{
    std::cout << "Hello World!\n";
    return 0;
}


