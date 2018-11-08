#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;

struct alignpoint{
    int level, time;
};

bool better(int lvlmiss1[], int lvlmiss[]) {
    int i=1;
    while(lvlmiss1[i]==lvlmiss[i])
        i++;
    if(lvlmiss1[i]<lvlmiss[i])
        return true;
    else return false;
}

int main() {
    int p, a, proglen[10], lvlmiss[6], switchpoint[10], ans[10], lvlmiss1[6], set=1;
    alignpoint ap[10];
    cin >> p;
    while(p) {
        for(int i=1; i<=p; i++)
            cin >> proglen[i];
        cin >> a;
        for(int i=1; i<=a; i++)
            cin >> ap[i].level >> ap[i].time;
        if(p==1) {
            for(int i=1; i<=5; i++)
                lvlmiss[i] = 0;
            for(int i=1; i<=a; i++)
                lvlmiss[ap[i].level] += abs(ap[i].time-proglen[1]);
            cout << "Data set " << set << endl;
            cout << "  Order: " << proglen[1] << endl;
            cout << "  Error: " << lvlmiss[1]+lvlmiss[2]+lvlmiss[3]+lvlmiss[4]+lvlmiss[5] << endl;
            cin >> p;
            set++;
            continue;
        }
        for(int i=1; i<=5; i++)
            lvlmiss[i] = -1;
        sort(proglen+1, proglen+p+1);
        while(next_permutation(proglen+1, proglen+p+1)) {
            for(int i=1; i<=5; i++)
                lvlmiss1[i] = 0;
            for(int i=1; i<=p; i++) {
                if(i==1)
                    switchpoint[i] = proglen[i];
                else switchpoint[i] = switchpoint[i-1]+proglen[i];
            }
            for(int i=1; i<=a; i++) {
                int miss;
                for(int j=1; j<=p; j++)
                    if(j==1 || miss > abs(ap[i].time-switchpoint[j]))
                        miss = abs(ap[i].time-switchpoint[j]);
                lvlmiss1[ap[i].level] += miss;
            }
            if(lvlmiss[1]==-1){
                for(int i=1; i<=5; i++)
                    lvlmiss[i] = lvlmiss1[i];
                for(int i=1; i<=p; i++)
                    ans[i] = proglen[i];
            }
            else if(better(lvlmiss1, lvlmiss)) {
                for(int i=1; i<=5; i++)
                    lvlmiss[i] = lvlmiss1[i];
                for(int i=1; i<=p; i++)
                    ans[i] = proglen[i];
            }
        }
        cout << "Data set " << set << endl;
        cout << "  Order: ";
        for(int i=1; i<=p; i++)
            cout << ans[i] << " ";
        cout << "\n  Error: " << lvlmiss[1]+lvlmiss[2]+lvlmiss[3]+lvlmiss[4]+lvlmiss[5] << endl;
        set++;
        cin >> p;
    }
    
    return 0;
}
