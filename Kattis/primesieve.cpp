#include <bits/stdc++.h>

using namespace std;

bool prima[10005];
vector<int> a;

void sieve(int x) {
	memset (prima,1,sizeof(prima));
	prima[0]=0;
	prima[1]=0;
	for (int i=2;i*i<=x;i++) {
		for (int j=i*i;j<=x;j+=i) {
			prima[j]=0;
		}
	}
	for (int i=1;i<=x;i++) {
		if (prima[i]) a.push_back(i);
	}
}

int main () {
	int n,q;
	cin >> n >> q;
	sieve(sqrt(n)+1);
	for (int i=1;i<=q;i++) {
		int x;
		cin >> x;
		if (!prima[x]) cout << 0 << endl;
		else {
			bool ac=1;
			for (int j=0;a[j]*a[j]<=x;j++) {
				if (x%a[j]==0) {
					ac=0;
					break;
				}
			}
			if (ac) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
