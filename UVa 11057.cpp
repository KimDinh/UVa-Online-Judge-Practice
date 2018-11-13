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
    unordered_set<int> set;
    int N, M, diff, a[10000];
    
    cin >> N;
    
    while(!cin.eof()) {
        for(int i=0; i<N; i++)
            cin >> a[i];
        cin >> M;
        diff = M;
        for(int i=0; i<N; i++) {
            if(set.find(M-a[i])==set.end())
                set.insert(a[i]);
            else if(diff>abs(M-2*a[i]))
                diff = abs(M-2*a[i]);
        }
        cout << "Peter should buy books whose prices are " << (M-diff)/2 << " and " << (M+diff)/2 << ".\n\n";
        set.clear();
        cin >> N;
    }
    
    return 0;
}
