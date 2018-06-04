#include <fstream>
#include <string>
using namespace std;

string quadTreeSolve(string a)
{
	string output="x";
	if (a.length() == 1)
	{
		return a;
	}
	else
	{
		int start, length, count=0;
		string a1, a2, a3, a4;
		start = length = 1;
		
		for (int it = 1; it < a.length(); it++)
		{
			if (a[it] == 'x') length+=4;
			else if (it == start + length - 1)
			{
				if(count==0) a3 = quadTreeSolve(a.substr(start, length));
				else if (count == 1) a4 = quadTreeSolve(a.substr(start, length));
				else if(count==2) a1 = quadTreeSolve(a.substr(start, length));
				else a2 = quadTreeSolve(a.substr(start, length));
				count++;
				start = start + length;
				length = 1;
			}	
		}
		output += a1 + a2 + a3 + a4;
		return output;		
	}
}

int main()
{
	ifstream in;
	ofstream out;
	string input;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		in >> input;
		out << quadTreeSolve(input) << "\n";

	}
	in.close();
	out.close();

	return 0;
}