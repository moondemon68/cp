#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	vector<string> a;
	while (getline(cin,s)) {
		s+=' ';
		string x="";
		for (int i=0;i<s.size();i++) {
			if (s[i]==' ') {
				a.push_back(x);
				x="";
			} else x+=s[i];
		}
	}
	vector<string> ans;
	for (int i=0;i<a.size();i++) {
		for (int j=0;j<a.size();j++) {
			if (i==j) continue;
			string z=a[i]+a[j];
			bool y=0;
			for (int k=0;k<ans.size();k++) {
				if (ans[k]==z) y=1;
			}
			if (!y) ans.push_back(z);
		}
	}
	sort (ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
