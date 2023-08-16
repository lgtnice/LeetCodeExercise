// 707设计链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


struct DoubleLinkedListNode {
    int val;
    DoubleLinkedListNode* next;
    DoubleLinkedListNode* prev;
    DoubleLinkedListNode() :
        val(0), next(nullptr), prev(nullptr)
    {
    }
    DoubleLinkedListNode(int x) :
        val(x), next(nullptr), prev(nullptr)
    {
    }
    DoubleLinkedListNode(int x, DoubleLinkedListNode* prev, DoubleLinkedListNode* next) :
        val(x), next(next), prev(prev)
    {
    }
};



class MyLinkedList {
private:
    DoubleLinkedListNode* startNode;
    DoubleLinkedListNode* endNode;
public:
    MyLinkedList() {
        startNode = nullptr;
        endNode = nullptr;
    }

    //获取第index个节点的值，如果索引无效，返回-1
    int get(int index) {
        int res = -1;
        DoubleLinkedListNode* temp = getRefByIndex(index);
        if (temp != nullptr)
        {
            res = temp->val;
        }
        return res;
    }

    void addAtHead(int val) {
        DoubleLinkedListNode* temp = new DoubleLinkedListNode(val);
        if (startNode == nullptr)
        {
            startNode = temp;
            endNode = temp;
        }
        else
        {
            temp->next = startNode;
            startNode->prev = temp;
            startNode = temp;
        }
    }

    void addAtTail(int val) {
        DoubleLinkedListNode* temp = new DoubleLinkedListNode(val);
        if (startNode == nullptr)
        {
            startNode = temp;
            endNode = temp;
        }
        else
        {
            temp->prev = endNode;
            endNode->next = temp;
            endNode = temp;
        }
    }

    void addAtIndex(int index, int val) {
        int len = getLength();
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == len)
        {
            addAtTail(val);
            return;
        }
        else if (index > 0 && index < len)
        {
            DoubleLinkedListNode* temp = new DoubleLinkedListNode(val);
            DoubleLinkedListNode* cur = getRefByIndex(index);
            DoubleLinkedListNode* preCur = cur->prev;

            preCur->next = temp;
            temp->prev = preCur;

            temp->next = cur;
            cur->prev = temp;
        }
    }

    void deleteAtIndex(int index) {
        int len = getLength();
        if (len <= 0) { return; }

        if (len == 1 && index == 0)
        {
            delete startNode;
            startNode = nullptr;
            endNode = nullptr;
            return;
        }

        if (index == 0)
        {
            startNode = startNode->next;
            delete startNode->prev;
            startNode->prev = nullptr;
        }
        else if (index == len - 1)
        {
            endNode = endNode->prev;
            delete endNode->next;
            endNode->next = nullptr;
        }
        else if (index > 0 && index < len - 1)
        {
            DoubleLinkedListNode* temp = getRefByIndex(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            temp = nullptr;
        }
    }

    int getLength()
    {
        int res = 0;
        DoubleLinkedListNode* temp = startNode;
        while (temp != nullptr)
        {
            temp = temp->next;
            res++;
        }
        return res;
    }

    DoubleLinkedListNode* getRefByIndex(int index)
    {
        DoubleLinkedListNode* res = nullptr;
        int len = getLength();
        if (index == 0)
        {
            res = startNode;
        }
        else if (index == len - 1)
        {
            res = endNode;
        }
        else if (index > 0 && index < len - 1)
        {
            DoubleLinkedListNode* cur = startNode;
            while (index > 0)
            {
                cur = cur->next;
                index--;
            }
            res = cur;
        }
        return res;
    }

    void printLinkedList()
    {
        DoubleLinkedListNode* temp = startNode;
        while (temp != nullptr)
        {
            std::cout << temp->val << ",";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */




int begin()
{
    std::cout << "Hello World!\n";
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(2);

    linkedList->printLinkedList();

    linkedList->deleteAtIndex(1);

    linkedList->printLinkedList();

    linkedList->addAtHead(2);
    linkedList->addAtHead(7);
    linkedList->addAtHead(3);
    linkedList->addAtHead(2);
    linkedList->addAtHead(5);
    linkedList->addAtTail(5);

    linkedList->printLinkedList();

    linkedList->get(5);
    linkedList->deleteAtIndex(6);

    linkedList->printLinkedList();

    linkedList->deleteAtIndex(4);

    linkedList->printLinkedList();

    return 0;
}
