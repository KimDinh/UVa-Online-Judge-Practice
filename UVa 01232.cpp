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

#define MAXN 1e5

struct Node{
    int max_height, lazy;
    bool same_max;
    Node(){}
    Node(int h, int l, bool u){
        max_height = h; lazy = l; same_max = u;
    }
};

class SegTree{
public:
    vector<Node> ST;
    int left(int i){ return (i << 1); }
    int right(int i){ return (i << 1) + 1; }
    void lazy_down(int p){
        int h = ST[p].lazy;
        if(ST[left(p)].max_height<=h){
            ST[left(p)].max_height = h;
            ST[left(p)].same_max = 1;
        } 
        ST[left(p)].lazy = max(ST[left(p)].lazy, h);
        if(ST[right(p)].max_height<=h){
            ST[right(p)].max_height = h;
            ST[right(p)].same_max = 1;
        }
        ST[right(p)].lazy = max(ST[right(p)].lazy, h);
        ST[p].lazy = 0;
        ST[p].same_max = (ST[left(p)].same_max 
                        && ST[right(p)].same_max
                        && ST[left(p)].max_height == ST[right(p)].max_height);
    }
    void build(int p, int L, int R){
        if(L==R){
            ST[p] = Node(0, 0, 1);
            return;
        }
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        ST[p] = Node(0, 0, 1);
    }
    void update(int p, int L, int R, int uL, int uR, int h){
        if(L>uR || R<uL) return;
        if(L>=uL && R<=uR){
            if(ST[p].max_height<=h)
                ST[p].same_max = 1;
            ST[p].max_height = max(ST[p].max_height, h);
            ST[p].lazy = max(ST[p].lazy, h);
            
            return;
        }
        lazy_down(p);
        update(left(p), L, (L+R)/2, uL, uR, h);
        update(right(p), (L+R)/2+1, R, uL, uR, h);
        ST[p].max_height = max(ST[left(p)].max_height, ST[right(p)].max_height);
        ST[p].same_max = (ST[left(p)].same_max 
                        && ST[right(p)].same_max
                        && ST[left(p)].max_height == ST[right(p)].max_height);
    }
    int query(int p, int L, int R, int qL, int qR, int h){
        if(L>qR || R<qL) return 0;
        if(L>=qL && R<=qR && ST[p].same_max)
            return (ST[p].max_height<=h) ? (R-L+1) : 0;
        lazy_down(p);
        return (query(left(p), L, (L+R)/2, qL, qR, h)
                + query(right(p), (L+R)/2+1, R, qL, qR, h));
    }
    void update(int uL, int uR, int h){
        update(1, 1, MAXN, uL, uR, h);
    }
    int query(int qL, int qR, int h){
        return query(1, 1, MAXN, qL, qR, h);
    }
    SegTree(){
        ST.resize(4*MAXN+10);
        build(1, 1, MAXN);
    }
};

int main(){
    int T, buildings, l, r, h, overlap;

    cin >> T;
    while(T--){
        cin >> buildings;
        overlap = 0;
        SegTree ST;
        for(int i=0; i<buildings; i++){
            cin >> l >> r >> h;
            overlap += ST.query(l, r-1, h);
            ST.update(l, r-1, h);
        }
        cout << overlap << "\n";
    }

    return 0;
}