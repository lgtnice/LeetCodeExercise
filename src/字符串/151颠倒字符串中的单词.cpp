#include <string>


using namespace std;


//�ռ临�Ӷ�Ҫ��O(1)���������������塣��ôѭ���ڲ��ܿ����ڴ�ռ�

string reverseWords(string s) {
	
	//˫ָ�룬���Ƴ��ո����ַ���
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
	
	//�������ַ�����ת
	for (int i = 0; i < s.size() / 2; i++)
	{
		swap(s[i], s[s.size() - 1 - i]);
	}
	//��תÿ������
	//��ϧ���ﻹ��Ҫ����forѭ����ʱ�临�ӶȻ���O(n��2�η�)
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

//���� �������ʼ����Ŀո񣬲��Ƽ�ʹ��string.erase()����Ϊ���api�������O(n)�ģ�forѭ��һ�ף�����O(n��2�η�)��
//ʹ��˫ָ�� ʹ�ôη��� ��1