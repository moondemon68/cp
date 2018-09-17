#include <bits/stdc++.h>

using namespace std;

int main () {
	long long a,b;
	cin >> a >> b;
	if (a==b) {
		cout << 0 << endl;
		return 0;
	}
	vector<long long> p,q;
	while (a>0) {
		p.push_back(a%2);
		a/=2;
	}
	while (b>0) {
		q.push_back(b%2);
		b/=2;
	}
	//reverse(p.begin(),p.end());
	reverse(q.begin(),q.end());
	while (p.size()<q.size()) {
		p.push_back(0);
	}
	reverse(p.begin(),p.end());
	//for (int i=0;i<p.size();i++) cout << p[i];
	//cout << endl;
	//for (int i=0;i<p.size();i++) cout << q[i];
	//cout << endl;
	for (int i=0;i<p.size();i++) {
		//cout << p[i] << q[i] << endl;
		if (p[i]!=q[i]) {
			long long r=pow(2,p.size()-i);
			cout << fixed << setprecision(0) << (r-1) << endl;
			return 0;
		}
	}
}
