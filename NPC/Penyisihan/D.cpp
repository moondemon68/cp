#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	getline(cin,s);
	long long n;
	cin >> n;
	s+='*';
	vector<long long> b;
	map<long long,int> a;
	long long x=0;
	for (int i=0;i<s.size();i++) {
		//cout << s[i] << " ";
		if (s[i]==' '||s[i]=='*') {
			x/=10;
			//cout << x << endl;
			if (a[x]==1) a[x]=2;
			else if (a[x]==0) a[x]=1;
			b.push_back(x);
			x=0;
		} else {
			x+=s[i]-'0';
			//cout << s[i] << " " << x << endl;
			x*=10;
		}
	}
	for (int i=0;i<b.size();i++) {
		//cout << b[i] << endl;
		if (n!=b[i]*2&&a[n-b[i]]==1) {
			cout << "ADA" << endl;
			return 0;
		}
		if (n==b[i]*2&&a[b[i]]==2) {
			//cout << b[i] << " " << n-b[i];
			cout << "ADA" << endl;
			return 0;
		}
	}
	cout << "TIDAK ADA" << endl;
	return 0;
}
