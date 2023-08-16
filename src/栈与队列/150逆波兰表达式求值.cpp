#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                //弹出来，num2在前，num1在后
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int num;
                if (s == "+") { num = num1 + num2; }
                else if (s == "-") { num = num1 - num2; }
                else if (s == "*") { num = num1 * num2; }
                else if (s == "/") { num = num1 / num2; }

                st.push(num);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};