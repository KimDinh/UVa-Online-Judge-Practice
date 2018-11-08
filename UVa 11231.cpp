#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    while(n!=0) {
        int evencolumn, oddcolumn, count=0;
        if(c==0) {
            if(m%2==1) {
                evencolumn = (m-7)/2;
                oddcolumn = (m-7)/2;
            }
            else {
                evencolumn = (m-8)/2;
                oddcolumn = (m-6)/2;
            }
            for(int i=0; i<=n-8; i++) {
                if(i%2==0)
                    count += evencolumn;
                else count += oddcolumn;
            }
        }
        else {
            if(m%2==1) {
                evencolumn = (m-7)/2;
                oddcolumn = (m-7)/2;
            }
            else {
                evencolumn = (m-6)/2;
                oddcolumn = (m-8)/2;
            }
            for(int i=0; i<=n-8; i++) {
                if(i%2==0)
                    count += evencolumn;
                else count += oddcolumn;
            }
        }
        cout << count << endl;
        cin >> n >> m >> c;
    }
}
