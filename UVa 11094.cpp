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

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, 1, -1};
int m, n, x, y;
char a[22][22];
bool visited[21][21];
vector<pii> land;
stack<pii> s;

bool valid(int i, int j){
	return (i>=0 && i<m && j>=0 && j<n && a[i][j]==a[x][y] && !visited[i][j]);
}

int main() {

	while(cin >> m >> n) {
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cin >> a[i][j];
			
		cin >> x >> y;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				if(a[i][j]==a[x][y])
					land.push_back(make_pair(i, j));

		memset(visited, 0, sizeof(visited));
		//DFS to mark(eliminate) all land regions connected to cell (x, y)
		s.push(make_pair(x, y));
		visited[x][y] = 1;
		while(!s.empty()) {
			int x1=s.top().first, y1=s.top().second;
			s.pop();
			for(int i=0; i<4; i++) {
				int x2=x1+dx[i], y2=(y1+dy[i]+n)%n;
				if(valid(x2, y2)) {
					visited[x2][y2] = 1;
					s.push(make_pair(x2, y2));
				}
			}
		}

		int maxsize=0, count;
		//DFS to find and calculate size of other connected components
		for(int i=0; i<land.size(); i++){
			int xx=land[i].first, yy=land[i].second;
			if(!visited[xx][yy]) {
				count = 0;
				visited[xx][yy] = 1;
				s.push(make_pair(xx, yy));
				while(!s.empty()) {
					int x1=s.top().first, y1=s.top().second;
					s.pop();
					count++;
					for(int j=0; j<4; j++) {
						int x2=x1+dx[j], y2=(y1+dy[j]+n)%n;
						if(valid(x2, y2)) {
							visited[x2][y2] = 1;
							s.push(make_pair(x2, y2));
						}
					}
				}
				maxsize = max(maxsize, count);
			}
		}
		cout << maxsize << endl;
		land.clear();
	}

	return 0;
}