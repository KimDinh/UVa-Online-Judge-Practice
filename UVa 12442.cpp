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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, n, send[50001], u, v;
	vector<int> reach;
	vector<bool> visited;
	cin >> T;
	for(int c=1; c<=T; c++) {
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> u >> v;
			send[u] = v;
		}
		visited.assign(n+1, 0);
		reach.assign(n+1, 0);
		for(int u=1; u<=n; u++)
			//pick an unvisited vertex and traverse
			if(!visited[u]) {
				int cur = u, count = 0;
				//stop when we complete a cycle
				while(!visited[cur]) {
					visited[cur] = 1;
					count++;
					cur = send[cur];
				}
				//we originally start at a vertex in the cycle
				if(cur==u) {
					reach[u] = count;
					cur = send[u];
					while(cur!=u) {
						reach[cur] = count;
						cur = send[cur];
					}
				}
				//we originally start at a vertex outside the cycle
				else {
					int cur2 = u;
					//the cycle is visited for the 1st time
					if(reach[cur]==0) {
						while(cur2!=cur) {
							reach[cur2] = count;
							count--;
							cur2 = send[cur2];
						}
						reach[cur] = count;
						cur2 = send[cur];
						while(cur2!=cur) {
							reach[cur2] = count;
							cur2 = send[cur2];
						}
					}
					//the cycle has been visited before
					else {
						reach[u] = count + reach[cur];
						while(send[cur2]!=cur) {
							reach[send[cur2]] = reach[cur2]-1;
							cur2 = send[cur2];
						}
					}
				}
			}
		int ans, m=0;
		for(int i=1; i<=n; i++) 
			if(reach[i]>m) {
				m = reach[i];
				ans = i;
			}
		cout << "Case " << c << ": " << ans << endl;
	}

	return 0;
}