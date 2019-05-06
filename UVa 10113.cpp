#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
using namespace std;

#define pii pair<int, int>

int n;
vector<pair<int, pii>> adj[61];
unordered_map<string, int> m;
pii rate[61];
bool visited[61];

//convert to lowest term
pii lowest(pii p) {
	int num=p.first, den=p.second, g=__gcd(num, den);
	return make_pair(num/g, den/g);
}

//multiply two exchange rates
pii combine_rate(pii p1, pii p2) {
	return lowest(make_pair(p1.first*p2.first, p1.second*p2.second));
}

//dfs to get exchange rate from src to dest
pii get_rate(int src, int dest){
	memset(visited, 0, sizeof(visited));
	stack<int> st;
	st.push(src);
	rate[src] = make_pair(1, 1);
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		visited[u] = 1;
		if(u==dest) return rate[u];
		for(int i=0; i<adj[u].size(); i++) {
			int v = adj[u][i].first;
			if(!visited[v]) {
				pii r1 = rate[u], r2 = adj[u][i].second;
				st.push(v);
				rate[v] = combine_rate(r1, r2);
			}
		}
	}
	//cannot be determined
	return make_pair(0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i1, i2;
	string s1, s2;
	char c;

	cin.get(c);
	n = 0;
	while(c!='.') {
		int u, v;
		if(c=='!') {
			cin >> i1; cin.get(c); getline(cin, s1, ' ');
			cin.get(c); cin.get(c);
			cin >> i2; cin.get(c); getline(cin, s2);
			
			auto f1 = m.find(s1), f2=m.find(s2);
			if(f1==m.end()) {
				m.insert(make_pair(s1, n));
				u = n; n++; 
			}
			else { u = f1->second; }
			
			if(f2==m.end()) {
				m.insert(make_pair(s2, n));
				v = n; n++;
			}
			else { v = f2->second; }
			adj[u].push_back(make_pair(v, lowest(make_pair(i2, i1))));
			adj[v].push_back(make_pair(u, lowest(make_pair(i1, i2))));
		}
		else {
			cin.get(c); getline(cin, s1, ' ');
			cin.get(c); cin.get(c); getline(cin, s2);
			auto f1=m.find(s1), f2=m.find(s2);

			//cannot be determined
			if(f1==m.end() || f2==m.end()) {
				cout << "? " << s1 << " = ? " << s2 << endl;
				continue;
			}
			
			u = f1->second; v = f2->second;
			pii p = get_rate(u, v);
			if(p.first==0)
				cout << "? " << s1 << " = ? " << s2 << endl;
			else cout << p.second << " " << s1 << " = " 
					<< p.first << " " << s2 << endl;
		}
		cin.get(c);
	}
	

	return 0;
}