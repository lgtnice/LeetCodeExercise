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

	//˫ָ��
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
			//������������Ŀո��ַ�������previous���ԣ�������ͨ�� һ����Ҫ�� 1
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