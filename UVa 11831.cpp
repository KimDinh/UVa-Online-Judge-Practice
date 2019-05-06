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


int di[]={-1, 0, 1, 0};
int dj[]={0, 1, 0, -1};
char a[101][101];
int n, m, l, d;
string s;
pair<int, int> pos;

bool valid(int i, int j) {
	return (i>=0 && i<n && j>=0 && j<m && a[i][j]!='#');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l;
	cin.ignore();
	while(n!=0) {
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				cin >> a[i][j];
				if(a[i][j]=='N'){
					d = 0; pos.first = i; pos.second = j;
				}
				else if(a[i][j]=='L'){
					d = 1; pos.first = i; pos.second = j;
				}
				else if(a[i][j]=='S'){
					d = 2; pos.first = i; pos.second = j;
				} 
				else if(a[i][j]=='O'){
					d = 3; pos.first = i; pos.second = j;
				}
			}
		cin.ignore();
		getline(cin, s);
		int count = 0;
		for(int k=0; k<l; k++) {
			if(s[k]=='D') { d++; d%=4; }
			else if(s[k]=='E') { d+=3; d%=4; }
			else {
				if(!valid(pos.first+di[d], pos.second+dj[d]))
					continue;
				pos.first += di[d];
				pos.second += dj[d];
				if(a[pos.first][pos.second]=='*') {
					count++; a[pos.first][pos.second] = '.';
				}
			}
		}
		cout << count << endl;
		cin >> n >> m >> l;
		cin.ignore();
	}
	
	return 0;
}