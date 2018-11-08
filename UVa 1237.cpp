#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct Car{
    char M[25];
    int low, high;
};

int main() {
    Car car[10000];
    int T, Q, P, D;
    
    cin >> T;
    while(T--) {
        cin >> D;
        for(int i=0; i<D; i++) {
            cin.ignore();
            cin.get(car[i].M, 25, ' ');
            cin >> car[i].low >> car[i].high;
        }
        cin >> Q;
        for(int i=0; i<Q; i++) {
            cin >> P;
            int count=0, index;
            for(int j=0; j<D; j++) {
                if(P>=car[j].low && P<=car[j].high) {
                    index = j;
                    count++;
                }
                if(count>1)
                    break;
            }
            if(count!=1)
                cout << "UNDETERMINED" << endl;
            else cout << car[index].M << endl;
        }
        if(T)
            cout << endl;
    }
    
    return 0;
}
