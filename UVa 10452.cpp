#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class StonePath {
private:
    int n, m;
    char** path;
public:
    StonePath(int N, int M) {
        n = N; m = M;
        path = new char* [n];
        for(int i=0; i<n; i++) {
            path[i] = new char[m];
            //memset(path[i], '0', m);
        }
    }
    ~StonePath() {
        for(int i=0; i<n; i++)
            delete [] path[i];
        delete [] path;
    }
    bool valid(int x, int y) {
        if(x>=0 && x<n && y>=0 && y<m)
            return true;
        else return false;
    }
    void Input() {
        for(int i=0; i<n; i++) {
            string str;
            getline(cin, str);
            for(int j=0; j<m; j++)
                path[i][j] = str[j];
        }
    }
    void Findpath() {
        char safeln[]="@IEHOVA#";
        int step=0, i=n-1, j=0;
        while(j<m) {
            if(path[i][j]==safeln[step]) {
                step++;
                break;
            }
            else j++;
        }
        while(i>=0 && step<8) {
            if(valid(i, j-1) && path[i][j-1]==safeln[step]) {
                cout << "left";
                j--; step++;
            }
            else if(valid(i, j+1) && path[i][j+1]==safeln[step]) {
                cout << "right";
                j++; step++;
            }
            else {
                cout << "forth";
                i--; step++;
            }
            if(step<8)
                cout << " ";
        }
    }
    
};

int main() {
    int test, N, M;
    cin >> test;
    for(int i=0; i<test; i++) {
        cin >> N >> M;
        cin.ignore();
        StonePath path(N, M);
        path.Input();
        path.Findpath();
        if(i<test-1)
            cout << endl;
    }
    return 0;
}
