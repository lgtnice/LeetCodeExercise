// 27移除元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int begin()
{
    std::cout << "Hello World!\n";
	return 0;
}

int removeElement(vector<int>& nums, int val) {
	int tag = nums.size() - 1;
	int index = tag;
	int result = index + 1;

	//从后往前的双指针法
	while (index >= 0)
	{
		if (nums[index] == val)
		{
			nums[index] = nums[tag];
			tag--;
			result--;
			index--;
		}
		else
		{
			index--;
		}
	}
	return result;
}
