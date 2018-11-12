#include <bits/stdc++.h>
#define MOD 1001113

using namespace std;

int main () {
	int a[105][105];
	a[2][1]=1;
	a[2][2]=1;
	for (int i=3;i<=100;i++) {
		for (int j=1;j<=i;j++) {
			if (j==1||j==i) a[i][j]=1;
			else {
				a[i][j]=j*a[i-1][j]+(i-j+1)*a[i-1][j-1];
				a[i][j]%=MOD;
			}
		}
	}
	/*
	for (int i=2;i<=8;i++) {
		for (int j=1;j<=i;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int p,n,k;
		cin >> p >> n >> k;
		cout << p << " " << a[n][k+1] << endl;
	} 
	return 0;
}
