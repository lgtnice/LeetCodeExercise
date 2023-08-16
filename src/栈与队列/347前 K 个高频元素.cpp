#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;




class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        //С����
        return lhs.second > rhs.second;
    }
};


class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Ҫͳ��Ԫ�س���Ƶ��
        unordered_map<int, int> map; // map<nums[i],��Ӧ���ֵĴ���>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // ��Ƶ������
        // pair<int, int>�Ƕ�������Ԫ�ص����ͣ�vector<pair<int, int>>�ǵײ�ʵ�ֵ����ݽṹ��mycomparison�������ص��������������С�����Ǵ�
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // �ù̶���СΪk��С���ѣ�ɨ������ pair
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
                pri_que.pop();
            }
        }

        // �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
        vector<int> result;
        while (!pri_que.empty())
        {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return result;

    }
};