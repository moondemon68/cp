#include <bits/stdc++.h>

using namespace std;

bool prima[31000005];
vector<int> p;

void sieve(int x) {
	memset (prima,1,sizeof(prima));
	for (int i=2;i*i<=x;i++) {
		for (int j=i*i;j<=x;j+=i) {
			prima[j]=0;
		}
	}
	for (int i=2;i<=x;i++) {
		if (prima[i]) p.push_back(i);
	}
}

int main () {
	sieve(31000000);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		int tc,x;
		cin >> tc >> x;
		cout << tc << " " << p[x-1] << endl;
	}
	return 0;
}
