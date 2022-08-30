#include <string>
#include <vector>

using namespace std;



//�����ⷨ��ʱ�临�Ӷȸߣ�O(M * N)
int strStr(string haystack, string needle) {
	int len = haystack.size();
	int lenP = needle.size();

	//Ϊ�����鲻Խ�磬i < len - lenP + 1
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



//KMP�㷨
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
				//ֻ�����˲��������ı� i �� j�����˵�ѭ���������˳������
				while (j > 0 && haystack[i] != needle[j])
				{
					j = next[j - 1];
				}
			}
			else
			{
				//��ƥ�� �� jָ��ģʽ���ĵ�һ���ַ�ʱ��ֱ��������iָ����һλ��j��������
				i++;
			}
		}
	}
	return -1;
}

//���ʹ�ñ�����next������ҪO(N��3�η�)�����ʧȥ������
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
				//��λ���
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