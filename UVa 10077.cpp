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

struct Frac{
    int num, den;
    double val() {return num*1.0/den;}
};

int main() {
    int m, n;
    string s="";
    Frac left, right, mid;
    cin >> m >> n;
    while (m!=1 || n!=1) {
        left.num = right.den = 0;
        left.den = right.num = 1;
        while(true) {
            mid.num = left.num+right.num;
            mid.den = left.den+right.den;
            if(mid.val()==m*1.0/n) {
                cout << s << endl;
                break;
            }
            else if(m*1.0/n<mid.val()) {
                s.append("L");
                right.num = mid.num;
                right.den = mid.den;
            }
            else {
                s.append("R");
                left.num = mid.num;
                left.den = mid.den;
            }
        }
        s = "";
        cin >> m >> n;
    }
    
    return 0;
}
