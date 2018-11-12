#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	getline(cin,s);
	for (int i=0;i<s.size();i++) {
		if ((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')&&(s[i]==s[i+2])) {
			if (s[i+1]=='p') { 
				i+=2;
				cout << s[i];
			} 
		}
		else cout << s[i];
	}
	return 0;
}
