//利用两个栈实现一个队列

#include <stack>

using namespace std;




//carl的代码，优点：时间复杂度少
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
                //触发异常
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
        //代码能复用的，就一定要复用
        int res = pop();
        //这里不是push到stIn，因为stIn是队列头，而stOut是队列尾，应该push到队列尾
        stOut.push(res);
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};









//我自己想的解法
class MyQueue2 {
    stack<int> st1;
    stack<int> st2;

    //用一个布尔值标识目前的出口处是  队列头  还是  队列尾。
    //true代表适用入队列，st1；false代表适用出队列，st2
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
        //此时，所有的元素一定都在st2，可以直接放回 st2
        st2.push(res);
        return res;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};