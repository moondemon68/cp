#include <bits/stdc++.h>

using namespace std;

long long fact(int n) {
	long long ans=1;
	for (int i=1;i<=n;i++) {
		ans*=i;
		if (ans>1000000007) return 10000000000;
	}
	return ans;
}

long long pow(long long n,long long x) {
	if (n>1000000007) return 10000000000;
	if (x==1) return n;
	else return n*pow(n,x-1);
}	

int main () {
	double m,n;
	int t;
	cin >> m >> n >> t;
	double a[8]={-1,fact(n),pow(2,n),pow(n,4),pow(n,3),pow(n,2),n*log2(n),n};
	if (a[t]<=m) cout << "AC" << endl; else cout << "TLE" << endl;
	return 0;
}
