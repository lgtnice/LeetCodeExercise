#include <vector>
#include <algorithm>

using namespace std;



vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res{};
	sort(nums.begin(), nums.end());
	int lastIndex = nums.size() - 1;
	int initIndex = 0;

	//begin的遍历，到集合的最后一个肯定没有意义，还会导致退出不了for循环
	for (int begin = initIndex; begin < lastIndex;)
	{
		//end的遍历，和begin的同理
		for (int end = lastIndex; end > begin;)
		{
			if ((end - begin) < 3) { break; }



			int i = begin + 1;
			int j = end - 1;
			while (i < j)
			{
				//int装不下，为了不溢出
				long sum = nums[i];
				sum += nums[j];
				sum += nums[begin];
				sum += nums[end];
				if (sum < target)
				{
					int temp = nums[i];
					while (nums[i] == temp && i < lastIndex)
					{
						i++;
					}
				}
				else if (sum > target)
				{
					int temp = nums[j];
					while (nums[j] == temp && j > initIndex)
					{
						j--;
					}
				}
				else
				{
					res.push_back(vector<int>{nums[begin], nums[i], nums[j], nums[end]});
					int temp1 = nums[i];
					while (nums[i] == temp1 && i < lastIndex)
					{
						i++;
					}
					int temp2 = nums[j];
					while (nums[j] == temp2 && j > initIndex)
					{
						j--;
					}
				}
			}




			int tempEnd = nums[end];
			while (nums[end] == tempEnd && end > initIndex)
			{
				end--;
			}
		}
		int tempBegin = nums[begin];
		while (nums[begin] == tempBegin && begin < lastIndex)
		{
			begin++;
		}
	}
	return res;

}