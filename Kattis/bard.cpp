#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int d;
	cin >> d;
	bool a[105][105];
	memset (a,0,sizeof(a));
	int s=0;
	for (int t=1;t<=d;t++) {
		int k;
		cin >> k;
		int b[105];
		bool y=0;
		for (int i=1;i<=k;i++) {
			cin >> b[i];
			if (b[i]==1) y=1;
		}
		if (!y) {
			vector<int> know;
			for (int i=1;i<=k;i++) {
				for (int j=1;j<=s;j++) {
					if (a[b[i]][j]) know.push_back(j);
				}
			}
			for (int i=1;i<=k;i++) {
				for (int j=0;j<know.size();j++) {
					a[b[i]][know[j]]=1;
				}
			}
		} else {
			s++;
			for (int i=1;i<=k;i++) {
				a[b[i]][s]=1;
			}
		}
		
	}
	for (int i=1;i<=n;i++) {
		bool x=1;
		for (int j=1;j<=s;j++) {
			if (!a[i][j]) x=0;
		}
		if (x) cout << i << endl;
	}
	return 0;
}
