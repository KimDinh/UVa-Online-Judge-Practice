#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <iomanip>
using namespace std;

#define MAXN 20100

char A[MAXN];
int n, cnt[MAXN];
int SA[MAXN], RA[MAXN], tempSA[MAXN], tempRA[MAXN];

void countingSort(int k){
    int max_char = max(300, n), sum=0;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
        cnt[i+k<n ? RA[i+k] : 0]++;
    for(int i=0; i<max_char; i++){
        int t = cnt[i];
        cnt[i] = sum;
        sum += t;
    }
    for(int i=0; i<n; i++)
        tempSA[cnt[SA[i]+k<n ? RA[SA[i]+k] : 0]++] = SA[i];
    for(int i=0; i<n; i++)
        SA[i] = tempSA[i];
}

void constructSA(){
    int rank;
    for(int i=0; i<n; i++)
        RA[i] = A[i];
    for(int i=0; i<n; i++)
        SA[i] = i;
    for(int k=1; k<n; k*=2){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = rank = 0;
        for(int i=0; i<n; i++){
            if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])
                tempRA[SA[i]] = rank;
            else tempRA[SA[i]] = ++rank;
        }
        for(int i=0; i<n; i++)
            RA[i] = tempRA[i];
        if(RA[SA[n-1]]==n-1)
            break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, m;
    char P[10005];
    cin >> T;
    cin.ignore();
    while(T--){
        cin.get(P, 10001, '\n');
        cin.ignore();
        m = strlen(P);
        strcpy(A, P); strcat(A, P); 
        strcat(A, "{");
        n = strlen(A);
        constructSA();
        for(int i=0; i<n; i++)
            if(SA[i]<m){
                cout << SA[i]+1 << "\n";
                break;
            }
    }

    return 0;
}