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
	string s;
	int code[80], power[]={1, 2, 4, 8, 16, 32, 64, 128};
	int N;

	cin >> N;
	while(N--){
		memset(code, 0, sizeof(code));
		cin >> s;
		for(int i=0; i<8; i++){
			cin >> s;
			for(int j=1; j<s.length()-1; j++)
				if(s[j]=='\\')
					code[j-1] += power[i];
		}
		cin >> s;
        cin.get();
		for(int i=0; i<s.length()-2; i++)
			cout << char(code[i]);
		cout << "\n";
	}

	return 0;
}