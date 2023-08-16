//��������ջʵ��һ������

#include <stack>

using namespace std;




//carl�Ĵ��룬�ŵ㣺ʱ�临�Ӷ���
class MyQueue {
    stack<int> stIn;
    stack<int> stOut;
public:
    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        int res = 0;
        if (stOut.empty())
        {
            if (stIn.empty())
            {
                //�����쳣
                res = stIn.top();
            }
            else
            {
                while (!stIn.empty())
                {
                    stOut.push(stIn.top());
                    stIn.pop();
                }

                res = stOut.top();
                stOut.pop();
            }
        }
        else
        {
            res = stOut.top();
            stOut.pop();
        }
        return res;
    }

    
    int peek() {
        //�����ܸ��õģ���һ��Ҫ����
        int res = pop();
        //���ﲻ��push��stIn����ΪstIn�Ƕ���ͷ����stOut�Ƕ���β��Ӧ��push������β
        stOut.push(res);
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};









//���Լ���Ľⷨ
class MyQueue2 {
    stack<int> st1;
    stack<int> st2;

    //��һ������ֵ��ʶĿǰ�ĳ��ڴ���  ����ͷ  ����  ����β��
    //true������������У�st1��false�������ó����У�st2
    bool flag = true;
public:
    MyQueue2() {

    }

    void push(int x) {
        if (!flag)
        {
            if (!st2.empty() && st1.empty())
            {
                while (!st2.empty())
                {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            flag = true;
        }
        st1.push(x);
    }

    int pop() {
        int res = 0;
        if (flag)
        {
            if (!st1.empty() && st2.empty())
            {
                while (!st1.empty())
                {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            flag = false;
        }
        res = st2.top();
        st2.pop();
        return res;
    }

    int peek() {
        int res = pop();
        //��ʱ�����е�Ԫ��һ������st2������ֱ�ӷŻ� st2
        st2.push(res);
        return res;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};