#include <windows.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string.h>
#include <map>
using namespace std;
typedef map<string, vector<string>> adj;

struct edge {
	int b;
	double w;
	edge(int x = 0, double y = 0) {
		b = x;
		w = y;
	}
};

void readGraph(adj &Adj){
	int n;
	string a, b, c;
	double w;
	ifstream cin("graph.txt");
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		Adj[a].push_back(b);
		Adj[a].push_back(c);
		Adj[b].push_back(a);
		Adj[b].push_back(c);
		Adj[c].push_back(a);
		Adj[c].push_back(b);
	}
}

void BFS(adj Adj, int v, map<string, int> &d)
{
	bool flag = false;
	for (auto i = Adj.begin(); i!= Adj.end(); i++)
	{
		d[i->first] = INT_MAX;
		if(i->first == "Isenbaev")
			flag = true;
	}
	d["Isenbaev"] = 0;
	queue<string> Q;
	Q.push("Isenbaev");
	while (Q.size())
	{
		string u = Q.front();
		Q.pop();
		for (auto i = Adj[u].begin; i != Adj[u].size(); i++)
		{
				int to = Adj[u][i];
			if (d[to] == INT_MAX)
			{
				d[to] = d[u] + 1;
				p[to] = u;
				Q.push(to);
			}

		}
	}
}

int main()
{
	adj Adj;
	int v = 0;
	vector<int> d, p;
	readGraph("graph.txt", Adj);
	int n = Adj.size();
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < Adj[i].size(); j++)
			cout << Adj[i][j]<<" ";
		cout << endl;
	}
	BFS(Adj, v, d, p);

	for (int i = 0; i < n; i++)
	{
		if (p[i] == -1)
		{
			cout << i << " is unreachable " << endl;
			continue;
		}
		int u = i;
		do
		{
			cout << u << " <- ";
			u = p[u];
		} while (u != -1);
			cout << endl;
	}
	system("pause");
	return 0;
}