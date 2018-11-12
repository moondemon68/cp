#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b,c;
	cin >> a >> b >> c;
	int t[105];
	int ans=0;
	memset (t,0,sizeof(t));
	for (int i=1;i<=3;i++) {
		int x,y;
		cin >>x >> y;
		for (int j=x;j<y;j++) {
			t[j]++;
		}	
	}
	for (int i=1;i<=100;i++) {
		if (t[i]==1) ans+=a;
		else if (t[i]==2) ans+=b+b;
		else if (t[i]==3) ans+=c+c+c;
	}
	cout << ans << endl;
	return 0;
}
