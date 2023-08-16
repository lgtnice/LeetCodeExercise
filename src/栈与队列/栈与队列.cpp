// 栈与队列.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "239滑动窗口最大值.cpp"
#include <vector>

int main()
{
    Solution s;
    vector<int> v{ 1,3,-1,-3,5,3,6,7 };
    vector<int> res = s.maxSlidingWindow(v, 3);

    std::cout << "Hello World!\n";
}

