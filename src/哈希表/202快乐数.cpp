#include <unordered_set>

using namespace std;

int calculateValue(int a);

bool isHappy(int n) {
	unordered_set<int> container;
	container.insert(n);
	while (true)
	{
		n = calculateValue(n);
		if (n == 1)
		{
			return true;
		}
		if (container.find(n) != container.end())
		{
			return false;
		}
		container.insert(n);
	}
}

int calculateValue(int a)
{
	int res = 0;
	do
	{
		int v = a % 10;
		res += v * v;
		a = a / 10;
	} while (a != 0);
	return res;
}