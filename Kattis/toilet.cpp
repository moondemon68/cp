#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	string t=s,u=s;
	int ans1=0,ans2=0,ans3=0;
	for (int i=1;i<s.size();i++) {
		if (s[i-1]=='D'&&s[i]=='D') ans1++;
		else if (s[i-1]=='D'&&s[i]=='U') ans1++;
		else if (s[i-1]=='U'&&s[i]=='D') ans1+=2;
		else if (s[i-1]=='U'&&s[i]=='U') ans1+=0;
		s[i]='U';
	}
	for (int i=1;i<s.size();i++) {
		if (t[i-1]=='U'&&t[i]=='U') ans2++;
		else if (t[i-1]=='U'&&t[i]=='D') ans2++;
		else if (t[i-1]=='D'&&t[i]=='U') ans2+=2;
		else if (t[i-1]=='D'&&t[i]=='D') ans2+=0;
		t[i]='D';
	}
	for (int i=1;i<s.size();i++) {
		if (u[i-1]=='D'&&u[i]=='U') ans3++;
		else if (u[i-1]=='U'&&u[i]=='D') ans3++;
	}
	cout << ans1 << endl << ans2 << endl << ans3 << endl;
	return 0;
}
