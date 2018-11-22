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
#include <unordered_map>
#include <iomanip>
using namespace std;


int main() {
    int n, a[101][101], M;
    
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if(i>0)
                a[i][j] += a[i-1][j];
            if(j>0)
                a[i][j] += a[i][j-1];
            if(i>0 && j>0)
                a[i][j] -= a[i-1][j-1];
        }
    M = a[0][0];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int x=i; x<n; x++)
                for(int y=j; y<n; y++) {
                    int m = a[x][y];
                    if(i>0)
                        m -= a[i-1][y];
                    if(j>0)
                        m -= a[x][j-1];
                    if(i>0 && j>0)
                        m += a[i-1][j-1];
                    if(m>M)
                        M = m;
                }
    cout << M << endl;
    
    return 0;
}

