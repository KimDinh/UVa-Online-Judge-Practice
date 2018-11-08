#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m, a[1000], cases=0;
    cin >> n;
    while(n) {
        cases++;
        for(int i=0; i<n; i++)
            cin >> a[i];
        cin >> m;
        int query, temp;
        cout << "Case " << cases << ":" << endl;
        for(int i=0; i<m; i++) {
            cin >> query;
            for(int j=0; j<n-1; j++) {
                for(int k=j+1; k<n; k++) {
                    if(j==0 && k==1)
                        temp = a[j] + a[k];
                    else {
                        if(abs(query-temp)>abs(query-a[j]-a[k]))
                            temp = a[j] + a[k];
                        if(query-temp==0)
                            break;
                    }
                }
                if(query-temp==0)
                    break;
            }
            cout << "Closest sum to " << query << " is " << temp << ".\n";
        }
        cin >> n;
    }
    
    return 0;
}
