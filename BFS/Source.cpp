#include <windows.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

struct edge;
using namespace std;



typedef vector<vector<edge>> adj;

struct edge {
	int b;
	double w;
	edge(int x = 0, double y = 0) {
		b = x;
		w = y;
	}
};



void readGraph(char* name, adj &Adj){
	int n, a, b;
	double w;
	ifstream fs(name);
	fs >> n;
	Adj = adj(n);
	while (!fs.eof()){
		fs >> a >> b >> w;
		Adj[a].push_back(edge(b,w));
	}
}

void BFS(adj Adj, int v, vector<int> &d, vector<int> &p)
{
	int n = Adj.size();
	d.resize(n);
	p.resize(n);

	for (int i = 0; i < n; i++)
	{
		p[i] = -1;
		d[i] = INT_MAX;
	}
	d[v] = 0;
	queue<int> Q;
	Q.push(v);
	while (Q.size())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < Adj[u].size(); i++)
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