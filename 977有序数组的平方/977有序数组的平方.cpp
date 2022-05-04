// 977有序数组的平方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

vector<int> sortedSquares(vector<int>& nums) {
	int start = 0;
	int end = nums.size() - 1;
	int index = end;

	vector<int> result = vector<int>(end + 1);

	while (end - start >= 0)
	{
		if (nums[start] + nums[end] > 0)
		{
			result[index] = nums[end] * nums[end];
			end--;
			index--;
		}
		else
		{
			result[index] = nums[start] * nums[start];
			start++;
			index--;
		}
	}
	return result;
}
