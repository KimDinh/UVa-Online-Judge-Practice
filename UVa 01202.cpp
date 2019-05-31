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

int m, n, dist[201][201];
double f1, f2;
set<pair<pii, pii>> wall, door;
int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};

bool valid(int x, int y){
	return (x>=0 && y>=0 && x<=200 && y<=200);
}

void Dijkstra(){
	for(int i=0; i<201; i++)
			for(int j=0; j<201; j++)
				dist[i][j] = 1e8;
	dist[0][0] = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	q.push(make_pair(0, pii(0, 0)));
	while(!q.empty()){
		int d = q.top().first, x1 = q.top().second.first, y1 = q.top().second.second;
		q.pop();
		if(d>dist[x1][y1])
			continue;
		for(int i=0; i<4; i++){
			int x2 = x1+dx[i], y2 = y1+dy[i];
			if(valid(x2, y2)) {
			    auto findwall = wall.find(make_pair(pii(x1, y1), pii(x2, y2)));
			    auto finddoor = door.find(make_pair(pii(x1, y1), pii(x2, y2)));
				if(finddoor!=door.end())
				    d = 1;
				else {
				    if(findwall!=wall.end())
				        d = 1e8;
				    else d = 0;
				}
				if(dist[x2][y2]>dist[x1][y1]+d){
					dist[x2][y2] = dist[x1][y1]+d;
					q.push(make_pair(dist[x2][y2], pii(x2, y2)));
				}
			}
		}
	}
}

int main(){
	int x, y, d, t;

	while(cin >> m >> n && m!=-1){
		wall.clear();
		door.clear();
		for(int i=0; i<m; i++){
			cin >> x >> y >> d >> t;
			for(int j=0; j<t; j++){
				if(d==0){
					wall.insert(make_pair(pii(x+j, y), pii(x+j, y-1)));
				    wall.insert(make_pair(pii(x+j, y-1), pii(x+j, y)));
				}
				else {
				    wall.insert(make_pair(pii(x, y+j), pii(x-1, y+j)));
				    wall.insert(make_pair(pii(x-1, y+j), pii(x, y+j)));
				}
			}
		}
		for(int i=0; i<n; i++){
			cin >> x >> y >> d;
			if(d==0){
				door.insert(make_pair(pii(x, y), pii(x, y-1)));
				door.insert(make_pair(pii(x, y-1), pii(x, y)));
			}
			else {
			    door.insert(make_pair(pii(x, y), pii(x-1, y)));
			    door.insert(make_pair(pii(x-1, y), pii(x, y)));
			}
		}
		cin >> f1 >> f2;
    Dijkstra();
    if(!valid(int(f1), int(f2)))
      cout << "0\n";
    else if(dist[int(f1)][int(f2)]==1e8)
      cout << "-1\n";
    else cout << dist[int(f1)][int(f2)] << endl;
	}

	return 0;
}