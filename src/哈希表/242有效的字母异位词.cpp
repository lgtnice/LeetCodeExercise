// 242有效的字母异位词.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
	if (s.length() != t.length())
	{
		return false;
	}
	int temp[26] = {0};
	for (char c:s)
	{
		temp[c - 'a']++;
	}
	for (char c: t)
	{
		if (--temp[c - 'a'] < 0)
		{
			return false;
		}
	}
	return true;
}

int begin_isAnagram()
{
    std::cout << "Hello World!\n";
	return 0;
}

