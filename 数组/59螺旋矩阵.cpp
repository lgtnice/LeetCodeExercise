// 59螺旋矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int begin()
{
    std::cout << "Hello World!\n";
	return 0;
}


vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n, 0)); 
	int direction = 1;
	int value = 1;
	int i = 0;
	int j = 0;
	while (true)
	{
		res[i][j] = value++;

		switch (direction)
		{
		case 1 :
		{
			//可往右
			bool flag = j + 1 < n && res[i][j + 1] == 0;
			//可往下
			bool flag2 = i + 1 < n && res[i + 1][j] == 0;
			if (flag)
			{
				j++;
			}
			else if (flag2)
			{
				i++;
				direction = 2;
			}
			else
			{
				return res;
			}
			break;
		}
		case 2:
		{
			//可往下
			bool flag = i + 1 < n && res[i + 1][j] == 0;
			//可往左
			bool flag2 = j - 1 >= 0 && res[i][j - 1] == 0;
			if (flag)
			{
				i++;
			}
			else if (flag2)
			{
				j--;
				direction = 3;
			}
			else
			{
				return res;
			}
			break;
		}
		case 3:
		{
			//可往左
			bool flag = j - 1 >= 0 && res[i][j - 1] == 0;
			//可往上
			bool flag2 = i - 1 >= 0 && res[i - 1][j] == 0;
			if (flag)
			{
				j--;
			}
			else if (flag2)
			{
				i--;
				direction = 4;
			}
			else
			{
				return res;
			}
			break;
		}
		case 4:
		{
			//可往上
			bool flag = i - 1 >= 0 && res[i - 1][j] == 0;
			//可往右
			bool flag2 = j + 1 < n && res[i][j + 1] == 0;
			if (flag)
			{
				i--;
			}
			else if (flag2)
			{
				j++;
				direction = 1;
			}
			else
			{
				return res;
			}
			break;
		}
		default:
			break;
		}
	}
	return res;
}


///网上大神的代码
vector<vector<int>> generateMatrix2(int n) {
	int l = 0, r = n - 1, t = 0, b = n - 1;
	vector<vector<int>> mat(n, vector<int>(n, 0));
	int num = 1, tar = n * n;
	while (num <= tar) {
		for (int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
		t++;
		for (int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
		r--;
		for (int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
		b--;
		for (int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
		l++;
	}
	return mat;
}
