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
    int A, B, C, n;
    bool found;
    cin >> n;
    while(n--) {
        cin >> A >> B >> C;
        found = false;
        int x, y;
        for(x=-100; x<=100; x++){
            if(3*x<=A && abs(x)<=B && x*x<=C){
                for(y=x+1; y<=100; y++) {
                    if(x*y<=0)
                        break;
                    if(x+2*y<=A && x*y<=B && x*x+y*y<=C && B%(x*y)==0){
                        int z = B/(x*y);
                        if(z>y && x+y+z==A && x*x+y*y+z*z==C) {
                            found = true;
                            cout << x << " " << y << " " << z;
                            break;
                        }
                    }
                }
                if(found)
                    break;
            }
        }
        if(!found)
            cout << "No solution.";
        if(n!=0)
            cout << endl;
    }
    
    return 0;
}
