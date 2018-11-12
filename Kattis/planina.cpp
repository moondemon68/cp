#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[20];
	a[0]=1;
	for (int i=1;i<=15;i++) {
		a[i]=a[i-1]*2;
	}
	cout << (a[n]+1)*(a[n]+1) << endl;
	return 0;
}
