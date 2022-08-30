
#include <string>
#include <stack>

using namespace std;



class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        stack<char> st;
        for (char ch : s)
        {
            if (!res)
            {
                break;
            }
            switch (ch)
            {
            case '(':
            {
                st.push('(');
                break;
            }
            case ')':
            {
                if (st.top() != '(')
                {
                    res = false;
                }
                else
                {
                    st.pop();
                }
                break;
            }
            case '{':
            {
                st.push('{');
                break;
            }
            case '}':
            {
                if (st.top() != '{')
                {
                    res = false;
                }
                else
                {
                    st.pop();
                }
                break;
            }
            case '[':
            {
                st.push('[');
                break;
            }
            case ']':
            {
                if (st.top() != '[')
                {
                    res = false;
                }
                else
                {
                    st.pop();
                }
                break;
            }
            default:
                break;
            }

        }
        return res && st.empty();

    }
};
