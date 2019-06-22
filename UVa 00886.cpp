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

vector<string> names, extensions;
unordered_map<char, int> letter_by_digit;

void DialSetting(){
	letter_by_digit['A'] = letter_by_digit['B'] = letter_by_digit['C'] = 2;
	letter_by_digit['D'] = letter_by_digit['E'] = letter_by_digit['F'] = 3;
	letter_by_digit['G'] = letter_by_digit['H'] = letter_by_digit['I'] = 4;
	letter_by_digit['J'] = letter_by_digit['K'] = letter_by_digit['L'] = 5;
	letter_by_digit['M'] = letter_by_digit['N'] = letter_by_digit['O'] = 6;
	letter_by_digit['P'] = letter_by_digit['Q'] = letter_by_digit['R'] = letter_by_digit['S'] = 7;
	letter_by_digit['T'] = letter_by_digit['U'] = letter_by_digit['V'] = 8;
	letter_by_digit['W'] = letter_by_digit['X'] = letter_by_digit['Y'] = letter_by_digit['Z'] = 9;
}

bool matching(string P, int index){
	string T = names[index];
	int i=0, j=0;
    while(i<T.length() && j<T.length() && P[j]==T[i]){
        i++;
        j++;
    }
    if(j==P.length())
        return true;
    return false;
}

int main(){
	string s, ln, ex;

	DialSetting();
	while(cin >> s && ((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))) {
		cin >> ln >> ex;
		string name = "";
		name += s[0];
		name += ln;
		for(int i=0; i<name.length(); i++)
			name[i] = '0'+letter_by_digit[toupper(name[i])];
		names.push_back(name);
		extensions.push_back(ex);
	}
	while(true){
		bool found=0;
		for(int i=0; i<extensions.size(); i++)
			if(s==extensions[i]){
				cout << s;
				found = 1;
				break;
			}
		if(!found){
			for(int i=0; i<names.size(); i++)
				if(matching(s, i)){
					if(found)
						cout << " ";
					cout << extensions[i];
					found = 1;
				}
		}
		if(!found)
			cout << 0;
		cout << "\n";
		if(!(cin >> s))
			break;
	}


	return 0;
}