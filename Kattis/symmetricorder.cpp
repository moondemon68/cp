#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,t=1;
	while (1>0) {
		cin >> n;
		if (n==0) return 0;
		string a[20];
		for (int i=1;i<=n;i++) cin>> a[i];
		cout << "SET " << t << endl;
		for (int i=1;i<=n;i+=2) cout << a[i] << endl;
		if (n%2==0) for (int i=n;i>=2;i-=2) cout << a[i] << endl;
		else if (n%2==1) for (int i=n-1;i>=2;i-=2) cout << a[i] << endl;
		t++;
	}
	return 0;
}
