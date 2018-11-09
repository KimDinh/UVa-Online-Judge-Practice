#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int step, mod;
    while(cin >> step) {
        cin >> mod;
        if(step==1 || mod==1)
            cout << setw(10) << right << step << setw(10) << right << mod << "    Good Choice\n\n";
        else if(mod%step==0)
            cout << setw(10) << right << step << setw(10) << right << mod << "    Bad Choice\n\n";
        else {
            int div=2;
            while(div<step) {
                if(step%div==0 && mod%div==0) {
                    cout << setw(10) << right << step << setw(10) << right << mod << "    Bad Choice\n\n";
                    break;
                }
                else div++;
            }
            if(div==step)
                cout << setw(10) << right << step << setw(10) << right << mod << "    Good Choice\n\n";
        }
    }
    
    return 0;
}

/*#include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main(){
    int index = 0 , mod , step;
    while(cin>> step >> mod){
        bool vis[100000]={0} ;
        bool bad = false ;
        for (int i = 0; i < mod; ++i){ // I will walk form 0 To Mod-1
            int generated = (index + step)%mod; // 4+3=7 || 7%5 = 2  (because n%5 = 0 : 5-1 )
            if(vis[generated]==1) { // if the number repeated ==> break  and this Bad
                bad = true;
                break;
            }
            vis[generated] = 1 ; // make sure I visited the number
            index = generated;  // to start from where I end
        }
        cout << setw(10) << step << setw(10) << mod << "    ";
        bad ? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
    }
 }*/
