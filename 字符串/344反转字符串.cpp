#include <vector>

using namespace std;







void reverseString(vector<char>& s) {
	char t = 0;
	//���ɣ����2�������s.size()Ϊ9 �Լ� Ϊ10ʱ���ֱ��ӦӦ�õ���4�κ�5�Ρ���󣬹۲� int i = 0; i < (s.size() / 2); �ܲ��ܷ��ϼ��ɡ�
	for (int i = 0; i < (s.size() / 2); i++)
	{
		t = s[i];
		s[i] = s[s.size() - i - 1];
		s[s.size() - i - 1] = t;
	}
}