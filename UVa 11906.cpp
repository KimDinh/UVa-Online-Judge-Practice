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

int R, C, M, N, W, x, y, even, odd;
bool visited[101][101], water[101][101];
set<pii> jump;

//set of all possible jumps
void all_jump() {
	jump.clear();
	jump.insert(make_pair(M, N));
	jump.insert(make_pair(M, -N));
	jump.insert(make_pair(-M, N));
	jump.insert(make_pair(-M, -N));
	jump.insert(make_pair(N, M));
	jump.insert(make_pair(N, -M));
	jump.insert(make_pair(-N, M));
	jump.insert(make_pair(-N, -M));
}

bool valid(int x, int y){
	return (x>=0 && x<R && y>=0 && y<C && !water[x][y]);
}

//count the number of possible jumps from the cell and mark the cell
bool mark(int x, int y){
	int c=0;
	for(auto i=jump.begin(); i!=jump.end(); i++)
		if(valid(x+i->first, y+i->second))
			c++;
	return c%2;
}

//BFS to make the tour
void make_tour() {
	queue<pii> q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while(!q.empty()) {
		int x=q.front().first, y=q.front().second;
		q.pop();
		//increment even or odd based on the cell is marked even or odd
		if(mark(x, y))
			odd++;
		else even++;
		for(auto i=jump.begin(); i!=jump.end(); i++) {
			int xx=x+i->first, yy=y+i->second;
			if(valid(xx, yy) && !visited[xx][yy]) {
				visited[xx][yy] = 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main() {
	int T;

	cin >> T;
	for(int i=1; i<=T; i++) {
		cin >> R >> C >> M >> N >> W;
		memset(visited, 0, sizeof(visited));
		memset(water, 0, sizeof(water));
		for(int j=0; j<W; j++) {
			cin >> x >> y;
			water[x][y] = 1;
		}
		all_jump();
		even = odd = 0;
		make_tour();
		cout << "Case " << i << ": " << even << " " << odd << endl;
	}

	return 0;
}