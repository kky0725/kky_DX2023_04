#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// 이산수학의 그래프
// 그래프에 대한 조사
// 그래프의 기원
// 그래프를 쓰는 이유

vector<vector<bool>> adjacent2;
vector<bool> discovered;
queue<int> visitedQ;

void CreateGraphByMatrix()
{
	adjacent2 = vector<vector<bool>>(7, vector<bool>(7, false));
	discovered = vector<bool>(7, false);

	adjacent2[0][0] = true;
	adjacent2[0][1] = true;
	adjacent2[0][2] = true;
	adjacent2[0][4] = true;

	adjacent2[1][0] = true;
	adjacent2[1][1] = true;

	adjacent2[2][0] = true;
	adjacent2[2][2] = true;
	adjacent2[2][3] = true;
	adjacent2[2][5] = true;

	adjacent2[3][2] = true;
	adjacent2[3][3] = true;

	adjacent2[4][0] = true;
	adjacent2[4][4] = true;
	adjacent2[4][6] = true;

	adjacent2[5][2] = true;
	adjacent2[5][5] = true;

	adjacent2[6][4] = true;
	adjacent2[6][6] = true;
}

void DFS(int start)
{
	if (discovered[start])
		return;

	discovered[start] = true;
	cout << start << "를 방문 했습니다." << endl;

	for (int there = 0; there < adjacent2.size(); there++)
	{
		//자기자신은 제외
		if (start == there)
			continue;
		
		//인접해 있지 않으면 제외
		if (!adjacent2[start][there])
			continue;

		//방문한적 있으면 제외
		if (discovered[there])
			continue;

		DFS(there);
	}
}

int DfsAll()
{
	int count = 0;
	for (int start = 0; start < 7; start++)
	{
		if (!discovered[start])
		{
			DFS(start);
			count++;
		}
	}
	return count;
}

int main()
{
	CreateGraphByMatrix();
	int count = DfsAll();

	return 0;
}