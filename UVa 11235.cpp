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

#define ii pair<int, int>

struct Node{
    int left_ind, right_ind;
    int left_val, right_val;
    int val, max_freq;
    Node(){}
    Node(int l, int r, int lv, int rv, int v, int f){
        left_ind = l; right_ind = r; 
        left_val = lv; right_val = rv; 
        val = v; max_freq = f;
    }
};

class SegTree{
public:
    int N;
    vector<Node> A, ST;
    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) + 1; }
    void build(int p, int L, int R){
        if(L==R){
            ST[p] = A[L]; return;
        }
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        Node nodeL = ST[left(p)], nodeR = ST[right(p)];
        ST[p].left_ind = nodeL.left_ind; 
        ST[p].left_val = nodeL.left_val;
        ST[p].right_ind = nodeR.right_ind; 
        ST[p].right_val = nodeR.right_val;
        if(nodeL.val==nodeR.val){
            ST[p].max_freq = nodeL.max_freq + nodeR.max_freq; ST[p].val = nodeL.val;
        }
        else if(nodeL.max_freq<nodeR.max_freq){
            ST[p].max_freq = nodeR.max_freq; ST[p].val = nodeR.val;
        }
        else{
            ST[p].max_freq = nodeL.max_freq; ST[p].val = nodeL.val;
        }
    }
    int query(int p, int l, int r){
        if(l>ST[p].right_ind || r<ST[p].left_ind) return 0;
        if(l<=ST[p].left_ind && r>=ST[p].right_ind) return ST[p].max_freq;
        if(ST[p].left_val==ST[p].right_val){
            if(r>ST[p].right_ind)
                return ST[p].right_ind-l+1;
            if(l<ST[p].left_ind)
                return r-ST[p].left_ind+1;
            return r-l+1;
        }
        return max(query(left(p), l, r), query(right(p), l, r));
    }
    int query(int l, int r){
        return query(1, l, r);
    }
    SegTree(vector<Node>& A){
        N = A.size();
        this->A = A;
        ST.resize(4*N);
        build(1, 0, N-1);
    }
};

int a[100000], n, q;
vector<Node> A;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n && n){
        cin >> q;
        for(int i=0; i<n; i++)
            cin >> a[i];
        int cur=0, prev=0;
        A.clear();
        while(cur<n){
            int freq=1;
            while(cur<n-1 && a[cur]==a[cur+1]){
                cur++; freq++;
            }
            A.push_back(Node(prev, cur, a[prev], a[cur], a[cur], freq));
            prev = ++cur;
        }
        SegTree ST(A);
        int l, r;
        for(int i=0; i<q; i++){
            cin >> l >> r;
            cout << ST.query(l-1, r-1) << "\n";
        }
    }

    return 0;
}