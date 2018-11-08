#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

void checkship(char a[][110], int n, int i, int j) {
    if(i<0 || j<0 || i>=n || j>=n)
        return;
    if(a[i][j]=='.')
        return;
    a[i][j] = '.';
    checkship(a, n, i-1, j);
    checkship(a, n, i+1, j);
    checkship(a, n, i, j-1);
    checkship(a, n, i, j+1);
}

int main() {
    char a[110][110];
    int n, t, ship, cases;
    cin >> t;
    cases = 0;
    while(t--) {
        ship = 0;
        cases++;
        cin >> n;
        cin.ignore();
        for(int i=0; i<n; i++) {
            cin.get(a[i], 110, '\n');
            cin.ignore();
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(a[i][j]=='x') {
                    ship++;
                    checkship(a, n, i, j);
                }
        cout << "Case " << cases << ": " << ship << endl;
    }
    
    return 0;
}
