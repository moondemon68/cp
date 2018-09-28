#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int main () {
	int n;
	cin >> n;
	if (n<=2) {
		cout << "YES" << endl;
		return 0;
	}
	int a[100005];
	for (int i=1;i<=n;i++) cin >> a[i];
	
	bool y=1;
	//reverse(a+1,a+n+1);
	for (int i=1;i<=n-2;i++) {
		//cout << a[i] << a[i+1] <<  a[i+2] << endl;
		if (a[i+2]<a[i]&&a[i]<a[i+1]) y=0;
	}
	if (y) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	return 0;
}
