#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;




class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        //小顶堆
        return lhs.second > rhs.second;
    }
};


class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // pair<int, int>是队列里面元素的类型；vector<pair<int, int>>是底层实现的数据结构；mycomparison里面重载的运算符决定了是小顶还是大顶
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有 pair
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result;
        while (!pri_que.empty())
        {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return result;

    }
};