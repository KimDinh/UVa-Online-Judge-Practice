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

#define ii pair<int, int>
#define INF 1e9

int n, m, nodes, s, t, dist[50110], totaldrink, available[50000];
vector<ii> edge, monkey_time;
vector<int> adj[50110], flow, cap, endpoints, units, interval_cur;
unordered_set<int> point;
unordered_map<int, int> interval_pos;

void AddEdge(int u, int v, int c){
	edge.push_back(ii(u, v));
	edge.push_back(ii(v, u));
	adj[u].push_back(edge.size()-2);
	adj[v].push_back(edge.size()-1);
	cap.push_back(c); cap.push_back(0);
	flow.push_back(0); flow.push_back(0);
}

bool Dinic_BFS(){
	for(int i=0; i<nodes; i++)
		dist[i] = INF;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++){
			int e = adj[u][i], v = edge[e].second;
			if(dist[v]==INF && flow[e]<cap[e]){
				q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
	return (dist[t]!=INF);
}

int Dinic_DFS(int s, int t, int f){
	if(s==t) return f;
	int push = 0;
	for(int i=0; i<adj[s].size(); i++){
		if(push>=f) break;
		int e = adj[s][i], v = edge[e].second;
		if(flow[e]<cap[e] && dist[v]==dist[s]+1){
			int current_push = Dinic_DFS(v, t, min(f-push, cap[e]-flow[e]));
			push += current_push;
			flow[e] += current_push;
			flow[e^1] -= current_push;
		}
	}
	return push;
}

int Dinic(){
	int f=0;
	while(Dinic_BFS()){
		f += Dinic_DFS(s, t, INF);
	}
	return f;
}

vector<ii> merge_time(vector<ii> time){
    vector<ii> new_time;
    int i=0, l, r;
    while(i<time.size()){
        l=time[i].first; r=time[i].second;
        while(i<time.size()-1 && r==time[i+1].first){
            r = time[++i].second;
        }
        new_time.push_back(ii(l, r));
        i++;
    }
    return new_time;
}

int main(){
	int v, a, b, cases=1;

	while(cin >> n >> m && n){
		s = 0; totaldrink = 0;
		edge.clear(); units.clear(); monkey_time.clear(); interval_cur.clear();
        endpoints.clear(); point.clear(); flow.clear(); cap.clear();
		for(int i=0; i<50110; i++)
			adj[i].clear();
		for(int i=1; i<=n; i++){
			cin >> v >> a >> b;
			totaldrink += v;
			units.push_back(v);
			AddEdge(s, i, v);
			point.insert(a);
			point.insert(b);
			monkey_time.push_back(ii(a, b));
		}
		for(auto& x : point)
			endpoints.push_back(x);
		sort(endpoints.begin(), endpoints.end());
		for(int i=0; i<endpoints.size(); i++)
			interval_pos[endpoints[i]] = i;
		for(int i=0; i<n; i++){
			int start = interval_pos[monkey_time[i].first];
			int finish = interval_pos[monkey_time[i].second];
			for(int j=start; j<finish; j++){
				a = endpoints[j]; b = endpoints[j+1];
				AddEdge(i+1, n+j+1, b-a);
			}
		}
		t = n+endpoints.size(); nodes = t+1;
		for(int i=0; i<endpoints.size()-1; i++){
			a = endpoints[i]; b = endpoints[i+1];
			AddEdge(n+i+1, t, m*(b-a));
		}
		cout << "Case " << cases++ << ": ";
		if(Dinic()!=totaldrink){
			cout << "No\n";
			continue;
		}
        cout << "Yes\n";
		for(int i=0; i<endpoints.size()-1; i++)
			interval_cur.push_back(endpoints[i]);
		vector<ii> time;
		for(int i=1; i<=n; i++){
			int unit = units[i-1];
			time.clear();
			for(int j=0; j<adj[i].size(); j++){
				int e = adj[i][j], w = edge[e].second;
				if(w==s || flow[e]==0)
					continue;
				int drink = flow[e], cur = interval_cur[w-n-1];
				int a = endpoints[w-n-1], b = endpoints[w-n];
				if(cur+drink<=b){
					time.push_back(ii(cur, cur+drink));
					cur += drink;
					if(cur==b)
						cur = a;
				}
				else{
					time.push_back(ii(a, a+drink-b+cur));
					time.push_back(ii(cur, b));
					cur += a+drink-b;
				}
				interval_cur[w-n-1] = cur;
				unit -= drink;
				if(unit==0)
					break;
			}
			vector<ii> new_time = merge_time(time);
            cout << new_time.size();
			for(int j=0; j<new_time.size(); j++)
				cout << " (" << new_time[j].first << "," << new_time[j].second << ")";
			cout << "\n";
		}

	}

	return 0;
}