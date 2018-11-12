#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<string> a;
	for (int i=1;i<=n;i++) {
		string stat,name;
		cin >> stat >> name;
		if (stat=="entry") {
			bool ada=0;
			for (int j=0;j<a.size();j++) {
				if (a[j]==name) {
					ada=1;
				}
			}
			if (ada) cout << name << " entered (ANOMALY)" << endl;
			else {
				a.push_back(name);
				cout << name << " entered" << endl;
			}
		}
		if (stat=="exit") {
			bool ada=0;
			int place;
			for (int j=0;j<a.size();j++) {
				if (a[j]==name) {
					ada=1;
					place=j;
				}
			}
			if (!ada) cout << name << " exited (ANOMALY)" << endl;
			else {
				a.erase(a.begin()+place);
				cout << name << " exited" << endl;
			}
		}
	}
	return 0;
}
