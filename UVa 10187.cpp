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

#define ii pair<int, int>
#define sii pair<string, ii>

int E;
map<string, vector<sii>> route;
map<string, ii> blood_arr;
string start, finish;
bool reach;

bool valid(int dep, int arr){
	return ((dep<arr && ((dep>=18 && arr>=18) || (dep<=6 && arr<=6))) || (dep>=18 && arr<=6));
}

bool newblood(int arr, int dep){
	return !((arr<=dep && (arr>=18 || dep<=6)) || (arr>=18 && dep<=6));
}

bool operator > (sii p1, sii p2){
	ii ii1=p1.second, ii2=p2.second;
	if(ii1.first!=ii2.first) return (ii1.first>ii2.first);
	if((ii1.second>=18 && ii2.second>=18) || (ii1.second<=6 && ii2.second<=6))
		return (ii1.second>ii2.second);
	return (ii1.second<=6);
}

struct Comp{
	bool operator()(sii p1, sii p2){
		return (p1>p2);
	}
};

void Dijkstra(){
	priority_queue<sii, vector<sii>, Comp> q;
	blood_arr[start] = ii(0, 18);
	q.push(sii(start, ii(0, 18)));
	while(!q.empty()){
		sii cur = q.top();
		string s1 = cur.first;
		int arr = cur.second.second;
		q.pop();
		if(cur>sii(s1, blood_arr[s1]))
			continue;
		if(s1==finish){
			reach = 1;
			return;
		}
		for(int i=0; i<route[s1].size(); i++){
			sii next = route[s1][i];
			string s2 = next.first;
			int dep = next.second.first;
			int l = cur.second.first+newblood(arr, dep);
			if(sii(s2, blood_arr[s2])>sii(s2, ii(l, next.second.second))){
				blood_arr[s2] = ii(l, next.second.second);
				q.push(sii(s2, ii(l, next.second.second)));
			}
		}
	}
}

int main(){
	int T, dep, arr;
	string s1, s2;

	cin >> T;
	for(int c=1; c<=T; c++){
		cin >> E;
		route.clear();
		blood_arr.clear();
		for(int i=0; i<E; i++){
			cin >> s1 >> s2 >> dep >> arr;
			arr += dep;
			if(valid(dep%24, arr%24)){
				route[s1].push_back(sii(s2, ii(dep%24, arr%24)));
				blood_arr[s1] = ii(1e8, 1e8);
        		blood_arr[s2] = ii(1e8, 1e8);
			}
		}

		cin >> start >> finish;
		reach = 0;
		Dijkstra();
		cout << "Test Case " << c << ".\n";
		if(!route.count(start) || !blood_arr.count(finish) || !reach)
      		cout << "There is no route Vladimir can take.\n";
    	else cout << "Vladimir needs " << blood_arr[finish].first << " litre(s) of blood.\n";
  	}
	return 0;
}