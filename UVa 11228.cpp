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
	int NumofSet() { return set_num; }
	int SetSize(int i) { return size[i]; }
};

bool cmp(pair<double, pii> p1, pair<double, pii> p2){
	return (p2.first-p1.first>epsilon);
}

int main() {
	int T, n, r, x, y;
	vector<pair<double, pii>> edge;
	vector<pii> point;

	cin >> T;
	for(int c=1; c<=T; c++){
		cin >> n >> r;
		for(int i=0; i<n; i++){
			cin >> x >> y;
			point.push_back(make_pair(x, y));
			if(i==0) continue;
			for(int j=0; j<i; j++){
				int dx=point[i].first-point[j].first, dy=point[i].second-point[j].second;
				edge.push_back(make_pair(sqrt(1.0*dx*dx+1.0*dy*dy), make_pair(j, i)));
			}
		}
		sort(edge.begin(), edge.end(), cmp);
		double road=0, railroad=0;
		int state=1;
		//Kruskal's algorithm to find minimum spanning tree
		UnionFind F(n);
		for(int i=0; i<edge.size(); i++){
			int u = edge[i].second.first, v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				//the edge added is a road
				if(edge[i].first-1.0*r<epsilon)
					road += edge[i].first;
				//the edge added is a railroad, increment # of states
				else { state++; railroad += edge[i].first; }
			}
		}
		cout << "Case #" << c << ": " << state << " " << int(road+0.5) << " " << int(railroad+0.5) << endl;
		edge.clear();
		point.clear();
	}

	return 0;
}