#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int N[20000];
int fenceSolve(int start, int end)
{
	if (start == end) return N[start];
	else
	{
		int half = (start + end) / 2;
		int ret;		
		//divide & conquer
		ret = max(fenceSolve(start, half), fenceSolve(half + 1, end));
		//사이에 껴있는경우
		int middlecase,height, left, right;
		left = half; right = half + 1;
		height = min(N[left], N[right]);
		ret = max(ret, height * 2);
		while (!(left == start && right == end))
		{
			if (left == start)
			{
				right = right + 1;
				if (height > N[right]) height = N[right];
				ret = max(ret, height*(right - left + 1));				
			}
			else if (right == end)
			{
				left = left - 1;
				if (height > N[left]) height = N[left];
				ret = max(ret, height*(right - left + 1));
			}
			else
			{
				if (N[left - 1] <= N[right + 1])
				{
					right = right + 1;
					if (height > N[right]) height = N[right];
					ret = max(ret, height*(right - left + 1));
				}
				else
				{
					left = left - 1;
					if (height > N[left]) height = N[left];
					ret = max(ret, height*(right - left + 1));
				}			
			}
		}
		return ret;
	}
}

int main()
{
	ifstream in;
	ofstream out;
	int num;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		in >> num;
		for (int j = 0; j < num; j++)
		{
			in >> N[j];
		}
		out << fenceSolve(0, num - 1) << endl;

	}
	in.close();
	out.close();

	return 0;
}