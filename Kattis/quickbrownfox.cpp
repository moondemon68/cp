#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	cin.ignore();
	for (int t=1;t<=tc;t++) {
		string s;
		getline(cin,s);
		bool a[30];
		memset (a,0,sizeof(a));
		for (int i=0;i<s.size();i++) {
			if (s[i]>='A'&&s[i]<='Z') a[s[i]-'A'+1]=1;
			else if (s[i]>='a'&&s[i]<='z') a[s[i]-'a'+1]=1;
		}
		bool yes=1;
		for (int i=1;i<=26;i++) {
			if (!a[i]) yes=0;
		}
		if (yes) cout << "pangram" << endl; else {
			cout << "missing ";
			for (int i=1;i<=26;i++) {
				if (!a[i]) printf("%c",i+'a'-1);
			}
			cout << endl;
		}
	}
}
