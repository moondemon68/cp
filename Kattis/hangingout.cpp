#include <bits/stdc++.h>

using namespace std;

int main () {
	int k,n;
	cin >> k >> n;
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++) {
		string s;
		int x;
		cin >> s >> x;
		if (s[0]=='e') {
			if (cnt+x>k) {
				ans++;
			} else {
				cnt+=x;
			}
		} else {
			cnt-=x;
		}
	}
	cout << ans << endl;
	return 0;
}
