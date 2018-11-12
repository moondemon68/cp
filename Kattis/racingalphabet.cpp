#include <bits/stdc++.h>

using namespace std;

int main () {
	string a="ABCDEFGHIJKLMNOPQRSTUVWXYZ '";
	string s;
	int tc;
	cin >> tc;
	cin.ignore();
	for (int t=1;t<=tc;t++) {
		int total=0;
		getline(cin,s);
		for (int i=0;i<s.size()-1;i++) {
			int x,y;
			for (int j=0;j<a.size();j++) {
				if (a[j]==s[i+1]) x=j;
			}
			for (int j=0;j<a.size();j++) {
				if (a[j]==s[i]) y=j;
			}
			int d=min(abs(x-y),(28-abs(x-y)));
			total+=d;
		}
		cout << fixed << setprecision(7) << s.size()+2*acos(-1)*30*total/28/15 << endl;
	}
	return 0;
}
