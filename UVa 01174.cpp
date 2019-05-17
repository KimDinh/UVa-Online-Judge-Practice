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
		if(rank[u]>rank[v]){
			parent[v] = u; size[u] += size[v];
		}
		else{
			parent[u] = v; size[v] += size[u];
			if(rank[u]==rank[v]) rank[v]++;
		}
	}
	int NumSet() { return set_num; }
	int SizeSet(int i) { return size[FindSet(i)]; }
};

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return (e1.first<e2.first);
}

int main(){
	int n, m, T, u, v, c, cost, size;
	string s1, s2;
	unordered_map<string, int> citytoint;
	vector<pair<int, pii>> edge;

	cin >> T;
	while(T--){
		cin >> n >> m;
		cin.ignore();
		size = 0;
		for(int i=0; i<m; i++){
			getline(cin, s1, ' ');
			getline(cin, s2, ' ');
			cin >> c; cin.ignore();
			auto f1=citytoint.find(s1), f2=citytoint.find(s2);
			if(f1!=citytoint.end())
				u = f1->second;
			else {
				citytoint.insert(make_pair(s1, size));
				u = size++;
			}
			if(f2!=citytoint.end())
				v = f2->second;
			else{
				citytoint.insert(make_pair(s2, size));
				v = size++;
			}
			edge.push_back(make_pair(c, make_pair(u, v)));
		}
		cost = 0;
		//Kruskal's algorithm to find minimum spanning tree
		sort(edge.begin(), edge.end());
		UnionFind F(n);
		for(int i=0; i<m; i++){
			u = edge[i].second.first; v = edge[i].second.second;
			if(F.FindSet(u)!=F.FindSet(v)){
				F.UnionSet(u, v);
				cost += edge[i].first;
			}
		}
		cout << cost << endl;
		if(T) cout << endl;
		edge.clear();
		citytoint.clear();
	}

	return 0;
}