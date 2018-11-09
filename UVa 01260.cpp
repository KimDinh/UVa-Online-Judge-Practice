#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, a[1000], S, t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        S = 0;
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(a[j]<=a[i])
                    S++;
        cout << S << endl;
    }
    
    return 0;
}
