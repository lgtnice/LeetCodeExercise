
#include <queue>

using namespace std;




class MyStack {
public:
    queue<int> que;


    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int res = 0;
        //可以获取到队列或者栈中 共有几个元素
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        res = que.front();
        que.pop();
        return res;
    }

    int top() {
        //队列可以获取到最后一个元素
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */