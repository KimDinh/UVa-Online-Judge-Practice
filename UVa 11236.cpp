#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    int a, b, c, d;
    long long p, s;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    for (a = 1; a+a+a+a <= 2000; a++)
        for (b = a; a+b+b+b <= 2000; b++)
            for (c = b; a+b+c+c <= 2000; c++) {
                p = (long long) a * b * c;
                s = a + b + c;
                if (p <= 1000000)
                    continue;
                if ((s * 1000000) % (p - 1000000))
                    continue;
                d = (s * 1000000) / (p - 1000000);
                s += d;
                if (s > 2000 || d < c)   continue;
                cout << a*1.0/100 << " " << b*1.0/100 << " " << c*1.0/100 << " " << d*1.0/100 << endl;
            }
    return 0;
}
