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

#define vi vector<int>
#define pii pair<int, int>

int n;
vector<pair<int, pii>> edge;


class UnionFind{
public:
	vi parent, rank, size;
	int set_num;

	UnionFind(int n){
		parent.assign(n, 0); rank.assign(n, 0); size.assign(n, 1);
		set_num = n;
		for(int i=0; i<n; i++) parent[i] = i;
	}
int FindSet(int i){
	if(parent[i]==i) return i;
	return (parent[i] = FindSet(parent[i]));
}
bool SameSet(int i, int j){ return (FindSet(i)==FindSet(j)); }
void UnionSet(int i, int j){
	int u=FindSet(i), v=FindSet(j);
	if(u==v) return;
	set_num--;
	if(rank[u]<rank[v]){
		parent[u] = v; size[v] += size[u];
	}
	else {
		parent[v] = u; size[u] += size[v];
		if(rank[u]==rank[v]) rank[u]++;
	}
}
int NumofSet(){ return set_num; }
int SizeofSet(int i){ return size[FindSet(i)]; }
};

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return (e1.first<e2.first);
}

int main() {
	int cost, u, v, c, m, k;

	cin >> n;
	while(true){
		cost = 0;
		for(int i=0; i<n-1; i++){
			cin >> u >> v >> c;
			cost += c;
		}
		cout << cost << endl; //Initial cost
		cin >> k;
		for(int i=0; i<k; i++){
			cin >> u >> v >> c;
			edge.push_back(make_pair(c, make_pair(u-1, v-1)));
		}
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> u >> v >> c;
			edge.push_back(make_pair(c, make_pair(u-1, v-1)));
		}
		m += k;

		//Kruskal's algorithm to find minimum spanning tree
		sort(edge.begin(), edge.end(), cmp);
		cost = 0;
		UnionFind F(n);
		for(int i=0; i<m; i++){
			u = edge[i].second.first; v = edge[i].second.second;
			c = edge[i].first;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				cost += c;
			}
		}
		cout << cost << endl; //Total cost of MST
		edge.clear();
		if(cin >> n)
			cout << endl;
		else break;
	}

	return 0;
}