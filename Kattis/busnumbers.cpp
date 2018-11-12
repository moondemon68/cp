#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	bool a[1005];
	memset (a,0,sizeof(a));
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		a[x]=1;
	}
	for (int i=1;i<=1000;i++) {
		if (a[i]) {
			int cur=i,num=0;
			for (int j=1;i+j<=1000;j++) {
				if (a[i+j]) num++; else break;
			}
			if (num>1) cout << cur << "-" << cur+num << " "; else if (num==1) cout << cur << " " << cur+1 << " "; else cout << cur << " ";
			i=cur+num;
		}
	}
}
