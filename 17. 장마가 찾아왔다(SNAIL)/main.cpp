#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

double cache[1001][2001];
int depth, days;

double snail(int day, int climbed)
{
	if (day == days) return (climbed >= depth) ? 1 : 0;
	double& ret = cache[day][climbed];
	if (ret != -1.0) return ret;
	return ret = snail(day + 1, climbed + 2)*0.75 + 0.25*snail(day + 1, climbed + 1);
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
		in >> depth >> days;
		fill_n(&cache[0][0], 2003001, -1.0);
		out.precision(10);
		out << fixed << snail(0, 0) << endl;
	}

	in.close();
	out.close();
	return 0;
}