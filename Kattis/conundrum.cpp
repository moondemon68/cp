#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int ans=0;
	for (int i=0;i<s.size();i++) {
		if (i%3==0&&s[i]!='P') ans++;
		if (i%3==1&&s[i]!='E') ans++;
		if (i%3==2&&s[i]!='R') ans++;
	}
	cout << ans << endl;
	return 0;
}
