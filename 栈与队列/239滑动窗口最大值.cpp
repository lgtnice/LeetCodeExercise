#include <vector>
#include <deque>

using namespace std;

//单调队列，完美解决问题
//单调队列中的所有元素 一定 是递增或者递减排列的
//单调队列不必存放所有 元素（例如此题求 k 个数中的最大数，那么单调队列不必存 k 个数），只需要保证队列的头 最大，且单调。

class MyQueue {
public:
    /// <summary>
    /// deque拥有 比queue更多更灵活的方法，双向都可以push和pop
    /// </summary>
    deque<int> que;

    void pop(int value) {
        //只需要对比 que的最前面即可。因为如果  要pop的元素在  单调队列的维护下， 由于此元素在最左边，而单调队列从左到右 递减，
        //此元素只可能在队列的最左边
        if (que.front() == value)
        {
            que.pop_front();
        }
    }
    void push(int value) {
        if (que.empty())
        {
            que.push_back(value);
        }
        else
        {
            if (value > que.back())
            {
                while (!que.empty() && value > que.back())
                {
                    que.pop_back();
                }
            }
            que.push_back(value);

        }

    }
    int front() {
        return que.front();
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int begin = 0;
        int end = k - 1;
        vector<int> res;
        MyQueue que1;
        MyQueue* myque = &que1;
        for (int i = begin; i <= end; i++)
        {
            myque->push(nums[i]);
        }
        for (; end < nums.size() - 1; )
        {
            res.push_back(myque->front());
            myque->push(nums[++end]);
            myque->pop(nums[begin++]);
        }
        res.push_back(myque->front());

        return res;
    }
};


