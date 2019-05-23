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

	void Reset(int n){
		set_num = n; parent.assign(n, 0); size.assign(n, 1); rank.assign(n, 0);
		for(int i=0; i<n; i++) parent[i] = i;
	}
	int FindSet(int i){
		if(parent[i]==i) return i;
		return (parent[i] = FindSet(parent[i]));
	}
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
	int NumofSet(){ return set_num; }
};

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return (e1.first<e2.first);
}

int main(){
	int T, n, m, u, v, c, S1, S2;
	vector<pair<int, pii>> edge;
	vector<pii> mst;
	UnionFind F;

	cin >> T;
	while(T--){
		cin >> n >> m;
		edge.clear();
		mst.clear();
		for(int i=0; i<m; i++){
			cin >> u >> v >> c;
			edge.push_back(make_pair(c, make_pair(u-1, v-1)));
		}
		F.Reset(n);
		S1 = 0;
		//Kruskal's algorithm to find minumum spanning tree
		sort(edge.begin(), edge.end(), cmp);
		for(int i=0; i<m; i++){
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				mst.push_back(make_pair(u, v));
				S1 += edge[i].first;
			}
		}
		//Iterate through every edge of MST, run Kruskal without that edge
		//to find second best spanning tree
		S2 = 1e9;
		int tmp;
		for(int i=0; i<n-1; i++){
			int u1=mst[i].first, v1=mst[i].second;
			F.Reset(n);
			tmp = 0;
			for(int j=0; j<m; j++){
				u = edge[j].second.first; v = edge[j].second.second;
				if(u==u1 && v==v1)
					continue;
				if(F.FindSet(u)!=F.FindSet(v)){
					F.UnionSet(u, v);
					tmp += edge[j].first;
				}
			}
			if(F.NumofSet()==1)
				S2 = min(S2, tmp);
		}
		cout << S1 << " " << S2 << endl;
	}

	return 0;
}