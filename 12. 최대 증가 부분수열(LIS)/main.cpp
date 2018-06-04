#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int bigint;

const bigint NEGINF = numeric_limits<long long>::min();
int n[100],m[100], N,M;
int cache[101][101];

int solve(int x, int y)
{
	int &ret = cache[x+1][y+1];
	if (ret != -1) return ret;
	ret = 2;
	bigint a = (x == -1 ? NEGINF : n[x]);
	bigint b = (y == -1 ? NEGINF : m[y]);
	bigint maxElement = max(a, b);
	for (int i = x + 1; i < N; i++)
	{
		if (maxElement < n[i]) ret = max(ret, solve(i, y) + 1);
	}
	for (int j = y + 1; j < M; j++)
	{
		if (maxElement < m[j]) ret = max(ret, solve(x, j) + 1);
	}
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
		in >> N >>M;
		for (int j = 0; j < N; j++)
		{
			in >> n[j];			
		}
		for (int j = 0; j < M; j++)
		{
			in >> m[j];
		}
		memset(cache, -1, sizeof(cache));
		
		out << solve(-1,-1)-2 << endl;
	}

	in.close();
	out.close();
	return 0;
}