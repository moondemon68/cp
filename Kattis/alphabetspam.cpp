#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a=0,b=0,c=0,d=0,n=s.size();
	for (int i=0;i<s.size();i++) {
		if (s[i]=='_') a++;
		else if (s[i]>='a'&&s[i]<='z') b++;
		else if (s[i]>='A'&&s[i]<='Z') c++;
		else d++;
	}
	cout << fixed << setprecision(8) << (double)a/n << endl << (double)b/n << endl << (double)c/n << endl << (double)d/n << endl;
	return 0;
}
