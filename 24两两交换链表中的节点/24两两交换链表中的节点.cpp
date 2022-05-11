// 24两两交换链表中的节点.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct SingleLinkedListNode {
    int val;
    SingleLinkedListNode* next;
    SingleLinkedListNode() :
        val(0), next(nullptr)
    {
    }
    SingleLinkedListNode(int x) :
        val(x), next(nullptr)
    {
    }
    SingleLinkedListNode(int x, SingleLinkedListNode* next) :
        val(x), next(next)
    {
    }
};


//通过添加假结点实现
//做此类题的捷径----先实现一版 普通情况最理想情况下的，再考虑特殊情况（例如空、一个结点、两个结点）


/// <summary>
/// 
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
SingleLinkedListNode* swapPairs(SingleLinkedListNode* head) {
    SingleLinkedListNode* dummyNode = new SingleLinkedListNode(0, head);

    SingleLinkedListNode* currentNode = dummyNode;
    SingleLinkedListNode* temp1 = dummyNode->next;
    if (temp1 == nullptr)
    {
        SingleLinkedListNode* res = dummyNode->next;
        delete dummyNode;
        dummyNode = nullptr;
        return res;
    }
    SingleLinkedListNode* temp2 = dummyNode->next->next;
    if (temp2 == nullptr)
    {
        SingleLinkedListNode* res = dummyNode->next;
        delete dummyNode;
        dummyNode = nullptr;
        return res;
    }
    SingleLinkedListNode* nextNode = dummyNode->next->next->next;

    while (nextNode != nullptr && nextNode->next != nullptr)
    {
        currentNode->next = temp2;
        temp2->next = temp1;
        temp1->next = nextNode;

        currentNode = temp1;
        temp2 = temp1->next->next;
        nextNode = temp1->next->next->next;
        temp1 = temp1->next;
    }

    currentNode->next = temp2;
    temp2->next = temp1;
    temp1->next = nextNode;

    SingleLinkedListNode* res = dummyNode->next;
    delete dummyNode;
    dummyNode = nullptr;
    return res;
}

int main()
{
    std::cout << "Hello World!\n";
}

