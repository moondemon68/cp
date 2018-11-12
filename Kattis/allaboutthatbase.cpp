#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	char ans[37]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0'};
	for (int t=1;t<=tc;t++) {
		string a;
		char op;
		string b;
		char eq;
		string c;
		cin >> a >> op >> b >> eq >> c;
		bool y=0;
		int maxc=0;
		for (int i=1;i<=36;i++) {
			long long d=0,e=0,f=0;
			for (int j=0;j<a.size();j++) {
				for (int p=1;p<36;p++) {
					if (ans[p]==a[j]) maxc=max(maxc,p);
				}
				if (a[j]>='0'&&a[j]<='9') d+=a[j]-'0';
				else d+=a[j]-'a'+10;
				if (j!=a.size()-1) d*=i;
			}
			for (int j=0;j<b.size();j++) {
				for (int p=1;p<36;p++) {
					if (ans[p]==b[j]) maxc=max(maxc,p);
				}
				if (b[j]>='0'&&b[j]<='9') e+=b[j]-'0';
				else e+=b[j]-'a'+10;
				if (j!=b.size()-1) e*=i;
			}
			for (int j=0;j<c.size();j++) {
				for (int p=1;p<36;p++) {
					if (ans[p]==c[j]) maxc=max(maxc,p);
				}
				if (c[j]>='0'&&c[j]<='9') f+=c[j]-'0';
				else f+=c[j]-'a'+10;
				if (j!=c.size()-1) f*=i;
			}
			//cout << d << " " << e << " " << f;
			if (i<=maxc&&maxc!=1&&d<=4294967295&&e<=4294967295&&f<=4294967295&&d>=1&&e>=1&&f>=1) continue;
			if (op=='+'&&d+e==f) {
				cout << ans[i];
				y=1;
			} 
			else if (op=='-'&&d-e==f) {
				cout << ans[i];
				y=1;
			} 
			else if (op=='*'&&d*e==f) {
				cout << ans[i]; 
				y=1;
			}
			else if (op=='/'&&d/e==f&&d%e==0) {
				cout << ans[i];
				y=1;
			}
			//cout << endl;
		}
		if (!y) cout << "invalid";
		cout << endl;
	}
}
