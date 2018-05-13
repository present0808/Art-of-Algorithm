#include <fstream>
#include <string>
#include <utility>

int board[20][20]; // -1�� �ʱ�ȭ, ���� �� ���±���(#) = 0, ����� �Ǵ� ����(.) = 1, �̹� ���� ����(O) = 2

std::pair<int, int> tCase[4][2]
	= { {std::pair<int,int>(0,1),std::pair<int,int>(1,0)},
	{ std::pair<int,int>(0,1),std::pair<int,int>(1,1) },
	{ std::pair<int,int>(1,0),std::pair<int,int>(1,1) },
	{ std::pair<int,int>(1,0),std::pair<int,int>(1,-1) }}; // ��, ��,��, ��4���� ���̽��� ��� ��ǥ ����

int count,H,W; //Height, Width

void Boardcover()
{
	int flag = 0, x,y;
	// ���� ���
	for (x = 0; x < H; x++)
	{
		for (y = 0; y < W; y++)
		{
			if (board[x][y] == 1)
			{
				flag = 1; break;
			}
		}
		if (flag == 1) break;
	}
	if (flag == 0)
	{
		count++; return;
	}
	// �ȵ��� �κ��� ���� �� ���
	for (int i = 0; i < 4; i++)
	{
		int flag=0;
		for (int j = 0; j < 2; j++)
		{
			int nextX, nextY;
			nextX = x + tCase[i][j].first;
			nextY = y + tCase[i][j].second;
			if (board[nextX][nextY] != 1)
			{
				flag = 1; break;
			}
		}
		if (flag == 0)
		{
			//�� Ÿ���� ���´�.
			board[x][y] = 2;
			for (int j = 0; j < 2; j++)
			{
				int nextX, nextY;
				nextX = x + tCase[i][j].first;
				nextY = y + tCase[i][j].second;
				board[nextX][nextY] = 2;
			}
			Boardcover(); // ��� ȣ��
			//�� Ÿ���� ����.
			board[x][y] = 1;
			for (int j = 0; j < 2; j++)
			{
				int nextX, nextY;
				nextX = x + tCase[i][j].first;
				nextY = y + tCase[i][j].second;
				board[nextX][nextY] = 1;
			}
		}
	}
	return;
}

void main()
{
	std::fstream in,out;	
	in.open("input.txt", std::ios::in);
	out.open("output.txt", std::ios::out);
	//�Է�
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		int dotCount=0;
		memset(board, -1, sizeof(board));
		in >> H >> W;
		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
			{
				char c;
				in >> c;
				if (c == '.')
				{
					dotCount++; board[j][k] = 1;
				}
				else board[j][k] = 0;
			}
		}
		count = 0;
		if(dotCount %3 == 0) Boardcover();
		out << count << "\n";
	}

	in.close();
	out.close();
}
