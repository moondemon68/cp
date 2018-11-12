#include <bits/stdc++.h>

using namespace std;

int main () {
	int x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int a[1005];
	memset (a,0,sizeof(a));
	a[x1]++;
	a[x2]++;
	a[x3]++;
	for (int i=1;i<=1000;i++) {
		if (a[i]==1) cout << i << " ";
	}
	memset (a,0,sizeof(a));
	a[y1]++;
	a[y2]++;
	a[y3]++;
	for (int i=1;i<=1000;i++) {
		if (a[i]==1) cout << i << endl;
	}
	return 0;
}
