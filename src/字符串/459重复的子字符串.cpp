#include <string>
#include <vector>

using namespace std;



bool repeatedSubstringPattern(string s) {
	void getNext(string needle, vector<int>&next);
	vector<int> next(s.size());
	getNext(s, next);

	//�۲�KMP�㷨�е�next����Ĺ��ɼ���
	int x = s.size() - next[next.size() - 1];
	int y = s.size();
	return (y / x > 1) && (y % x == 0);
}