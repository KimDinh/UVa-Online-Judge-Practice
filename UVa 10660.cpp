#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

const int M = 5;
const int MM = M*M;

int main() {
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        int area[MM];
        int min_dist_sum=0;
        for (int i=0;i<MM;++i) {
            area[i]=0;
            min_dist_sum+=2*M*10000;
        }
        while (n--) {
            int r, c, population;
            cin >> r>> c>> population;
            area[r*M+c]=population;
        }
        
        int sol[5];
        for (int a=0;a<MM-4;++a)
            for (int b=a+1;b<MM-3;++b)
                for (int c=b+1;c<MM-2;++c)
                    for (int d=c+1;d<MM-1;++d)
                        for (int e=d+1;e<MM;++e) {
                            int office[5]={a,b,c,d,e};
                            int dist_sum = 0;
                            for (int i=0;i<MM;++i) {
                                if (area[i]>0) {
                                    int dist = abs(i/5-office[0]/5) + abs(i%5-office[0]%5);
                                    for (int j=1;j<5;++j) {
                                        int tmp = abs(i/5-office[j]/5) + abs(i%5-office[j]%5);
                                        if (tmp<dist)
                                            dist=tmp;
                                    }
                                    dist*=area[i];
                                    dist_sum+=dist;
                                }
                            }
                            if (dist_sum<min_dist_sum) {
                                min_dist_sum=dist_sum;
                                for(int t=0; t<5; t++)
                                    sol[t] = office[t];
                            }
                        }
        for (int i=0;i<5;++i) {
            if (i>0)
                cout<<" ";
            cout<<sol[i];
        }
        cout<<endl;
    }
    return 0;
}
