#include <vector>
#include <deque>

using namespace std;

//�������У������������
//���������е�����Ԫ�� һ�� �ǵ������ߵݼ����е�
//�������в��ش������ Ԫ�أ���������� k �����е����������ô�������в��ش� k ��������ֻ��Ҫ��֤���е�ͷ ����ҵ�����

class MyQueue {
public:
    /// <summary>
    /// dequeӵ�� ��queue��������ķ�����˫�򶼿���push��pop
    /// </summary>
    deque<int> que;

    void pop(int value) {
        //ֻ��Ҫ�Ա� que����ǰ�漴�ɡ���Ϊ���  Ҫpop��Ԫ����  �������е�ά���£� ���ڴ�Ԫ��������ߣ����������д����� �ݼ���
        //��Ԫ��ֻ�����ڶ��е������
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


