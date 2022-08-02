#include <map>
#include <vector>
#include <iostream>

using namespace std;


int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	multimap<int, int> m1;
	multimap<int, int> m2;
	multimap<int, int> m3;
	multimap<int, int> m4;
	int aim = 0;
	bool zeroBreak = false;
	int count = nums1.size();

	for (int n = 0; n < count; n++)
	{
		m1.insert(pair<int, int>(nums1[n], n));
	}
	for (int n = 0; n < count; n++)
	{
		m2.insert(pair<int, int>(nums2[n], n));
	}
	for (int n = 0; n < count; n++)
	{
		m3.insert(pair<int, int>(nums3[n], n));
	}
	for (int n = 0; n < count; n++)
	{
		m4.insert(pair<int, int>(nums4[n], n));
	}

	for (multimap<int, int>::iterator iter1 = m1.begin(); iter1 != m1.end(); iter1++)
	{
		for (multimap<int, int>::iterator iter2 = m2.begin(); iter2 != m2.end(); iter2++)
		{
			for (multimap<int, int>::iterator iter3 = m3.begin(); iter3 != m3.end(); iter3++)
			{
				for (multimap<int, int>::iterator iter4 = m4.begin(); iter4 != m4.end(); iter4++)
				{
					int sum = iter1->first + iter2->first + iter3->first + iter4->first;
					if (sum == 0)
					{
						aim++;
						cout << iter1->second << "," << iter2->second << "," << iter3->second << "," << iter4->second << endl;
					}
					else if(sum > 0)
					{
						zeroBreak = iter4 == m4.begin();
						break;
					}
				}
				if (zeroBreak)
				{
					zeroBreak = iter3 == m3.begin();
					break;
				}
			}
			if (zeroBreak)
			{
				zeroBreak = iter2 == m2.begin();
				break;
			}
		}
		if (zeroBreak)
		{
			zeroBreak = iter1 == m1.begin();
			break;
		}
	}


	return aim;
}