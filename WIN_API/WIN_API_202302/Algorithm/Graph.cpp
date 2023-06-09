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

// 그래프
// 노드끼리 서로 관련없이 연결되이 있는 구조를 나타낼 때 네일 적합한 자료구조.

vector<vector<int>> adjacent;
vector<vector<bool>> adjacent2;

// 인접 리스트로 그래프를 구현하기.
// 장점 :
// 단점 : 탐색하는 시간이 N
void CreateGraph()
{
	vector<int> v = vector<int>(6, -1);
	adjacent = vector<vector<int>>(7, vector<int>());

	adjacent[0].push_back(1);
	adjacent[0].push_back(2);
	adjacent[0].push_back(4);

	adjacent[1].push_back(0);

	adjacent[2].push_back(0);
	adjacent[2].push_back(3);
	adjacent[2].push_back(5);

	adjacent[3].push_back(2);

	adjacent[4].push_back(0);
	adjacent[4].push_back(6);

	adjacent[5].push_back(2);

	adjacent[6].push_back(4);
}


// 인접 행렬 그래프로 구현하기
// 장점 : 탐색하는 시간이 상수
// 단점 : 필요한 데이터 량이 커진다.
void CreateGraphByMatrix()
{
	adjacent2 = vector<vector<bool>>(7, vector<bool>(7, false));

	//	 0  1  2  3  4  5  6
	// 0 T  T  T  F  T  F  F
	// 1 T  T  F  F  F  F  F
	// 2 T  F  T  T  F  T  F
	// 3 F  F  T  T  F  F  F
	// 4 T  F  F  F  T  F  T
	// 5 F  F  T  F  F  T  F
	// 6 F  F  F  F  T  F  T

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

int main()
{
#pragma region 인접리스트로 인접 확인하기
	CreateGraph();

	auto iter = std::find(adjacent[0].begin(), adjacent[0].end(), 1);
	if(iter != adjacent[0].end())
		cout << "0과 1이 직접 연결되어 있습니다." << endl;
	else
		cout << "0과 1이 직접 연결되어 있지 않습니다." << endl;
#pragma endregion

	CreateGraphByMatrix();
	if (adjacent2[4][6])
		cout << "4와 6이 인접해 있습니다." << endl;
	else
		cout << "4와 6이 인접해 있지 않습니다." << endl;

	// DFS(Depth-First Search)
	// 깊이 우선 탐색

	// BFS(Breadth-First Search)
	// 너비 우선 탐색

	return 0;
}