#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

struct Co_or{
    int x,y;
};

int main() {
    int m;
    char a[1000][1000];
    Co_or pos1[1000], pos3[1000];
    
    cin >> m;
    while(!cin.eof()) {
        cin.ignore();
        int i1=0, i3=0;
        for(int i=1; i<=m; i++) {
            cin.get(a[i], 10000, '\n');
            cin.ignore();
            for(int j=0; j<m; j++){
                if(a[i][j]=='1') {
                    pos1[i1].x = i;
                    pos1[i1].y = j+1;
                    i1++;
                }
                if(a[i][j]=='3') {
                    pos3[i3].x = i;
                    pos3[i3].y = j+1;
                    i3++;
                }
            }
        }
        int maxofmin=0;
        for(int i=0; i<i1; i++) {
            int min=0;
            for(int j=0; j<i3; j++){
                int step = abs(pos1[i].x-pos3[j].x) + abs(pos1[i].y-pos3[j].y);
                if(min==0 || min > step)
                    min = step;
            }
            if(maxofmin<min)
                maxofmin = min;
        }
        cout << maxofmin;
        cin >> m;
        if(!cin.eof())
            cout << endl;
    }
    
    return 0;
    
}
