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
#include <stack>
#include <iomanip>
using namespace std;

int T, n, m, x, y;
char a[101][101];
bool visited[100][100];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y) {
	return (x>=0 && x<n && y>=0 && y<m && a[x][y]=='W' && !visited[x][y]);
}

int connected(int x, int y) {
	int c=1;
	visited[x][y] = 1;
	for(int i=0; i<8; i++)
			if(valid(x+dx[i], y+dy[i]))
				c += connected(x+dx[i], y+dy[i]);
	return c;
}


int main() {
	string s;
	cin >> T;
	getline(cin, s);
	getline(cin, s);
	for(int i=1; i<=T; i++){
		getline(cin, s);
		m = s.length();
		n = 0;
		while(s[0]=='L' || s[0]=='W') {
			strcpy(a[n++], s.c_str());
			getline(cin, s);
		}
		while(true) {
			x = s[0]-'0'-1; y = s[2]-'0'-1;
			memset(visited, 0, sizeof(visited));
			if(a[x][y]=='L')
				cout << 0 << endl;
			else cout << connected(x, y) << endl;
			if(!getline(cin, s) || s.empty())
				break;
		}
		if(i<T)
			cout << endl;
}


	return 0;
}