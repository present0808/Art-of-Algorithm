#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define INF 987654321

const int button[10][16] = {
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool isAligned(int* clock)
{
	for (int i = 0; i < 16; i++)
	{
		if (clock[i] != 0) return false;
	}
	return true;
}

void main()
{
	std::fstream in,out;	
	in.open("input.txt", std::ios::in);
	out.open("output.txt", std::ios::out);
	//ют╥б
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		int clock[16], clock2[16], swit[10];
		unsigned int count;
		int min=INF;
		for (int j = 0; j < 16; j++)
		{
			int time;
			in >> time;
			clock[j] = (time / 3) % 4;
		}
		for (count = 0; count < 0x100000; count++)
		{
			unsigned int bitmasking = 3;
			for (int j = 0; j < 16; j++) clock2[j] = clock[j];

			for (int j = 0; j < 10; j++)
			{
				swit[j] = (count & bitmasking) >> (2 * j);
				bitmasking = bitmasking << 2;
			}
			
			for (int j = 0; j < 16; j++)
			{
				for (int k = 0; k < 10; k++)
					clock2[j] += button[k][j] * swit[k];
				clock2[j] %= 4;
			}
			if (isAligned(clock2))
			{
				int ret=0;
				for (int j = 0; j < 10; j++) ret += swit[j];
				if (ret < min) min = ret;
			}
			if (count % 10000 == 0) cout << count << "\n";
		}		
		if (min == INF) out << "-1\n";
		else out << min << "\n";
	}
	in.close();
	out.close();
}
