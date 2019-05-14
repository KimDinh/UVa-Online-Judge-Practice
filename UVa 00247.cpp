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

int n, m, c, pre[25], low[25], root[25];
vector<int> adj[25];
unordered_map<string, int> nametoint;
vector<string> inttoname;
bool visited[25];
stack<int> s;

//Tarjan algorithm to find SCCs
void TarjanDFS(int u, int &clock){
	visited[u] = 1;
	pre[u] = low[u] = ++clock;
	s.push(u);
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!visited[v]){
			TarjanDFS(v, clock);
			low[u] = min(low[u], low[v]);
		}
		else if(root[v]==-1)
			low[u] = min(low[u], pre[v]);
	}
	//pop vertices from stack until we reach u
	if(low[u]==pre[u]){
		int w = s.top();
		s.pop();
		root[w] = u;
		cout << inttoname[w];
		while(w!=u){
			w = s.top();
			s.pop();
			root[w] = u;
			cout << ", " << inttoname[w];
		}
		cout << endl;
	}
}

//Find strongly connected components
void FindSCC(){
	int clock = 0;
	for(int i=0; i<n; i++){
		visited[i] = 0;
		root[i] = -1;
	}
	for(int i=0; i<n; i++)
		if(!visited[i])
			TarjanDFS(i, clock);
}

int main(){
	int u, v, count;
	string s1, s2;
	cin >> n >> m;
	c = 1;
	while(n && m){
		cin.ignore();
		count = 0;

		//read in names and calls
		for(int i=0; i<m; i++){
			getline(cin, s1, ' ');
			getline(cin, s2);
			auto f1=nametoint.find(s1), f2=nametoint.find(s2);
			if(f1!=nametoint.end())
				u = f1->second;
			else {
				u = count;
				nametoint.insert(make_pair(s1, count++));
				inttoname.push_back(s1);
			}
			if(f2!=nametoint.end())
				v = f2->second;
			else {
				v = count;
				nametoint.insert(make_pair(s2, count++));
				inttoname.push_back(s2);
			}
			adj[u].push_back(v);
		}

		cout << "Calling circles for data set " << c++ << ":\n";
		FindSCC();
		cin >> n >> m;
		if(n && m)
			cout << endl;
		nametoint.clear();
		inttoname.clear();
		for(int i=0; i<n; i++)
			adj[i].clear();
	}

	return 0;
}