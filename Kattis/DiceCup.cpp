#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b;
	cin >> a >> b;
	int cnt[45];
	memset (cnt,0,sizeof(cnt));
	for (int i=1;i<=a;i++) {
		for (int j=1;j<=b;j++) {
			cnt[i+j]++;
		}
	}
	int maxsum=0;
	for (int i=1;i<=40;i++) {
		maxsum=max(maxsum,cnt[i]);
	}
	for (int i=1;i<=40;i++) {
		if (cnt[i]==maxsum) {
			cout << i << endl;
		}
	}
	return 0;
}
