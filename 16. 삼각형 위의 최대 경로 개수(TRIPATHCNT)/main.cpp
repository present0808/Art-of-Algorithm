#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int cache[100][100];
int board[100][100];
int n;

int maxPathSum(int x, int y)
{
	int &ret = cache[x][y];
	if (ret != -1) return ret;
	if (x == (n - 1)) return ret=board[x][y];
	ret = max(maxPathSum(x + 1, y), maxPathSum(x + 1, y + 1)) + board[x][y];
	return ret;
}
int maxPathNum(int x, int y, int leftPathSum)
{
	if (x == n - 1) return (leftPathSum == board[x][y]);
	int ret=0;
	int a = leftPathSum - board[x][y];
	if (a == cache[x + 1][y]) ret += maxPathNum(x + 1, y, a);
	if (a == cache[x + 1][y + 1]) ret += maxPathNum(x + 1, y + 1, a);
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
	for (int i = 0; i < C; i++)
	{
		in >> n;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				in >> board[j][k];
			}
		}
		memset(cache, -1, sizeof(cache));
		int maxPath = maxPathSum(0, 0);
		out << maxPathNum(0, 0, maxPath) << endl;
	}

	in.close();
	out.close();
	return 0;
}