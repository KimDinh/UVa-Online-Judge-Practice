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
    string s="";
    int T, i;
    vector<long long> l;
    
    l.push_back(0);
    for(int i=1; i<=100000; i++) {
        s += to_string(i);
        l.push_back(l[i-1]+s.length());
    }
    
    cin >> T;
    while(T--) {
        cin >> i;
        auto find = lower_bound(l.begin(), l.end(), i);
        cout << s[i-*(find-1)-1] << endl;
    }
    
    return 0;
}
