#include <string>


using namespace std;

void reverseRange(string& s, int begin, int end)
{
	//�ǵ�  ����ֵ���ж�����  ͬʱ��begin
	for (int i = begin; i < (end + 1 - begin) / 2 + begin; i++)
	{
		swap(s[i], s[end - i + begin]);
	}
}

//�ռ临�Ӷȿ϶�Ҫ�� O(1)���а�����Ȼ��Ŀ������
string reverseLeftWords(string s, int n) {
	//�������Ƶ�����ⷨ���ֲ���ת+���巴ת
	reverseRange(s, 0, n - 1);
	reverseRange(s, n, s.size() - 1);
	reverseRange(s, 0, s.size() - 1);
	return s;
}