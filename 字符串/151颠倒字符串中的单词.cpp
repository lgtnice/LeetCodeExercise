#include <string>


using namespace std;


//空间复杂度要求O(1)，否则这题无意义。那么循环内不能开辟内存空间

string reverseWords(string s) {
	
	//双指针，求移除空格后的字符串
	bool flag = true;
	int m = 0, n = 0;
	while (n != s.size())
	{
		if (s[n] != ' ' && flag)
		{
			flag = false;
			s[m] = s[n];
			m++;
		}
		else if (!flag && s[n] != ' ')
		{
			s[m] = s[n];
			m++;
		}
		else if (!flag && s[n] == ' ')
		{
			if (s[n - 1] != ' ')
			{
				s[m] = s[n];
				m++;
			}
		}
		n++;
	}
	if (s[m - 1] == ' ')
	{
		s.resize(m - 1);
	}
	else
	{
		s.resize(m);
	}
	
	//将整个字符串翻转
	for (int i = 0; i < s.size() / 2; i++)
	{
		swap(s[i], s[s.size() - 1 - i]);
	}
	//翻转每个单词
	//可惜这里还是要两层for循环，时间复杂度还是O(n的2次方)
	int b = 0;
	for (int a = 0; a < s.size(); a++)
	{
		if (s[a] == ' ')
		{
			for (int t = b; t < (a - b) / 2 + b; t++)
			{
				swap(s[t], s[a - 1 - t + b]);
			}
			b = a + 1;
		}
		else if (a == s.size() - 1)
		{
			for (int t = b; t < (a + 1 - b) / 2 + b; t++)
			{
				swap(s[t], s[a - t + b]);
			}
		}
	}

	return s;
}

//对于 除掉单词间多余的空格，不推荐使用string.erase()，因为这个api本身就是O(n)的，for循环一套，就是O(n的2次方)了
//使用双指针 使得次方数 减1