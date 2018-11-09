#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int k, S[15];
    cin >> k;
    while(k) {
        for(int i=1; i<=k; i++)
            cin >> S[i];
        for(int i1=1; i1<=k-5; i1++)
            for(int i2=i1+1; i2<=k-4; i2++)
                for(int i3=i2+1; i3<=k-3; i3++)
                    for(int i4=i3+1; i4<=k-2; i4++)
                        for(int i5=i4+1; i5<=k-1; i5++)
                            for(int i6=i5+1; i6<=k; i6++)
                                cout << S[i1] << " " << S[i2] << " " << S[i3] << " " << S[i4] << " " << S[i5] << " " << S[i6] << endl;
        cin >> k;
        if(k)
            cout << endl;
    }
    
    return 0;
    
}
