#include <bits/stdc++.h>

using namespace std;

long long pow(long long a,long long b,long long MOD) {
	if (b==0) return 1;
	long long ans=1;
	if (b%2==0) {
		ans=pow(a,b/2,MOD)*pow(a,b/2,MOD);
		ans%=MOD;
	}
	else {
		ans=pow(a,b/2,MOD)*pow(a,b/2,MOD);
		ans%=MOD;
		ans*=a;
	}
	ans%=MOD;
	return ans;
}

int main () {
	long long n,k;
	int q;
	cin >> n >> k >> q;
	long long p=pow(k,n-2,n);
	for (int t=1;t<=q;t++) {
		long long c,d;
		cin >> c >> d;
		long long pos=p;
		pos*=d;
		pos%=n;
		//cout << pos << endl;
		long long ans=c/n;
		
		if ((c%n)>pos) ans++;
		cout << ans << endl;
	}
	return 0;
}
