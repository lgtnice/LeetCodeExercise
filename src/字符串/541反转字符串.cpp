#include <string>


using namespace std;




//一开始快速的写出框架来，具体的值呀，边界呀，先不管准确没准确，搞完整体框架之后慢慢修改边界值
string reverseStr(string s, int k) {
	bool flag = true;
	int round = 0;
	//假设k = 5，验证 s.size() 分别为5，8两种情况时，while的进入和退出 是否正确即可。
	while (round * k < s.size())
	{
		if (flag)
		{
			if ((round + 1) * k > s.size())
			{
				//这里的 j < 和下面的一样要注意
				for (int j = round * k; j < ((s.size() - round * k) / 2 + round * k); j++)
				{
					swap(s[j], s[s.size() - 1 - j + round * k]);
				}
			}
			else
			{
				//这里的 j < 后面记得加上初始的j的值，因为一开始考虑时只考虑了会循环多少次，不要忽略了它的初始值
				for (int j = round * k; j < (k / 2 + round * k); j++)
				{
					swap(s[j], s[(round + 1) * k - 1 - j + round * k]);
				}
			}
		}

		flag = !flag;
		round++;
	}
	return s;
}