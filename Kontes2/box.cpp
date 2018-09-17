#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> ans;
	ans.push_back(0);
	stack<int> a;
	for (int i=1;i<=2*n;i++) {
		string s;
		cin >> s;
		if (s=="add") {
			int x;
			cin >> x;
			a.push(x);
		} else {
			ans.push_back(a.top());
			a.pop();
		}
	}
	int out=0;
	for (int i=1;i<=n;i++) {
		if (ans[i]!=i) {
			out++;
			for (int j=i+1;j<=n;j++) {
				if (ans[j]==i) {
					swap(ans[i],ans[j]);
					break;
				}
			}
		}
	}
	cout << out << endl;
	return 0;
}
