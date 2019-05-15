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
	int n, size, u, v, indegree[100];
	char word[26], c;
	string s, w;
	vector<int> adj[100];
	bool visited[100];
	unordered_map<string, int> wordtoint;
	vector<string> inttoword, ans;
	queue<int> q;

	cin >> n;
	while(n){
		size = 0;
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<n; i++)
		    indegree[i] = 0;
		cin.ignore();
		for(int i=0; i<n; i++){
			getline(cin, s);
			w = "";
			int j=0;
			while(j<s.length() && s[j]!=' ')
				w += s[j++];
			auto f=wordtoint.find(w);
			if(f!=wordtoint.end())
				u = f->second;
			else {
				u = size;
				wordtoint.insert(make_pair(w, size++));
				inttoword.push_back(w);
			}
			w = "";
			while(++j<s.length()){
				if(s[j]!=' '){
					w += s[j];
					if(j+1<s.length())
					continue;
				}
				f = wordtoint.find(w);
				if(f!=wordtoint.end())
					v = f->second;
				else{
					v = size;
					wordtoint.insert(make_pair(w, size++));
					inttoword.push_back(w);
				}
				adj[u].push_back(v);
				indegree[v]++;
				w = "";
			}
		}

		for(int i=0; i<n; i++)
			if(indegree[i]==0)
				q.push(i);
		while(!q.empty()){
			u = q.front();
			visited[u] = 1;
			q.pop();
			for(int i=0; i<adj[u].size(); i++){
				v = adj[u][i];
				if(--indegree[v]==0)
					q.push(v);
			}
		}

		for(int i=0; i<n; i++)
			if(!visited[i])
				ans.push_back(inttoword[i]);
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl << ans[0];
		for(int i=1; i<ans.size(); i++)
			cout << " " << ans[i];
		cout << endl;
		for(int i=0; i<n; i++)
			adj[i].clear();
		wordtoint.clear();
		inttoword.clear();
		ans.clear();

		cin >> n;
	}

	return 0;
}
