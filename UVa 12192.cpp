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
    vector<vector<int>> a;
    int N, M, Q, U, L, x, max;
    
    cin >> N >> M;
    
    while(N>0) {
        a.resize(500);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++) {
                cin >> x;
                a[i].push_back(x);
            }
        cin >> Q;
        while(Q--) {
            max = 0;
            cin >> L >> U;
            for(int i=0; i<N; i++) {
                auto find = lower_bound(a[i].begin(), a[i].end(), L);
                if(find==a[i].end())
                    continue;
                int size=0;
                while(i+size<N && find-a[i].begin()+size<M && a[i+size][find-a[i].begin()+size]<=U)
                    size++;
                if(size>max)
                    max = size;
            }
            cout << max << endl;
        }
        cout << "-\n";
        a.clear();
        cin >> N >> M;
    }
    
    return 0;
}
