#include <bits/stdc++.h>

using namespace std;

int main () {
	int k,p;
	cin >> k;
	int cnt=0;
	for (int i=1;i<=INT_MAX;i*=2) {
		cnt++;
		if (i>=k) {
			p=i;
			cout << i << " ";
			break;
		}
	}
	cnt=0;
	while (k>0) {
		if (k-p==0) {
			cout << cnt << endl;
			break;
		} 
		else if (k>p) k-=p;
		cnt++;
		p/=2;
	}
	return 0;
}
