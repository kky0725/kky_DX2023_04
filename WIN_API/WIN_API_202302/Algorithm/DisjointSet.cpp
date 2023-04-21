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

//DisjointSet : 서로소 집합.

struct User
{
	int guild_id;

};

void GulidSystem()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user;
		user.guild_id = i;

		users.push_back(user);
	}

	// [0] [1] [2] [3] [4] [5]
	//  0   1   2   3   4   5

	//인덱스 1번 유저와 5번 유저가 길드를 합침.
	users[1].guild_id = users[5].guild_id;
	// [0] [1] [2] [3] [4] [5]
	//  0   5   2   3   4   5
}

class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent.resize(n, 0);

		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}
	~DisJointSet() {}

	int FindLaeder(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];

		return FindLaeder(parent);
	}

	void Merge(int u, int v)
	{
		int leaderU = FindLaeder(u);
		int leaderV = FindLaeder(v);

		if (leaderU == leaderV)
			return;

		_parent[leaderV] = leaderU;
	}

private:
	vector<int> _parent;
};

int main()
{
	DisJointSet guild = DisJointSet(10);

	cout << guild.FindLaeder(5) << endl;

	guild.Merge(1, 5);
	guild.Merge(5, 2);
	guild.Merge(5, 9);
	guild.Merge(5, 3);

	cout << guild.FindLaeder(3) << endl;

	return 0;
}