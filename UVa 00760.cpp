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

#define MAXN 10000
#define LINE cout << __LINE__ << "\n"

char P[MAXN];
int n, RA[MAXN], SA[MAXN], cnt[MAXN], order[MAXN];
int tempRA[MAXN], tempSA[MAXN], lcp[MAXN];

void countingSort(int k){
    int max_char = max(n, 300);
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
        cnt[i+k<n ? RA[i+k] : 0]++;
    for(int i=1; i<max_char; i++)
        cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; i--)
        tempSA[--cnt[SA[i]+k<n ? RA[SA[i]+k] : 0]] = SA[i];
    for(int i=0; i<n; i++)
        SA[i] = tempSA[i];
}

void constructSA(){
    int rank;
    for(int i=0; i<n; i++){
        RA[i] = P[i];
        SA[i] = i;
    }
    for(int k=1; k<n; k*=2){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = rank = 0;
        for(int i=1; i<n; i++){
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

void constructLCP(){
    for(int i=0; i<n; i++)
        order[SA[i]] = i;
    int L=0;
    for(int i=0; i<n; i++){
        if(order[i]==n-1){
            L = 0;
            continue;
        }
        int j = SA[order[i]+1];
        while(i+L<n && j+L<n && P[i+L]==P[j+L])
            L++;
        lcp[order[i]] = L;
        if(L)
            L--;
    }
}

int main(){
    char A[305], B[305], prev[MAXN], cur[MAXN];
    vector<int> ans;
    int maxL;
    bool first=1;

    while(cin.get(A, 301, '\n')){
        cin.ignore(); cin.get(B, 301, '\n');
        cin.ignore(); cin.ignore();
        strcpy(P, A); strcat(P, "$"); strcat(P, B);
        int nA = strlen(A);
        n = strlen(P);
        if(!first)
            cout << "\n";
        first = 0;
        memset(SA, 0, sizeof(SA));
        memset(lcp, 0, sizeof(lcp));
        constructSA(); constructLCP();
        maxL = 0;
        ans.clear();
        
        for(int i=0; i<n-1; i++)
            if(min(SA[i], SA[i+1])+lcp[i]<=nA && max(SA[i], SA[i+1])>nA && lcp[i]>=maxL) {
                if(lcp[i]>maxL){
                    maxL = lcp[i];
                    ans.clear();
                    ans.push_back(min(SA[i], SA[i+1]));
                    memset(prev, '\0', sizeof(prev));
                    strncpy(prev, A+min(SA[i], SA[i+1]), maxL);
                }
                else if(maxL>0){
                    memset(cur, '\0', sizeof(cur));
                    strncpy(cur, A+min(SA[i], SA[i+1]), maxL);
                    if(strcmp(prev, cur)){
                        ans.push_back(min(SA[i], SA[i+1]));
                        strcpy(prev, cur);
                    }
                }
            }
        
        if(maxL==0){
            cout << "No common sequence.\n";
            continue;
        }
        for(int i=0; i<ans.size(); i++)
            printf("%.*s\n", maxL, A+ans[i]);
    }

    return 0;
}