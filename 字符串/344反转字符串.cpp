#include <vector>

using namespace std;







void reverseString(vector<char>& s) {
	char t = 0;
	//技巧：检查2种情况，s.size()为9 以及 为10时，分别对应应该调换4次和5次。最后，观察 int i = 0; i < (s.size() / 2); 能不能符合即可。
	for (int i = 0; i < (s.size() / 2); i++)
	{
		t = s[i];
		s[i] = s[s.size() - i - 1];
		s[s.size() - i - 1] = t;
	}
}