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

class UnionFind{
public:
	vector<int> parent, size, rank;
	int set_num;

	UnionFind(int n){
		set_num = n;
		parent.assign(n, 0); size.assign(n, 1); rank.assign(n, 0);
	}
	void Reset(){
		for(int i=0; i<set_num; i++) {
			parent[i] = i;
			size[i] = 1;
			rank[i] = 0;
		}
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

int main(){
	int u, v, refuse;
	UnionFind F(1e5+1);
	while(cin >> u){
		F.Reset();
		refuse = 0;
		while(u>-1){
			cin >> v;
			if(F.FindSet(u)!=F.FindSet(v))
				F.UnionSet(u, v);
			else refuse++;
			cin >> u;
		}
		cout << refuse << endl;
	}

	return 0;
}