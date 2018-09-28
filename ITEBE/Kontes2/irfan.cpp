#include <bits/stdc++.h>

using namespace std;

bool cmp(int x,int y) {
	int a=x,b=y,dx=0,dy=0;
	while (x>0) {
		dx++;
		x/=10;
	}
	while (y>0) {
		dy++;
		y/=10;
	}
	long long p=a*pow(10,dy)+b,q=b*pow(10,dx)+a;
	//cout << p << " " << q << " " << (p>q) << endl;
	return p>q;
}

int main () {
	int n;
	cin >> n;
	int a[2005];
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) cout << a[i];
	return 0;
}
