// 206反转链表.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

class MyLinkedList {
private:
    SingleLinkedListNode* startNode;
    SingleLinkedListNode* endNode;
public:
    MyLinkedList() {
        startNode = nullptr;
        endNode = nullptr;
    }

    int get(int index) {
        int res = -1;
        SingleLinkedListNode* temp = getRefByIndex(index);
        if (temp != nullptr)
        {
            res = temp->val;
        }
        return res;
    }

    void addAtHead(int val) {
        SingleLinkedListNode* temp = new SingleLinkedListNode(val);
        if (startNode == nullptr)
        {
            startNode = temp;
            endNode = temp;
        }
        else
        {
            temp->next = startNode;
            startNode = temp;
        }
    }

    void addAtTail(int val) {
        SingleLinkedListNode* temp = new SingleLinkedListNode(val);
        if (startNode == nullptr)
        {
            startNode = temp;
            endNode = temp;
        }
        else
        {
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
            SingleLinkedListNode* temp = new SingleLinkedListNode(val);
            SingleLinkedListNode* preCur = getRefByIndex(index - 1);
            SingleLinkedListNode* cur = preCur->next;

            preCur->next = temp;
            temp->next = cur;
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
            SingleLinkedListNode* temp = startNode;
            startNode = startNode->next;
            delete temp;
            temp = nullptr;
        }
        else if (index == len - 1)
        {
            endNode = getRefByIndex(len - 2);
            delete endNode->next;
            endNode->next = nullptr;
        }
        else if (index > 0 && index < len - 1)
        {
            SingleLinkedListNode* temp = getRefByIndex(index - 1);
            SingleLinkedListNode* toBeDeleted = temp->next;
            temp->next = temp->next->next;

            delete toBeDeleted;
            toBeDeleted = nullptr;
        }
    }

    void reverseList() {
        SingleLinkedListNode* behindNode = startNode;
        if (behindNode == nullptr)
        {
            return;
        }
        SingleLinkedListNode* frontNode = behindNode->next;
        if (frontNode == nullptr)
        {
            return;
        }
        SingleLinkedListNode* tempNode = frontNode->next;

        behindNode->next = nullptr;

        while (tempNode != nullptr)
        {
            frontNode->next = behindNode;
            behindNode = frontNode;
            frontNode = tempNode;
            tempNode = tempNode->next;
        }
        frontNode->next = behindNode;
        startNode = frontNode;
    }

    int getLength()
    {
        int res = 0;
        SingleLinkedListNode* temp = startNode;
        while (temp != nullptr)
        {
            temp = temp->next;
            res++;
        }
        return res;
    }

    SingleLinkedListNode* getRefByIndex(int index)
    {
        SingleLinkedListNode* res = nullptr;
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
            SingleLinkedListNode* cur = startNode;
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
        SingleLinkedListNode* temp = startNode;
        while (temp != nullptr)
        {
            std::cout << temp->val << ",";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};

class Solution {
public:
    SingleLinkedListNode* reverseList(SingleLinkedListNode* head) {
        SingleLinkedListNode* behindNode = head;
        if (behindNode == nullptr)
        {
            return head;
        }
        SingleLinkedListNode* frontNode = behindNode->next;
        if (frontNode == nullptr)
        {
            return head;
        }
        SingleLinkedListNode* tempNode = frontNode->next;

        behindNode->next = nullptr;

        while (tempNode != nullptr)
        {
            frontNode->next = behindNode;
            behindNode = frontNode;
            frontNode = tempNode;
            tempNode = tempNode->next;
        }
        frontNode->next = behindNode;
        head = frontNode;

        return head;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
