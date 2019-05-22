#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

#define pii pair<int, int>

class UnionFind{
public:
	vector<int> parent, size, rank;
	int set_num;

	UnionFind(int n){
		parent.assign(n, 0); size.assign(n, 1); rank.assign(n, 0);
		for(int i=0; i<n; i++) parent[i] = i;
		set_num = n;
	}
	int FindSet(int i){
		if(parent[i]==i) return i;
		return (parent[i] = FindSet(parent[i]));
	}
	bool SameSet(int i, int j){ return (FindSet(i)==FindSet(j)); }
	void UnionSet(int i, int j){
		int u = FindSet(i), v = FindSet(j);
		if(u==v) return;
		set_num--;
		if(rank[u]>rank[v]){
			parent[v] = u; size[u] += size[v];
		}
		else {
			parent[u] = v; size[v] += size[u];
			if(rank[u]==rank[v]) rank[v]++;
		}
	}
};

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return (e1.first<e2.first);
}

int main(){
	int n, m, u, v, c;
	vector<pair<int, pii>> edge;
	vector<int> cycle_weight;
	while(cin >> n >> m && n){
		for(int i=0; i<m; i++){
			cin >> u >> v >> c;
			edge.push_back(make_pair(c, make_pair(u, v)));
		}
		//Kruskal's algorithm to find minimum spanning tree
		sort(edge.begin(), edge.end(), cmp);
		UnionFind F(n);
		for(int i=0; i<m; i++){
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v))
				F.UnionSet(u, v);
			//edges that are not in the MST are cycle edges
			else cycle_weight.push_back(edge[i].first);
		}
		if(cycle_weight.size()==0)
			cout << "forest";
		else {
			cout << cycle_weight[0];
			for(int i=1; i<cycle_weight.size(); i++)
				cout << " " << cycle_weight[i];
		}
		cout << endl;
		edge.clear();
		cycle_weight.clear();
	}

	return 0;
}