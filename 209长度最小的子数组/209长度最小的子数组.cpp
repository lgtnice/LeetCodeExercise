// 209长度最小的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen2(int target, vector<int>& nums);

int main()
{
    std::cout << "Hello World!\n";
	vector<int> v = {1,1,1,1,1,1,1,1,1,1};
	cout << minSubArrayLen2(11, v);
}

///暴力解法
///
int minSubArrayLen(int target, vector<int>& nums) {
	int x = nums.size();
	int result = 0;
	int temp = 0;
	for (int i = 0; i < x; i++)
	{
		temp = 0;
		for (int j = i; j < x; j++)
		{
			temp += nums[j];
			if (temp >= target)
			{
				if (result == 0)
				{
					result = j - i + 1;
				}
				else if (j - i + 1 < result)
				{
					result = j - i + 1;
				}
				break;
			}
		}
	}
	return result;
}
///滑动窗口
int minSubArrayLen2(int target, vector<int>& nums) {
	int x = 0;
	int y = 0;
	int temp = nums[0];

	int result = 0;
	while (y < (nums.size() - 1) || temp >= target)
	{
		if (temp >= target)
		{
			if (y - x + 1 < result || result == 0)
			{
				result = y - x + 1;
			}
			if (result == 1)
			{
				return result;
			}
			else
			{
				temp -= nums[x];
				x++;
			}
		}
		else
		{
			y++;
			temp += nums[y];
		}
	}
	return result;
}