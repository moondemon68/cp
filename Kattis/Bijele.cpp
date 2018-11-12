#include <bits/stdc++.h>

using namespace std;

int main () {
	int a[6]={1,1,2,2,2,8};
	for (int i=0;i<=5;i++) {
		int x;
		cin >> x;
		cout << a[i]-x << " ";
	}
	return 0;
}
