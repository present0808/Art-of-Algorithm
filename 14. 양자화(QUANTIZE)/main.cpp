#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 987654321;
using namespace std;

int N, S;
vector<int> n;

int cache[1000][10];

int solve(int start, int quantNum)
{
	if (start == N - 1) return 0;
	int &ret = cache[start][quantNum];
	if (ret != -1) return ret;
	if (quantNum == 1)
	{		
		int i,sum = 0, av, dev=0;
		for (i=start; i < N; i++) sum += n[i];
		av =( ((float)sum) / (i - start) )+0.5;
		for (i = start; i < N; i++) dev += (av - n[i])*(av - n[i]);
		return ret = dev;
	}
	else
	{
		int i,j, minimum=INF;
		for (i = start+1; i < N; i++)
		{
			int av, dev=0, sum=0;
			for (j = start; j < i; j++) sum += n[j];
			av = (((float)sum) / (i - start)) + 0.5;
			for (j = start; j<i; j++) dev += (av - n[j])*(av - n[j]);
			minimum = min(minimum, dev + solve(i, quantNum - 1));
		}
		return ret = minimum;
	}

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
		int k;
		n.clear();
		in >> N >> S;
		for (int j = 0; j < N; j++)
		{
			in >> k;
			n.push_back(k);
		}
		sort(n.begin(), n.end());
		memset(cache, -1, sizeof(cache));
		out << solve(0, S) << endl;

	}

	in.close();
	out.close();
	return 0;
}