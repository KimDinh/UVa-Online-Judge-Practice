#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main() {
	int N, a[10001], b[10001], m;

	cin >> N;
	while(N) {
		for(int i=0; i<N; i++)
			cin >> a[i];
		b[0] = m = a[0];
		for(int i=1; i<N; i++) {
			b[i] = max(b[i-1]+a[i], a[i]);
			m = max(m, b[i]);
		}
		if(m>0)
			cout << "The maximum winning streak is " << m << ".\n";
		else cout << "Losing streak.\n";
		cin >> N;
	}

	return 0;
}
