#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a[30],b[30];
	memset (a,-1,sizeof(a));
	memset (b,-1,sizeof(b));
	for (int i=0;i<s.size();i++) {
		if (b[s[i]-'a']==-1) {
			b[s[i]-'a']=i;
		} else {
			a[s[i]-'a']=max(a[s[i]-'a'],i-b[s[i]-'a']);
			b[s[i]-'a']=i;
		}
	}
	int ans=1000000;
	for (int i=0;i<26;i++) {
		if (a[i]==-1) continue;
		ans=min(ans,a[i]);
	}
	if (ans==1000000) ans=(s.size())/2+1;
	cout << ans << endl;
	return 0;
}