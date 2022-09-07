#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        stack<char> st;
        for (char ch : s)
        {
            if (!st.empty() && st.top() == ch)
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        //用这种方式倒转字符串会超时
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        //用reverse这个api函数就不会超时
        /*while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());*/

        return res;
    }

    //另一种方法，string有 类似栈的所有函数
    string removeDuplicates2(string S) 
    {
        string result;
        for (char s : S) 
        {
            if (result.empty() || result.back() != s) 
            {
                result.push_back(s);
            }
            else 
            {
                result.pop_back();
            }
        }
        return result;
    }

};