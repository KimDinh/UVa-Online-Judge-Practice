#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> state(256);
    int serial=0 ,Q, first, last;
    string s;
    char c;
    
    cin.get(c);
    while(c!='\n') {
        state[c].push_back(serial);
        serial++;
        cin.get(c);
    }
    
    cin >> Q;
    cin.ignore();
    while(Q--) {
        serial = 0;
        getline(cin,s);
        int l = s.length(), i;
        for(i=0; i<l; i++) {
            auto find = lower_bound(state[s[i]].begin(), state[s[i]].end(), serial);
            if(find==state[s[i]].end())
                break;
            if(i==0)
                first = *find;
            if(i==l-1)
                last = *find;
            serial = *find + 1;
        }
        if(i<l)
            cout << "Not matched" << endl;
        else cout << "Matched " << first << " " << last << endl;
    }
    
    return 0;
}
