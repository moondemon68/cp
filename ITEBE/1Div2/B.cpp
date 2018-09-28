#include <bits/stdc++.h>

using namespace std;

int main () {
	string a,b;
	cin >> a >> b;
	vector<int> p,q;
	for (int i=0;i<a.size();i++) {
		p.push_back(a[i]-'0');
	}
	for (int i=0;i<b.size();i++) {
		q.push_back(b[i]-'0');
	}
	if (p.size()<q.size()) {
		reverse(p.begin(),p.end());
		while (p.size()<q.size()) {
			p.push_back(0);
		}
		reverse(p.begin(),p.end());
	}
	if (p.size()>q.size()) {
		reverse(q.begin(),q.end());
		while (p.size()>q.size()) {
			q.push_back(0);
		}
		reverse(q.begin(),q.end());
	}
	for (int i=0;i<p.size();i++) {
		if (p[i]<q[i]) {
			cout << '<' << endl;
			return 0;
		} else if (p[i]>q[i]) {
			cout << ">" << endl;
			return 0;
		}
	}
	cout << "=" << endl;
	return 0;
}
