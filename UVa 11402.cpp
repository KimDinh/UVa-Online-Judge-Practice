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

unordered_map<char, int> query_type;

struct Node{
    int length, ones, lazy_type;
    Node(){}
    Node(int l, int o, int t){
        length = l; ones = o; lazy_type = t;
    }
};

class SegTree{
public:
    vector<Node> ST;
    string A;
    int N;
    int left(int i) { return (i << 1); }
    int right(int i) { return (i << 1) + 1; }
    void build(int p, int L, int R){
        if(L==R){
            ST[p] = Node(1, (A[L]=='1') ? 1 : 0, 0);
            return;
        }
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        ST[p].length = ST[left(p)].length + ST[right(p)].length;
        ST[p].ones = ST[left(p)].ones + ST[right(p)].ones;
        ST[p].lazy_type = 0;
    }
    int combine_type(int t1, int t2){
        if(t2==0) return t1;
        if(t2==1 || t2==2) return t2;
        return 3-t1;
    }
    void lazy_down(int p){
        update_type(left(p), ST[p].lazy_type);
        update_type(right(p), ST[p].lazy_type);
        ST[p].lazy_type = 0;
        ST[p].ones = ST[left(p)].ones + ST[right(p)].ones;
    }
    void update_type(int p, int type){
        switch (type){
        case 1:
            ST[p].ones = ST[p].length;
            break;
        case 2:
            ST[p].ones = 0;
            break;
        case 3:
            ST[p].ones = ST[p].length-ST[p].ones;
            break;
        default:
            break;
        }
        ST[p].lazy_type = combine_type(ST[p].lazy_type, type);
    }
    void update(int p, int L, int R, int uL, int uR, int type){
        if(L>uR || R<uL) return;
        if(L>=uL && R<=uR){
            update_type(p, type);
            return;
        }
        lazy_down(p);
        update(left(p), L, (L+R)/2, uL, uR, type);
        update(right(p), (L+R)/2+1, R, uL, uR, type);
        ST[p].ones = ST[left(p)].ones + ST[right(p)].ones;
    }
    int query(int p, int L, int R, int qL, int qR){
        if(L>qR || R<qL) return 0;
        if(L>=qL && R<=qR) return ST[p].ones;
        lazy_down(p);
        return (query(left(p), L, (L+R)/2, qL, qR)
                + query(right(p), (L+R)/2+1, R, qL, qR));
    }
    void update(int uL, int uR, int type){
        update(1, 0, N-1, uL, uR, type);
    }
    int query(int qL, int qR){
        return query(1, 0, N-1, qL, qR);
    }
    SegTree(string a){
        A = a; N = a.length();
        ST.resize(4*N+1);
        build(1, 0, N-1);
    }
};

int main(){
    int cases, M, T, Q, q, l, r;
    string a, s;
    char t;

    query_type['F'] = 1;
    query_type['E'] = 2;
    query_type['I'] = 3;
    query_type['S'] = 4;

    cin >> cases;
    for(int c=1; c<=cases; c++){
        cin >> M;
        a = "";
        for(int i=0; i<M; i++){
            cin >> T; cin >> s;
            for(int j=0; j<T; j++)
                a += s;
        }
        SegTree ST(a);
        cin >> Q;
        q = 0;
        cout << "Case " << c << ":\n";
        for(int i=0; i<Q; i++){
            cin.ignore(); cin.get(t);
            cin >> l >> r;
            if(t=='S')
                cout << "Q" << ++q << ": " << ST.query(l, r) << "\n";
            else ST.update(l, r, query_type[t]);
        }
    }

    return 0;
}