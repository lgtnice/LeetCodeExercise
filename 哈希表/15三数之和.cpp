#include <vector>
#include <set>
#include <algorithm>

using namespace std;




vector<vector<int>> threeSum(vector<int>& nums) {
	multiset<int> mm(nums.begin(), nums.end());
	vector<int> vv(mm.begin(), mm.end());
	int count = nums.size();
	vector<vector<int>> res{};
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			for (int k = j + 1; k < count; k++)
			{
				if ((vv[i] + vv[j] + vv[k]) == 0)
				{
					bool isExist = false;
					for (vector<int> temp : res)
					{
						isExist = ((vv[i] == temp[0]) && (vv[j] == temp[1]) && (vv[k] == temp[2]));
						if (isExist) { break; }
					}
					if (!isExist)
					{
						res.push_back(vector<int>{vv[i], vv[j], vv[k]});
					}
				}
			}
		}
	}
	return res;
}

//������Ǹ���ʱ�ˡ������ǲ���ʱ����ָ�뷨

vector<vector<int>> threeSum2(vector<int>& nums)
{
	vector<vector<int>> res{};
	sort(nums.begin(), nums.end());
	int lastIndex = nums.size() - 1;
	int initIndex = 0;

	for (int tail = lastIndex; tail >= 2;)
	{
		int i = 0;
		int j = tail - 1;
		while (i < j)
		{
			int sum = nums[i] + nums[j] + nums[tail];
			if (sum < 0)
			{
				//Ϊ�˲���res����Ѱ�������ظ���Ԫ�飬��������ķ����ƶ�ָ��
				//��res��Ѱ�һᵼ�±���������ʱ�临�Ӷȣ�n��2�η� ��� n��3�η���
				int temp = nums[i];
				while (nums[i] == temp && i < lastIndex)
				{
					i++;
				}
			}
			else if (sum > 0)
			{
				int temp = nums[j];
				while (nums[j] == temp && j > initIndex)
				{
					j--;
				}
			}
			else
			{
				res.push_back(vector<int>{nums[i], nums[j], nums[tail]});
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
		int temp3 = nums[tail];
		while (temp3 == nums[tail] && tail > initIndex)
		{
			tail--;
		}
	}
	return res;

}