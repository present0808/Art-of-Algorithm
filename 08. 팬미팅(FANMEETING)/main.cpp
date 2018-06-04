#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void addTo(vector<int> &a, const vector<int> &b, int k)
{
	for (int i = 0; i < b.size(); i++)
	{
		a[k + i] = b[i] + a[k + i];
	}
}
void subFrom(vector<int> &a, vector<int> &b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a[i] = a[i] - b[i];
	}
}
vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
	vector<int> ret(a.size()+b.size());
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			ret[j + i] += a[j] * b[i];
		}
	}
	return ret;
}


vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}


int solve(const string& members, const string& fans)
{
	int N = members.size(), M = fans.size();
	vector<int> m(N), f(M), mf(N+M);
	for (int i = 0; i < N; i++)
		m[i] = (members[i] == 'M') ? 1 : 0;
	for (int i = 0; i < M; i++)
		f[M-i-1] = (fans[i] == 'M') ? 1 : 0;
	mf = karatsuba(m, f);
	int count=0;
	for (int i = N - 1; i < M; i++)
	{
		if (mf[i] == 0) count++;
	}
	return count;

}

int main()
{
	ifstream in;
	ofstream out;
	string members, fans;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		in >> members;
		in >> fans;
		out << solve(members, fans) << endl;
		
	}
	in.close();
	out.close();

	return 0;
}