#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;

int countbit(int a) {
    int n = 0;
    while(a!=0) {
        n++;
        a-=(a&(-a));
    }
    return n;
}
int main() {
    int n, build, m, t, T=1;
    int customer[30],ca[20],caNo[20];
    int current,Max,best;
    cin >> n >> build;
    while(n) {
        Max=0;
        memset(caNo, 0, 20);
        for(int i=0; i<n; i++)
            cin >> customer[i];
        cin >> m;
        for(int i=0; i<m; i++) {
            cin >> t;
            int p;
            for(int j=0; j<t; j++) {
                cin >> p;
                caNo[i] |= 1<<(p-1);
            }
            cin >> ca[i];
        }
        for(int k=1; k<(1<<n); k++)
            if(countbit(k)==build) {
                current = 0;
                for(int i=0; i<n; i++)
                    if(k&(1<<i))
                        current += customer[i];
                for(int i=0; i<m; i++) {
                    int comtow = k&caNo[i];
                    if(comtow>1)
                        current -= (countbit(comtow)-1)*ca[i];
                }
                if(current>Max){
                    Max = current;
                    best = k;
                }
            }
        cout << "Case Number  " << T << endl;
        cout << "Number of Customers: " << Max << endl;
        cout << "Locations recommended:";
        for(int i=0; i<n; i++)
            if(best&(1<<i))
                cout << " " << i+1;
        cout << endl << endl;
        
        cin >> n >> build;
        T++;
    }
    
    return 0;
}
