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
		set_num = n; parent.assign(n, 0); size.assign(n ,1); rank.assign(n, 0);
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
	return (e2.first>e1.first);
}

int main(){
	int N, S, P, x, y, u, v;
	vector<pair<double, pii>> edge;
	vector<pii> point;
	double D;
	UnionFind F;

	cin >> N;
	while(N--){
		cin >> S >> P;
		edge.clear();
		point.clear();
		for(int i=0; i<P; i++){
			cin >> x >> y;
			point.push_back(make_pair(x, y));
			for(int j=0; j<i; j++){
				int dx=point[i].first-point[j].first, dy=point[i].second-point[j].second;
				edge.push_back(make_pair(sqrt(1.0*dx*dx+1.0*dy*dy), make_pair(j, i)));
			}
		}
		F.Reset(P);
		D = 0;
		//A variant of Kruskal's algorithm to find minimum spanning forest
		sort(edge.begin(), edge.end(), cmp);
		for(int i=0; i<edge.size(); i++){
			if(F.NumofSet()==S)
				break;
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				D = max(D, edge[i].first);
			}
		}
		cout << fixed << setprecision(2) << D << endl;
	}

	return 0;
}