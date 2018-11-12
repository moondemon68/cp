#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int d;
		long long n;
		cin >> d >> n;
		long long x=n;
		long long l=1,r=1;
		string s="";
		while (x>1) {
			if (x%2==0) s+='0';
			else s+='1';
			x/=2;
		}
		for (int i=s.size()-1;i>=0;i--) {
			if (s[i]=='0') r=l+r;
			else l=l+r;
		}
		cout << t << " " << l << "/" << r << endl;
	}
	return 0;
}
