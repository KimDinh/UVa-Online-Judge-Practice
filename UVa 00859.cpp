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

struct point{
	int x, y, step;
	point(int a, int b, int c){
		x = a; y = b; step = c;
	}
	bool operator < ( const point& p ) const {
		return x > p.x || ( x == p.x && y < p.y );
	}
};

int L, C;
bool piece[10001][10001];
vector<point> p;
int dx1[]={ 0, 1, 0}, dx2[]={ 2, 2, 2,  0, 0};
int dy1[]={-1, 0, 1}, dy2[]={-2, 0, 2, -2, 2};

bool valid(int x, int y){
	return (x>=1 && x<=L && y>=1 && y<=C);
}

void bfs(int x, int y){
	p.clear();
	p.push_back(point(x, y, 0));
	for(int i=0; i<p.size(); i++){
		x = p[i].x; y = p[i].y;
		int step = p[i].step; 
		for(int j=0; j<5; j++)
			if(valid(x+dx2[j], y+dy2[j]) && !piece[x+dx2[j]][y+dy2[j]] 
				&& piece[x+dx2[j]/2][y+dy2[j]/2]) {
				piece[x+dx2[j]][y+dy2[j]] = 1;
				p.push_back(point(x+dx2[j], y+dy2[j], step+1));
			}
	}
	x = p[0].x; y = p[0].y;
	for(int i=0; i<3; i++)
		if(valid(x+dx1[i], y+dy1[i]) && !piece[x+dx1[i]][y+dy1[i]]){
			piece[x+dx1[i]][y+dy1[i]] = 1;
			p.push_back(point(x+dx1[i], y+dy1[i], 1));
		}
}

int main(){
	int x, y;

	cin >> L >> C;
	while(true){
		memset(piece, 0, sizeof(piece));
		for(int i=0; i<4*C; i++){
			cin >> x >> y;
			piece[x][y] = 1;
		}
		cin >> x >> y;
		bfs(x, y);
		sort(p.begin()+1, p.end());
		for(int i=1; i<p.size(); i++)
			cout << p[i].x << " " << p[i].y << " " << p[i].step << endl;
		if(cin >> L >> C)
			cout << endl;
		else break;
	}

	return 0;
}