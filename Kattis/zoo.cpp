#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc=0;
	int n;
	while (1>0) {
		cin >> n;
		if (n==0) return 0;
		cin.ignore();
		tc++;
		cout << "List " << tc << ":" << endl;
		//cin.ignore();
		
		map<string,int> num;
		vector<string> ani;
		for (int t=1;t<=n;t++) {
			string s;
			getline(cin,s);
			//cin.ignore();
			vector<char> a;
			for (int i=s.size()-1;i>=0;i--) {
				if (s[i]==' ') break;
				else a.push_back(s[i]);
			}
			reverse(a.begin(),a.end());
			s="";
			for (int i=0;i<a.size();i++) {
				if (a[i]>='A'&&a[i]<='Z') a[i]+=32;
				s+=a[i];	
			}
			bool y=0;
			for (int i=0;i<ani.size();i++) {
				if (ani[i]==s) y=1;
			}
			if (!y) ani.push_back(s);
			num[s]++;
		}
		sort (ani.begin(),ani.end());
		
		for (int i=0;i<ani.size();i++) {
			cout << ani[i] << " | " << num[ani[i]] << endl;
			//cin.ignore();
		}
	}
}
