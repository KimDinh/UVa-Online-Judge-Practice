#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

#define ii pair<int, int>

int d[25][25];
ii p[25][25];
string A, B;

void EditDistance(){
	int n = A.length(), m = B.length();
	d[0][0] = 0;
	for(int i=1; i<=n; i++){
		d[i][0] = i;
        p[i][0] = ii(i-1, 0);
    }
	for(int j=1; j<=m; j++){
		d[0][j] = j;
        p[0][j] = ii(0, j-1);
    }
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			int opt[3];
			ii cell[3];
			opt[0] = d[i-1][j-1]+((A[i-1]==B[j-1]) ? 0 : 1); cell[0] = ii(i-1, j-1);
			opt[1] = d[i][j-1]+1; cell[1] = ii(i, j-1);
			opt[2] = d[i-1][j]+1; cell[2] = ii(i-1, j);
			int M = 100, t;
			for(int k=0; k<3; k++)
				if(opt[k]<M){
					M = opt[k];
					t = k;
				}
			d[i][j] = M;
			p[i][j] = cell[t];
		}
}

void backtrack(int x, int y, int& shift){
	if(x==0 && y==0)
		return;
	int px = p[x][y].first, py = p[x][y].second;
    backtrack(px, py, shift);
	if(x==px && y==py+1){
		cout << 'I' << B[y-1];
		if(x+1+shift<10)
			cout << 0;
		cout << x+1+shift;
        shift++;
	}
	else if(x==px+1 && y==py){
		cout << 'D' << A[x-1];
		if(x+shift<10)
			cout << 0;
		cout << x+shift;
        shift--;
	}
	else if(A[x-1]!=B[y-1]){
		cout << 'C' << B[y-1];
		if(x+shift<10)
			cout << 0;
		cout << x+shift;
	}
}

int main(){
    int shift=0;

	while(cin >> A >> B && A[0]!='#'){
   		EditDistance();
        shift = 0;
		backtrack(A.length(), B.length(), shift);
		cout << "E\n";
	}

	return 0;
}