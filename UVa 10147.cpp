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
const double epsilon = 1e-8;

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

bool cmp(pair<double, pii> e1, pair<double, pii> e2){
	return (e2.first-e1.first>epsilon);
}

int main(){
	int T, n, m, x, y, u, v;
	vector<pair<double, pii>> edge;
	vector<pii> point;
	UnionFind F;

	cin >> T;
	while(T--){
		cin >> n;
		edge.clear();
		point.clear();
		for(int i=0; i<n; i++){
			cin >> x >> y;
			point.push_back(make_pair(x, y));
			for(int j=0; j<i; j++){
				int dx=point[i].first-point[j].first, dy=point[i].second-point[j].second;
				edge.push_back(make_pair(sqrt(1.0*dx*dx+1.0*dy*dy), make_pair(j, i)));
			}
		}
		F.Reset(n);
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> u >> v;
			u-=1; v-=1;
			F.UnionSet(u, v);
		}
		//All towns are already connected
		if(F.NumofSet()==1){
			cout << "No new highways need\n";
			if(T) cout << endl;
			continue;
		}
		//Kruskal's algorithm 
		sort(edge.begin(), edge.end(), cmp);
		for(int i=0; i<edge.size(); i++){
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				cout << u+1 << " " << v+1 << endl;
			}
			if(F.NumofSet()==1)
				break;
		}
		if(T) cout << endl;
	}

	return 0;
}