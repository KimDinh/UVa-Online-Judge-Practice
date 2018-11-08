#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int F, R, f[15] ,r[15];
    double d[110];
    cin >> F;
    while(F) {
        cin >> R;
        for(int i=0; i<F; i++)
            cin >> f[i];
        for(int i=0; i<R; i++)
            cin >> r[i];
        int k=0;
        for(int i=0; i<F; i++)
            for(int j=0; j<R; j++) {
                d[k] = r[j]*1.0/f[i];
                k++;
            }
        sort(d, d+F*R);
        double M=0;
        for(int i=0; i<F*R-1; i++)
            if(M<(d[i+1]/d[i]))
                M = d[i+1]/d[i];
        cout << fixed << setprecision(2) << M << endl;
        
        cin >> F;
    }
    
    
    return 0;
    
}
