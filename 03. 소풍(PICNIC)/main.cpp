#include <fstream>
#include <string>

int studentPair[10][10];
int studentAlready[10];
int sNum;
int count;

void picnic()
{
	int flag = 0, i;
	//기저 사례
	for ( i = 0; i < sNum; i++)
	{
		if (studentAlready[i] == 0)
		{
			flag = 1; break;
		}
	}
	if (flag == 0)
	{
		count++; return;
	}	
	for (int j = i + 1; j < sNum; j++)
	{
		if (studentAlready[j] == 0 && studentPair[i][j] == 1)
		{
			studentAlready[i] = studentAlready[j] = 1;
			picnic();
			studentAlready[i] = studentAlready[j] = 0;
		}
	}
	return;
}


void main()
{
	std::fstream in,out;	
	in.open("input.txt", std::ios::in);
	out.open("output.txt", std::ios::out);
	//입력
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		int	pNum;
		in >> sNum >> pNum;
		memset(studentPair, 0, sizeof(studentPair));
		memset(studentAlready, 0, sizeof(studentAlready));	
		count = 0;
		for (int j = 0; j < pNum; j++)
		{
			int a, b;
			in >> a >> b;
			studentPair[a][b] = studentPair[b][a] = 1;
		}
		picnic();
		out << count << "\n";
	}

	in.close();
	out.close();
}
