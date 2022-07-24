#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<string> res;
    for (char ch : words[0])
    {
        bool success = true;
        vector<int> temp(words.size());
        for (short i = 1; i < words.size(); i++)
        {
            int index = words[i].find(ch);
            temp[i] = index;
            if (index == -1) { success = false; break; }
        }
        if (success)
        {
            char c[]  = {ch, '\0'};
            res.push_back(c);
            for (short i = 1; i < words.size(); i++)
            {
                words[i] = words[i].erase(temp[i], 1);
            }
        }
    }
    return res;
}

int begin_commonChars()
{
    vector<string> words = {"bella","label","roller"};
    vector<string> str = commonChars(words);
    std::cout << "Hello World!\n";
    return 0;
}


bool existInArray(char ch, string s)
{
    unordered_set<char> st(s.begin(),s.end());
	return st.find(ch) != st.end();
}