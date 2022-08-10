#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	int m[26]{};
	for (char c : magazine)
	{
		m[c - 'a']++;
	}
	for (char c : ransomNote)
	{
		int temp = --m[c - 'a'];
		if (temp < 0)
		{
			return false;
		}
	}
	return true;
}