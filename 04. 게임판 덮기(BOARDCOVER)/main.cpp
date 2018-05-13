#include <fstream>
#include <string>
#include <utility>

int board[20][20]; // -1로 초기화, 덮을 수 없는구역(#) = 0, 덮어야 되는 구역(.) = 1, 이미 덮은 구역(O) = 2

std::pair<int, int> tCase[4][2]
	= { {std::pair<int,int>(0,1),std::pair<int,int>(1,0)},
	{ std::pair<int,int>(0,1),std::pair<int,int>(1,1) },
	{ std::pair<int,int>(1,0),std::pair<int,int>(1,1) },
	{ std::pair<int,int>(1,0),std::pair<int,int>(1,-1) }}; // ┌, ┐,└, ┘4가지 케이스의 상대 좌표 저장

int count,H,W; //Height, Width

void Boardcover()
{
	int flag = 0, x,y;
	// 기저 사례
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
	// 안덮은 부분이 있을 때 재귀
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
			//그 타일을 놓는다.
			board[x][y] = 2;
			for (int j = 0; j < 2; j++)
			{
				int nextX, nextY;
				nextX = x + tCase[i][j].first;
				nextY = y + tCase[i][j].second;
				board[nextX][nextY] = 2;
			}
			Boardcover(); // 재귀 호출
			//그 타일을 뺀다.
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
	//입력
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
