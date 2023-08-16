#include <string>


using namespace std;



string replaceSpace(string s) {
	int count = 0;
	for (char c : s)
	{
		if (c == ' ')
		{
			count++;
		}
	}
	s.resize(s.size() + count * 2);

	//双指针
	int previous = s.size() - count * 2 - 1;
	int behind = s.size() - 1;
	while (previous != behind)
	{
		if (s[previous] == ' ')
		{
			s[behind] = '0';
			behind--;
			s[behind] = '2';
			behind--;
			s[behind] = '%';
			behind--;
			//这里遇到特殊的空格字符，对于previous而言，当作普通的 一样需要减 1
			previous--;
		}
		else
		{
			s[behind] = s[previous];
			previous--;
			behind--;
		}
	}
	return s;
}