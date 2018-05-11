#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
const int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
const int dy[8] = { -1,0,1,1,1,0,-1,-1 };
char board[5][5];
int cache[5][5][10];
string word;

//�׳� ���
/*
int hasWord(int x, int y, int th)
{
	// ���� ���
	if (x < 0 || x>4 || y < 0 || y>4) return 0;
	// ���� ���
	if (word.length() - 1 == th)
	{
		if (word[th] == board[x][y]) return 1;
		else return 0;
	}

	
	if (board[x][y] != word[th]) return false;
	
	// ���� Ž��
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + dx[i], nextY = y + dy[i];
		if (hasWord(nextX, nextY, th + 1))
		{
			return true;
		}
	}
	return false;
}
*/
//Cache�� �̿��� ���� ��ȹ
int hasWord(int x, int y, int th)
{
	// ���� ���
	if (x<0 || x>4 || y<0 || y>4)
	{
		return 0;
	}
	// ���� ���
	if (word.length()-1 == th)
	{
		if (word[th] == board[x][y]) return 1;		
		else return 0;
	}
	
	//cache check
	int& ret = cache[x][y][th];
	if (ret != -1) return ret;
	if (board[x][y] != word[th])
	{
		ret = 0; 
		return ret;
	}
	// ���� Ž��
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + dx[i], nextY = y + dy[i];
		if (hasWord(nextX, nextY, th + 1))
		{
			ret = 1;
			return ret;
		}
	}
	ret = 0;
	return ret;
}
void main()
{
	fstream input,output;	
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	//�Է�
	int C;
	input >> C;
	for (int i = 0; i < C; i++)
	{
		for(int j=0; j<5; j++) input >> board[j];
		int N; 
		input >> N;
		for (int j = 0; j < N; j++)
		{
			int flag=0;
			input >> word;
			memset(cache, -1, sizeof(cache));
			for (int k = 0; k < 25; k++)
			{
				
				if (hasWord(k / 5, k % 5, 0))
				{
					output << word << " YES\n";
					flag = 1;
					break;
				}
			}
			if(flag==0) output << word << " NO\n";
		}
	}

	//���
	
	input.close();
	output.close();
}
