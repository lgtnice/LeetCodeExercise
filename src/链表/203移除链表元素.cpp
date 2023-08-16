// 203移除链表元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int begin()
{
    std::cout << "Hello World!\n";
	return 0;
}


ListNode* removeElements(ListNode* head, int val) {
	ListNode* res = nullptr;
	//寻找到第一个不是val的节点，这个节点的地址是返回值
	while (head != nullptr && head->val == val)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	res = head;
	if (head == nullptr) { return res; }
	//处理好链表，删除指定的节点
	while (head->next != nullptr)
	{
		if (head->next->val == val)
		{
			ListNode* temp = head->next;
			head->next = head->next->next;
			delete temp;
			temp = nullptr;
		}
		else
		{
			head = head->next;
		}
	}
	return res;
}

///设置虚拟头结点的方式
ListNode* removeElements2(ListNode* head, int val) {
	//设置为-1，因为 0 <= val <= 50 
	ListNode* dummyHead = new ListNode(-1, head);

	ListNode* cur = dummyHead;
	while (cur->next != nullptr)
	{
		if (cur->next->val == val)
		{
			ListNode* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
			temp = nullptr;
		}
		else
		{
			cur = cur->next;
		}
	}
	head = dummyHead->next;
	delete dummyHead;
	dummyHead = nullptr;
	return head;
}