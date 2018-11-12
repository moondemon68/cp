#include <bits/stdc++.h>

using namespace std;

bool prima[1000000005];
vector<int> primes;

void sieve(int x) {
	memset (prima,1,sizeof(prima));
	prima[0]=0;
	prima[1]=0;
	for (int i=2;i*i<=x;i++) {
		for (int j=i*i;j<=x;j+=i) {
			prima[j]=0;
		}
	}
	for (int i=2;i<=x;i++) {
		if (prima[i]) primes.push_back(i);
	}
}

int main () {
	int n;
	cin >> n;
	sieve(n);
	//for (int i=0;i<primes.size();i++) cout << primes[i] << " ";
	if (prima[n]) {
		cout << "yes" << endl;
		return 0;
	} else {
		bool ans=0;
		for (int i=0;i<primes.size();i++) {
			int x=n;
			while (x%primes[i]==0) {
				x/=primes[i];
			}
			if (x==1&&n!=1) {
				ans=1;
				break;
			}
		}
		if (ans) cout << "yes" << endl;
		else cout << "no" << endl;
		return 0;
	}
}
