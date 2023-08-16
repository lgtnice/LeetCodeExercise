#include <string>


using namespace std;

void reverseRange(string& s, int begin, int end)
{
	//记得  赋初值和判断条件  同时加begin
	for (int i = begin; i < (end + 1 - begin) / 2 + begin; i++)
	{
		swap(s[i], s[end - i + begin]);
	}
}

//空间复杂度肯定要求 O(1)才行啊，不然题目无意义
string reverseLeftWords(string s, int n) {
	//利用类似的巧妙解法，局部反转+整体反转
	reverseRange(s, 0, n - 1);
	reverseRange(s, n, s.size() - 1);
	reverseRange(s, 0, s.size() - 1);
	return s;
}