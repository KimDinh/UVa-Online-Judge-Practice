#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int score[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
    int n=sizeof(score)/sizeof(int), x, c, p;
    
    cin >> x;
    while(x>0) {
        c=0; p=0;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                for(int k=j; k<n; k++)
                    if(score[i]+score[j]+score[k]==x) {
                        c++;
                        if(i<j) {
                            if(j<k)
                                p+=6;
                            else p+=3;
                        }
                        else {
                            if(j<k)
                                p+=3;
                            else p+=1;
                        }
                    }
        if(c>0) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << x << " IS " << c << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << x << " IS " << p << ".\n";
        }
        else cout << "THE SCORE OF " << x << " CANNOT BE MADE WITH THREE DARTS.\n";
        for(int i=0; i<70; i++)
            cout << "*";
        cout << endl;
        
        cin >> x;
        if(x<=0)
            cout << "END OF OUTPUT";
    }
    
    return 0;
    
}
