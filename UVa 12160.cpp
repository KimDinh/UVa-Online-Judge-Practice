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

int L, U, R, dist[10000];
vector<int> button;

void bfs(){
	for(int i=0; i<10000; i++)
		dist[i] = 1e8;
	dist[L] = 0;
	queue<int> q;
	q.push(L);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x==U)
			return;
		for(int i=0; i<button.size(); i++){
			int y = (x+button[i])%10000;
			if(dist[y]==1e8){
				dist[y] = dist[x]+1;
				q.push(y);
			}
		}
	}
}

int main(){
	int x, cases=1;

	while(cin >> L >> U >> R && (L || U || R)){
		button.clear();
		for(int i=0; i<R; i++){
			cin >> x;
			button.push_back(x);
		}
		bfs();
		cout << "Case " << cases++ << ": ";
		if(dist[U]==1e8)
			cout << "Permanently Locked\n";
		else cout << dist[U] << endl;
	}

	return 0;
}