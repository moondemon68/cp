#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	if (a==b) {
		cout << 0 << endl;
		return 0;
	}
	int ans=0;
	int cnta[30],cntb[30];
	memset (cnta,0,sizeof(cnta));
	memset (cntb,0,sizeof(cntb));
	for (int i=0;i<a.size();i++) cnta[a[i]-'a']++;
	for (int i=0;i<b.size();i++) cntb[b[i]-'a']++;
	bool p=0;
	for (int i=0;i<26;i++) {
		if (cnta[i]!=cntb[i]) p=1;
	}
	if (p) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> x;
	for (int i=0;i<a.size();i++) {
		if (a[i]==b[i]) continue;
		for (int j=i+1;j<a.size();j++) {
			if (a[j]==b[i]) {
				for (int k=j;k>i;k--) {
					swap(a[k-1],a[k]);
					x.push_back(k-1);
				}
				break;
			}
			if (a==b) break;
		}
		if (a==b) break;
	}
	//reverse(x.begin(),x.end());
	cout << x.size() << endl;
	for (int i=0;i<x.size();i++) {
		cout << x[i]+1 << " ";
	}
	//cout << a;
	return 0;
}
