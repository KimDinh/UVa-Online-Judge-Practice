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
	int NumofSet(){ return set_num; }
	int SetSize(int i){ return size[FindSet(i)]; }
};

bool cmp(pair<double, pii> e1, pair<double, pii> e2){
	return (e2.first-e1.first > epsilon);
}

int main(){
	int T, k, n, x, y, u, v, d;
	vector<pii> point;
	vector<pair<double, pii>> edge;
	UnionFind F;

	cin >> T;
	while(T--){
		n = 0;
		point.clear();
		edge.clear();
		cin >> k;
		while(cin >> x && x!=-1){
			cin >> y;
			point.push_back(make_pair(x, y));
			n++;
			if(n==1) continue;
			for(int i=0; i<n-1; i++){
				int dx=point[i].first-point[n-1].first, dy=point[i].second-point[n-1].second;
				edge.push_back(make_pair(sqrt(1.0*dx*dx+1.0*dy*dy), make_pair(i, n-1)));
			}
		}
		double ecd=0;
		//Minimum spanning forest with k components using Kruskal's algorithm
		sort(edge.begin(), edge.end(), cmp);
		F.Reset(n);
		for(int i=0; i<edge.size(); i++){
			if(F.NumofSet()==k) break;
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				ecd = edge[i].first;
			}
		}
		if(ecd-int(ecd)>=0 && ecd-int(ecd)<epsilon)
			cout << int(ecd) << endl;
		else cout << int(ecd)+1 << endl;
	}

	return 0;
}