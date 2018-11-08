#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int candy(char a[], char b[]) {
    int i=0, M=0, tmp;
    while(a[i]) {
        tmp = 0;
        int j=0, k=i;
        while(b[j] && a[k]) {
            if(b[j] == a[k])
                tmp++;
            j++;
            k++;
        }
        M = max(M, tmp);
        i++;
    }
    return M;
}

int main() {
    int t, n, len[80];
    char s[80][80];
    cin >> t;
    while(t--) {
        cin >> n;
        cin.ignore();
        for(int i=0; i<n; i++) {
            cin.get(s[i], 80, '\n');
            cin.ignore();
            len[i] = strlen(s[i]);
        }
        int Candy=0, tmp;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i!=j && len[i]>Candy && len[j]>Candy) {
                    tmp = candy(s[i], s[j]);
                    Candy = max(Candy, tmp);
                }
        cout << Candy << endl;
    }
    
    return 0;
}
