// 02.07链表相交.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 //巧妙的考了单链表的结点只能指向一个其他结点的地址，
 //整个题目内都是对比的 地址值，从没有考虑过结点的val值
 ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
     int lenA = 0, lenB = 0;
     ListNode* temp = headA;
     while (temp != nullptr)
     {
         lenA++;
         temp = temp->next;
     }
     temp = headB;
     while (temp != nullptr)
     {
         lenB++;
         temp = temp->next;
     }
     bool b = lenA - lenB > 0;
     int len = b ? lenA - lenB : lenB - lenA;
     if (b)
     {
         ListNode* p = headA;
         headA = headB;
         headB = p;
     }
     while (len--)
     {
         headB = headB->next;
     }
     while (headA != nullptr && headA != headB)
     {
         headA = headA->next;
         headB = headB->next;
     }
     return headA;
 }

int begin()
{
    std::cout << "Hello World!\n";
    return 0;
}


