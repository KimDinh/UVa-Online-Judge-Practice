#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

long long poly(int c[], int degree, int n) {
    if(degree==0)
        return c[0];
    long long p=1;
    for(int i=0; i<degree; i++)
        p *= n;
    return c[degree]*p + poly(c, degree-1, n);
}

int main() {
    int c[25], d, k, C ,i;
    cin >> C;
    while(C--) {
        cin >> i;
        for(int j=0; j<=i; j++)
            cin >> c[j];
        cin >> d >> k;
        int j=0, S=0;
        while(k>S) {
            j++;
            S += j*d;
        }
        cout << poly(c, i, j) << endl;
    }
    
    
    return 0;
}
