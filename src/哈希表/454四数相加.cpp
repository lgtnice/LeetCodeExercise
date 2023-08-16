#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void findItem(multimap<int, int>::iterator iter1, multimap<int, int>::iterator iter2, multimap<int, int>::iterator iter3, multimap<int, int>::iterator iter4);
bool existInVector(vector<string>& v, string s);

multimap<int, int> m1;
multimap<int, int> m2;
multimap<int, int> m3;
multimap<int, int> m4;

multimap<int, int>::iterator end1;
multimap<int, int>::iterator end2;
multimap<int, int>::iterator end3;
multimap<int, int>::iterator end4;

vector<string> v_aim;

int aim = 0;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
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
	end1 = (--m1.end());
	end2 = (--m2.end());
	end3 = (--m3.end());
	end4 = (--m4.end());


	findItem(m1.begin(), m2.begin(), m3.begin(), m4.begin());
	return aim;
}

void findItem(multimap<int ,int>::iterator iter1, multimap<int, int>::iterator iter2, multimap<int, int>::iterator iter3, multimap<int, int>::iterator iter4)
{
	multimap<int, int>::iterator temp1 = iter1;
	multimap<int, int>::iterator temp2 = iter2;
	multimap<int, int>::iterator temp3 = iter3;
	multimap<int, int>::iterator temp4 = iter4;
	int sum = iter1->first + iter2->first + iter3->first + iter4->first;
	if (sum <= 0)
	{
		if (sum == 0)
		{
			/// �˴��и���ѧ���⣺
			/// ����� v_aim �������� vector<string>����ô����������⣬�������ʱ����ÿ�ζ���new�ɹ������ٳ��µ��ڴ�
			/// �������� vector<int*> �Ļ����뷨�Ƕ�̬��������� �������� �����������СΪ4����̬����������ֻ��  ����������׵�ַ
			/// ��һ��ʼ���ھŸ���vector<int*> v_aim �����ݣ�int[]���ڴ�ռ俪�٣���û�����⡣
			/// ���ǣ���Ȥ����������ˣ��ھŸ�֮��int[]�ĳ�ʼ�����ٵ��ڴ��ַ�����µģ����� v_aim �����еĵ�ַ��
			/// �����Ḳ�� ֮ǰ��ֵ������push_backһ����ͬ�ĵ�ַ������ǲ����� ��̬�����ĩβ ����µ�ֵ
			string tempStr = { (char)(iter1->second + 65),(char)(iter2->second + 65), (char)(iter3->second + 65), (char)(iter4->second + 65)};
			if (!existInVector(v_aim, tempStr))
			{
				aim++;
				v_aim.push_back(tempStr);
				cout << iter1->second << "," << iter2->second << "," << iter3->second << "," << iter4->second << endl;
			}
		}
		if (iter1 != end1)
		{
			findItem(++temp1, iter2, iter3, iter4);
		}
		if (iter2 != end2)
		{
			findItem(iter1, ++temp2, iter3, iter4);
		}
		if (iter3 != end3)
		{
			findItem(iter1, iter2, ++temp3, iter4);
		}
		if (iter4 != end4)
		{
			findItem(iter1, iter2, iter3, ++temp4);
		}
	}
}

bool existInVector(vector<string>& v, string s)
{
	bool res = false;
	vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		if (!(*it).compare(s))
		{
			res = true;
			break;
		}
		it++;
	}
	return res;
}