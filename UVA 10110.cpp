#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    unsigned int n;
    int x;
    double N;
    
    cin >> n;
    if(n==0)
        cout << "no" << endl;
    else {
        while(n!=0){
            if(n==1)
                cout << "yes" << endl;
            else {
                N = sqrt(n);
                x=2;
                while(x<N) {
                    x++;
                }
                if(x==N)
                    cout << "yes" << endl;
                else cout << "no" << endl;
            }
            cin >> n;
        }
    }
    
    return 0;
}
