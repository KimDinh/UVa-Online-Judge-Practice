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

int n, m, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
bool visited[50][50][4], bomb[50][50];

struct node{
	int x, y, dir, time;
	node(int a, int b, int d, int t){
		x = a; y = b; dir = d; time = t;
	}
};

bool valid(int x, int y){
	return (x>0 && x<n && y>0 && y<m
		&& !bomb[x-1][y-1] && !bomb[x-1][y] && !bomb[x][y-1] && !bomb[x][y]);
}

int bfs(pair<int, int> start, int d, pair<int, int> end){
	if(!valid(start.first, start.second))
		return -1;
	visited[start.first][start.second][d] = 1;
	queue<node> q;
	q.push(node(start.first, start.second, d, 0));
	while(!q.empty()){
		node cur = q.front();
		if(cur.x==end.first && cur.y==end.second)
			return cur.time;
		q.pop();
		if(!visited[cur.x][cur.y][(cur.dir+1)%4]){
			visited[cur.x][cur.y][(cur.dir+1)%4] = 1;
			q.push(node(cur.x, cur.y, (cur.dir+1)%4, cur.time+1));
		}
		if(!visited[cur.x][cur.y][(cur.dir+3)%4]){
			visited[cur.x][cur.y][(cur.dir+3)%4] = 1;
			q.push(node(cur.x, cur.y, (cur.dir+3)%4, cur.time+1));
		}
		for(int step=1; step<=3; step++){
			int xx = cur.x+dx[cur.dir]*step, yy = cur.y+dy[cur.dir]*step;
			if(!valid(xx, yy))
				break;
			if(!visited[xx][yy][cur.dir]){
				visited[xx][yy][cur.dir] = 1;
				q.push(node(xx, yy, cur.dir, cur.time+1));
			}
		}
	}
	return -1;
}

int main(){
	int x, y;
	string s;
	int d;
	
	while(cin >> n >> m && n){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				for(int k=0; k<4; k++)
					visited[i][j][k] = 0;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				cin >> bomb[i][j];
					
			}
		cin >> x >> y;
		pair<int, int> start(x, y);
		cin >> x >> y;
		pair<int, int> end(x, y);
		cin.ignore();
		getline(cin, s);
		if(s[0]=='n') d = 0;
		else if(s[0]=='e') d = 1;
		else if(s[0]=='s') d = 2;
		else d = 3;
		cout << bfs(start, d, end) << endl;
	}

	return 0;
}