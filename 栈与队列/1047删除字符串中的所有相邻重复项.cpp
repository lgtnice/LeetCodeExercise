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
        //�����ַ�ʽ��ת�ַ����ᳬʱ
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        //��reverse���api�����Ͳ��ᳬʱ
        /*while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());*/

        return res;
    }

    //��һ�ַ�����string�� ����ջ�����к���
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