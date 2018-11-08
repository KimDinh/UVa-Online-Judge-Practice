#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int a[502], first=0;
        for(int i=0; i<502; i++)
            a[i] = 0;
        for(int i=0; i<s1.length(); i++)
            for(int j=0; j<s2.length(); j++)
                a[i+j] += (s1[i]-'0')*(s2[j]-'0');
        for(int i=0; i<501; i++) {
            a[i+1] += a[i]/10;
            a[i] %= 10;
            if(a[i+1]!=0)
                first = i+1;
        }
        for(int i=first; i>=0; i--)
            cout << a[i];
        cout << endl;
        
    }
    
    return 0;
}
