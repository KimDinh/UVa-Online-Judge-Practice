#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct Pair{
    int value, index;
};

bool ComparePair(Pair p1, Pair p2) {
    return (p1.value < p2.value);
}

int main() {
    int n;
    Pair a[10005];
    cin >> n;
    cin.ignore();
    while(n) {
        for(int i=0; i<n; i++) {
            cin >> a[i].value;
            a[i].index = i;
        }
        sort(a, a+n, ComparePair);
        int k=1;
        while(k<=(n-1)/2) {
            int i;
            for(i=0; i<=n-1-2*k; i++)
                if((a[i].index-a[i+k].index)*(a[i+k].index-a[i+2*k].index)>0)
                    break;
            if(i<=n-1-2*k)
                break;
            k++;
        }
        if(k<=(n-1)/2)
            cout << "no\n";
        else cout << "yes\n";
        
        cin >> n;
        cin.ignore();
    }
    
    return 0;
    
}
