#include <string>


using namespace std;




//һ��ʼ���ٵ�д��������������ֵѽ���߽�ѽ���Ȳ���׼ȷû׼ȷ������������֮�������޸ı߽�ֵ
string reverseStr(string s, int k) {
	bool flag = true;
	int round = 0;
	//����k = 5����֤ s.size() �ֱ�Ϊ5��8�������ʱ��while�Ľ�����˳� �Ƿ���ȷ���ɡ�
	while (round * k < s.size())
	{
		if (flag)
		{
			if ((round + 1) * k > s.size())
			{
				//����� j < �������һ��Ҫע��
				for (int j = round * k; j < ((s.size() - round * k) / 2 + round * k); j++)
				{
					swap(s[j], s[s.size() - 1 - j + round * k]);
				}
			}
			else
			{
				//����� j < ����ǵü��ϳ�ʼ��j��ֵ����Ϊһ��ʼ����ʱֻ�����˻�ѭ�����ٴΣ���Ҫ���������ĳ�ʼֵ
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