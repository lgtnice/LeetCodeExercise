#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	for (int n = 0; n < nums.size(); n++)
	{
		auto iter = m.find(target - nums[n]);
		if (iter != m.end())
		{
			return { n, iter->second };
		}
		else
		{
			m.insert(pair<int, int>(nums[n], n));
		}
	}
	return {};
}