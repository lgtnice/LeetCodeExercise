#include <string>
#include <vector>

using namespace std;



//暴力解法，时间复杂度高，O(M * N)
int strStr(string haystack, string needle) {
	int len = haystack.size();
	int lenP = needle.size();

	//为了数组不越界，i < len - lenP + 1
	for (int i = 0; i < len - lenP + 1; i++)
	{
		for (int j = 0; j < lenP; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
			if (j == lenP -1)
			{
				return i;
			}
		}
	}
	return -1;
}



//KMP算法
int strStr2(string haystack, string needle)
{
	void getNext(string needle, vector<int>& next);
	vector<int> next(needle.size());
	getNext(needle, next);

	int j = 0;
	int i = 0;
	for (; i < haystack.size(); )
	{
		if (haystack[i] == needle[j])
		{
			if (j == needle.size() - 1)
			{
				return i - needle.size() + 1;
			}
			else
			{
				j++; 
				i++;
			}
		}
		else
		{
			if (j > 0)
			{
				//只做回退操作，不改变 i 和 j，回退的循环有两种退出的情况
				while (j > 0 && haystack[i] != needle[j])
				{
					j = next[j - 1];
				}
			}
			else
			{
				//不匹配 且 j指向模式串的第一个字符时，直接跳过，i指向下一位，j不做处理
				i++;
			}
		}
	}
	return -1;
}

//如果使用暴力求next，就需要O(N的3次方)，这就失去了意义
void getNext(string needle, vector<int>& next)
{
	if (next.size() == 0)
	{

	}
	else if (next.size() == 1)
	{
		next[0] = 0;
	}
	else
	{
		next[0] = 0;
		int j = 0;
		int i = 1;
		for (; i < next.size(); i++)
		{
			if (needle[i] == needle[j])
			{
				j++;
			}
			else
			{
				//如何回退
				while (j > 0 && needle[i] != needle[j])
				{
					j = next[j - 1];
				}
				if (needle[i] == needle[j])
				{
					j++;
				}
			}
			next[i] = j;
		}
	}
}