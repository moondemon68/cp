#include <bits/stdc++.h>

using namespace std;

int main () {
	int a[10];
	for (int i=1;i<=9;i++) cin >> a[i];
	for (int i=0;i<(1<<9);i++) {
		int x=i;
		vector<int> p;
		while (p.size()<9) {
			p.push_back(x%2);
			x/=2;
		}
		int cnt=0;
		for (int j=0;j<9;j++) cnt+=p[j];
		if (cnt==7) {
			int ans=0;
			for (int j=0;j<9;j++) {
				if (p[j]) ans+=a[j+1];
			}
			if (ans==100) {
				for (int j=0;j<9;j++) {
					if (p[j]) cout << a[j+1] << endl;
				}
				return 0;
			}
		}
	}
}
