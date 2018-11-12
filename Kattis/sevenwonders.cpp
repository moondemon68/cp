#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a=0,b=0,c=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='T') a++;
		else if (s[i]=='C') b++;
		else if (s[i]=='G') c++;
	}
	cout << a*a+b*b+c*c+7*(min(a,min(b,c))) << endl;
	return 0;
}
