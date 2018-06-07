#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int cache[101][102];

int poly(int bottomBlockNum, int leftBlockNum)
{
	int &ret = cache[bottomBlockNum][leftBlockNum];
	if (bottomBlockNum == leftBlockNum) return ret=1;
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= leftBlockNum - bottomBlockNum; i++)
	{
		ret += poly(i, leftBlockNum - bottomBlockNum) * (bottomBlockNum + i - 1);
		ret = (10000000 + (ret % 10000000)) % 10000000;
	}
	ret = (10000000 + (ret % 10000000)) % 10000000;
	return ret;
}

int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	memset(cache, -1, sizeof(cache));
	poly(1, 101);
	for (int i = 0; i < C; i++)
	{
		int n, ret=0;
		in >> n;
		for (int j = 1; j <= n; j++)
		{
			ret += cache[j][n];
		}
		ret = (10000000 + (ret%10000000)) % 10000000;
		out << ret << endl;
	}

	in.close();
	out.close();
	return 0;
}