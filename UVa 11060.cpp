#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

int n, m, c;
vector<int> adj[100], top_order;
int indegree[100];
map<string, int> bev;
vector<string> b;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	string s1, s2;
	c = 1;
	cin >> n;
	while(!cin.eof()) {
		getline(cin, s1);
		for(int i=0; i<n; i++) {
			getline(cin, s1);
			bev.insert(make_pair(s1, i));
			b.push_back(s1);
		}
		cin >> m;
		getline(cin, s1);
		memset(indegree, 0, sizeof(indegree));
		for(int i=0; i<m; i++) {
			getline(cin, s1, ' ');
			getline(cin, s2);
			auto f1=bev.find(s1), f2=bev.find(s2);
			int u=f1->second, v=f2->second;
			adj[u].push_back(v);
			indegree[v]++;
		}
		for(int i=0; i<n; i++)
			if(indegree[i]==0)
				q.push(i);
		//topological sort using a queue that stores the vertices with indegree 0
		while(!q.empty()) {
			int u = q.top();
			top_order.push_back(u);
			q.pop();
			for(int i=0; i<adj[u].size(); i++) {
				int v = adj[u][i];
				indegree[v]--;
				if(indegree[v]==0)
					q.push(v);
			}
		}
		cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
		c++;
		for(int i=0; i<n; i++)
			cout << " " << b[top_order[i]];
		cout << ".\n\n";
		for(int i=0; i<n; i++)
			adj[i].clear();
		bev.clear();
		b.clear();
		top_order.clear();
		cin >> n;
	}

	return 0;
}