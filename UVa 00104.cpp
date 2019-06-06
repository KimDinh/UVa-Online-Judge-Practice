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

int main(){
    int n, p[21][21][21];
    double adj[21][21][21];
	bool found;

	while(cin >> n){
        memset(adj, 0, sizeof(adj));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				p[i][j][1] = i;
				if(i==j)
					adj[i][j][1] = 1.0;
				else cin >> adj[i][j][1];
			}
		//modified Floyd Warshall's algorithm
		for(int l=2; l<=n; l++)
			for(int k=1; k<=n; k++)
				for(int i=1; i<=n; i++)
					for(int j=1; j<=n; j++){
						double tmp = adj[i][k][l-1]*adj[k][j][1];
						if(adj[i][j][l]<tmp){
							adj[i][j][l] = tmp;
							p[i][j][l] = k;
						}
					}
		found = 0;
		for(int l=2; l<=n; l++){
			for(int i=1; i<=n; i++){
				if(adj[i][i][l]>1.01){
					stack<int> path;
					int length = l, j = p[i][i][length--];
					while(length>0){
						path.push(j);
						j = p[i][j][length--];
					}
					cout << i << " ";
					while(!path.empty()){
						cout << path.top() << " ";
						path.pop();
					}
					cout << i << endl;
					found = 1;
					break;
				}
            }
			if(found) break;
		}
		if(!found)
			cout << "no arbitrage sequence exists\n";
	}

	return 0;
}