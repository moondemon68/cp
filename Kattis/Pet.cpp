#include <bits/stdc++.h>

using namespace std;

int main () {
	int maxi=0,maxsum=0;
	for (int i=1;i<=5;i++) {
		int sum=0;
		for (int j=1;j<=4;j++) {
			int x;
			cin >> x;
			sum+=x;
		}
		if (sum>maxsum) {
			maxsum=sum;
			maxi=i;
		}
	}
	cout << maxi << " " << maxsum << endl;
	return 0;
}
