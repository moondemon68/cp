#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,k;
	cin >> n >> k;
	int ac=0,pen=0,time=0;
	vector<int> a;
	for (int i=0;i<n;i++) {
		int x;
		cin >> x;
		if (i==k) {
			pen+=x;
			time+=x;
			if (pen>300) {
				cout << "0 0" << endl;
				return 0;
			} else {
				ac++;
			}
		} else a.push_back(x);
	}
	sort (a.begin(),a.end());
	for (int i=0;i<a.size();i++) {
		time+=a[i];
		if (time>300) {
			cout << ac << " " << pen << endl;
			return 0;
		} else {
			ac++;
			pen+=time;
		}
	}
	cout << ac << " " << pen << endl;
	return 0;
}
