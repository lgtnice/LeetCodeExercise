// 704二分查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target);

int main()
{
	vector<int> v1 = {-1};
	search(v1, -2);
    std::cout << "Hello World!\n";
}

int search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int middle = (left + right) / 2;
	while (true)
	{
		if (left > right)
		{
			return -1;
		}
		else if(nums[middle] == target)
		{
			return middle;
		}
		else if (nums[middle] > target)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		else
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
	}
	return -1;
}

