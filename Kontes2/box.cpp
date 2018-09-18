#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ans=0,cur=1;
	stack<int> a;
	for (int i=1;i<=n+n;i++) {
		string s;
		cin >> s;
		if (s=="add") {
			int x;
			cin >> x;
			a.push(x);
		} else {
			if (!a.empty()) {
				if (a.top()!=cur) {
					ans++;
					//cout << ans << endl;
					while (!a.empty()) a.pop();
				} else {
					a.pop();
				}
			}
			cur++;
		}
	}
	cout << ans << endl;
}
