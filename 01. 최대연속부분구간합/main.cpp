#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

// O(n^3) 알고리즘
int verySlow(const vector<int>& A)
{
	int size = A.size();
	int i, j, k, ret=MIN;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			int sum = 0;
			for (k = i; k <= j; k++)
			{
				sum += A[k];
			}			
			ret = max(ret, sum);
		}
	}
	return ret;
}

//O(n^2) 알고리즘
int slow(const vector<int>& A)
{
	int size = A.size();
	int i, j, ret = MIN;
	for (i = 0; i < size; i++)
	{
		int sum = 0;
		for (j = i; j < size; j++)
		{	
			sum += A[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

//O(nlogn) 알고리즘 : 분할 정복
int divideAndConquer(const vector<int>& A, int lo, int hi)
{
	//Base : 구간의 길이가 1일때	
	if (lo == hi) return A[lo];
	// 배열을 lo~mid, mid+1~hi 로 나눔
	int mid = (lo + hi) / 2;
	// 중간에 걸친 경우를 생각
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; i--)
	{
		sum += A[i];
		left = (left > sum) ? left : sum;
	}
	sum = 0;
	for (int i = mid + 1; i <= hi; i++)
	{
		sum += A[i];
		right = (right > sum) ? right : sum;
	}
	// 부분 수열이 각각의 두 조각 중 하나에만 속해있을 경우
	int single = max(divideAndConquer(A, lo, mid), divideAndConquer(A, mid + 1, hi));
	return max(single, left + right);
}

//O(n) 알고리즘 : 동적 계획법
int fastest(const vector<int>& A)
{
	int i, sum=0, ret=MIN;
	for (i = 0; i < A.size(); i++)
	{
		sum = max(sum, 0) + A[i];
		ret = max(sum, ret);
	}
	return ret;
}

void main()
{
	fstream input,output;
	vector<int> a;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);

	//입력
	while(!input.eof())
	{
		int i;
		input >> i;
		a.push_back(i);
	}

	//출력
	output << verySlow(a) << "\n";
	output << slow(a) << "\n"; 
	output << divideAndConquer(a, 0, a.size() - 1) << "\n";
	output << fastest(a);

	input.close();
	output.close();
}
