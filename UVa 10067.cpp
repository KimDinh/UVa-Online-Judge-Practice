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

int dist[10000];
int turn[9]={-1, 1, -10, 10, -100, 100, -1000, 1000, 10000};

int config_to_int(int a, int b, int c, int d){
    return 1000*a+100*b+10*c+d;
}

int bfs(int start, int end){
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u==end) return dist[u];
		for(int i=0; i<8; i++){
		    //calculate the new state
		    int j;
		    if(i>=6) j = 8;
		    else if(i>=4) j =7;
		    else if(i>=2) j = 5;
		    else j = 3;
			int p = u/turn[j], r = u%turn[j];
			int v = p*turn[j]+(r+turn[i]+turn[j])%turn[j];
			
			if(dist[v]==1e8){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	return -1;
}

int main(){
	int T, n, x, y, z, t;

    cin >> T;
	while(T--){
		cin >> x >> y >> z >> t;
		int start = config_to_int(x, y, z, t);
		cin >> x >> y >> z >> t;
		int end = config_to_int(x, y, z, t);
		for(int i=0; i<10000; i++)
			dist[i] = 1e8;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x >> y >> z >> t;
			dist[config_to_int(x, y, z, t)] = -1;
		}
		cout << bfs(start, end) << endl;
	}

	return 0;
}