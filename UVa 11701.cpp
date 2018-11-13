#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <iomanip>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    while(s!="END") {
        if(s=="0" || s=="1") {
            cout << "MEMBER\n";
            getline(cin, s);
            continue;
        }
        int decimal = s.substr(2).length();
        int x = atoi((s.substr(2)).c_str());
        double t = x*1.0;
        for(int i=0; i<decimal; i++)
            t/=10;
        int i=0;
        while(i<=6) {
            t*=3;
            if(t>1) {
                int d = (int)t;
                t-=d;
                if(d==1) {
                    cout << "NON-MEMBER\n";
                    break;
                }
            }
            i++;
        }
        if(i>6)
            cout << "MEMBER\n";
        getline(cin, s);
    }
    
    return 0;
}
