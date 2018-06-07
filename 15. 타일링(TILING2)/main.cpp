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
	int f[101];
	f[1] = 1; f[2] = 2;
	for (int i = 3; i < 101; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
	}
	for (int i = 0; i < C; i++)
	{
		int n;
		in >> n;
		out << f[n] << endl;
	}

	in.close();
	out.close();
	return 0;
}