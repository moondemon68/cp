#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[100005];
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort (a,a+n);
	long long sum=0;
	for (int i=0;i<n;i++) {
		if (i%3!=n%3) sum+=a[i];
	}
	cout << sum << endl;
	return 0;
}
