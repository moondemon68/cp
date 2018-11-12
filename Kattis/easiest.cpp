#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (cin >> n) {
		if (n==0) return 0;
		int sum=0;
		int t=n;
		while (t>0) {
			sum+=t%10;
			t/=10;
		}
		for (int i=11;i<=10000;i++) {
			int tmp=i*n;
			int sum1=0;
			while (tmp>0) {
				sum1+=tmp%10;
				tmp/=10;
			}
			if (sum1==sum) {
				cout << i << endl;
				break;
			}
		}
	}
}
