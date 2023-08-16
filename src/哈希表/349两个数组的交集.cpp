#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	//unordered_set，它可以自动去重
	unordered_set<int> res;
	unordered_set<int> set2(nums2.begin(), nums2.end());
	for (int n : nums1)
	{
		if (set2.find(n) != set2.end())
		{
			res.insert(n);
		}
	}
	return vector<int>(res.begin(), res.end());
}