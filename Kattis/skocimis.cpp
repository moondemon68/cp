#include <bits/stdc++.h>

using namespace std;

int main () {
	int a[3],ans=0,ans1=0;
	cin >> a[0] >> a[1] >> a[2];
	int b[3]={a[0],a[1],a[2]},c[3]={a[0],a[1],a[2]};
	while (b[2]-b[1]>1) {
		b[0]=b[1]+1;
		sort (b,b+3);
		ans++;
	}
	while (c[1]-c[0]>1) {
		c[2]=c[1]-1;
		sort (c,c+3);
		//cout << c[0] << c[1] << c[2] << endl;
		ans1++;
	}
	cout << max(ans,ans1) << endl;
}
