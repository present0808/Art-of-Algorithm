#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	int f[101], sym[101], asym[101];
	
	f[1] = 1; f[2] = 2;
	for (int i = 3; i < 101; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
	}
	sym[1] = 1; sym[2] = 2; sym[3] = 1; sym[4] = 3;
	asym[1] = 0; asym[2] = 0; asym[3] = 2; asym[4] = 2;
	for (int i = 5; i < 101; i++)
	{
		sym[i] = (sym[i - 2] + sym[i - 4]) % 1000000007;
		asym[i] = (f[i] - sym[i]);
		asym[i] = (asym[i] < 0) ? asym[i] + 1000000007 : asym[i];
	}
	for (int i = 0; i < C; i++)
	{
		int n;
		in >> n;
		out << asym[n] << endl;
	}

	in.close();
	out.close();
	return 0;
}