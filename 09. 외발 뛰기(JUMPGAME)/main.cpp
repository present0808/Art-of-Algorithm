#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int board[7][7];
int cache[7][7];
bool jump(int x, int y)
{
	if (x >= 7 || y >= 7) return 0;
	if (x == 6 && y == 6) return 1;
	int &ret = cache[x][y];
	if (ret != -1) return ret;
	int jumpSize = board[x][y];
	ret = jump((x + jumpSize), y) || jump(x, (y + jumpSize));
	return ret;
}

int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			in >> board[i][j];
	out << jump(0,0);


	in.close();
	out.close();
	return 0;
}