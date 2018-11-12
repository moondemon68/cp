#include <bits/stdc++.h>

using namespace std;

bool prima[32005];
void sieve(int x) {
	memset (prima,1,sizeof(prima));
	prima[0]=0;
	prima[1]=0;
	for (int i=2;i*i<=x;i++) {
		for (int j=i*i;j<=x;j+=i) {
			prima[j]=0;
		}
	}
	return;
}

int main () {
	sieve(32000);
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		vector<int> ans;
		int n;
		cin >> n;
		for (int i=1;i*2<=n;i++) {
			if (prima[i]&&prima[n-i]) ans.push_back(i);
		}
		cout << n << " has " << ans.size() << " representation(s)" << endl;
		for (int i=0;i<ans.size();i++) {
			cout << ans[i] << "+" << n-ans[i] << endl;
		}
		cout << endl;
	}
	return 0;
	
}
