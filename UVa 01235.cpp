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
	int NumSet(){ return set_num; }
	int SetSize(int i){ return size[FindSet(i)]; }
};

int cal_roll(string s1, string s2){
	int c=0;
	for(int i=0; i<4; i++)
		c += min(abs(s1[i]-s2[i]), 10-abs(s1[i]-s2[i]));
	return c;
}

bool cmp(pair<int, pii> e1, pair<int, pii> e2){
	return e1.first<e2.first;
}

int main(){
	int T, n, roll;
	vector<string> lock;
	vector<pair<int, pii>> edge;
	string s;

	cin >> T;
	for(int i=0; i<T; i++){
		cin >> n;
		cin.ignore();
		for(int i=0; i<n-1; i++){
			getline(cin, s, ' ');
			lock.push_back(s);
		}
		getline(cin, s);
		lock.push_back(s);
		for(int u=0; u<n-1; u++)
			for(int v=u+1; v<n; v++)
				edge.push_back(make_pair(cal_roll(lock[u], lock[v]), make_pair(u, v)));

		roll = 0;
		int m=40;
		for(int i=0; i<n; i++)
			m = min(m, cal_roll("0000", lock[i]));
		roll += m;
		//Kruskal's algorithm to find minimum spanning tree
		sort(edge.begin(), edge.end(), cmp);
		UnionFind F(n);
		for(int j=0; j<edge.size(); j++){
		 	int u = edge[j].second.first, v = edge[j].second.second;
		 	if(F.FindSet(u)!=F.FindSet(v)){
		 		F.UnionSet(u, v);
		 		roll += edge[j].first;
		 	}
		}
		cout << roll << endl;
		edge.clear();
		lock.clear();
	}


	return 0;
}