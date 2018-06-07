#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
string N;
int cache[10000];

int classification(const string a)
{
	int len = a.length();
	int i, a0, d, flag;
	//case 1 숫자가 모두 똑같을때
	flag = 0;
	for (i = 0; i < len - 1; i++)
	{
		if (a[i] != a[i + 1]) flag = 1;
	}
	if (flag == 0) return 1;
	//case 2 등차수열
	flag = 0;
	d = a[0]-a[1];
	for (i = 0; i < len - 1; i++)
	{
		if (a[i] - a[i + 1] != d) flag = 1;
	}
	if (flag == 0)
	{
		if (d == 1 || d == -1) return 2;
		else return 5;
	}
	//case 3 번갈아가면서
	flag = 0;
	for (i = 0; i < len; i++)
	{
		if (i >= 2 && (a[i] != a[i - 2])) flag = 1;
	}
	if (flag == 0) return 4;
	//case 4 그외의경우
	return 10;
}

int solve(int n)
{
	if (N.length() - n < 3) return INF;
	int &ret = cache[n];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 3; i <= 5; i++)
	{
		if (N.length() - n < i) break;
		else if (N.length() - n == i) ret = min(ret, classification(N.substr(n,i)));
		else ret = min(ret, classification(N.substr(n, i)) + solve(n + i));
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
		in >> N;
		memset(cache, -1, sizeof(cache));
		
		out << solve(0) << endl;
	}

	in.close();
	out.close();
	return 0;
}