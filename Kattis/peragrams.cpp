#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a[30];
	memset (a,0,sizeof(a));
	for (int i=0;i<s.size();i++) {
		a[s[i]-'a'+1]++;
		if (a[s[i]-'a'+1]%2==0) a[s[i]-'a'+1]=0;
	}
	int ans=0;
	for (int i=1;i<=26;i++) {
		if (a[i]%2==1) ans++;
	}
	cout << max(0,ans-1) << endl;
	return 0;
}
