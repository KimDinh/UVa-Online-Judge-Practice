#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct Fraction{
    long x,y;
};

int main() {
    Fraction frac[10000];
    int k;
    cin >> k;
    while(!cin.eof()) {
        int count=0;
        long K = k*k;
        for(int i=1; i<=k; i++)
            if(K%i==0) {
                frac[count].y = i+k;
                frac[count].x = K/i+k;
                count++;
            }
        cout << count << endl;
        for(int i=0; i<count; i++)
            cout << "1/" << k << " = 1/" << frac[i].x << " + 1/" << frac[i].y << endl;
        cin >> k;
    }
    
    return 0;
}
