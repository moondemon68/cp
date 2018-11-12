#include <bits/stdc++.h>

using namespace std;

int main () {
	int a[4];
	for (int i=0;i<=3;i++) cin >> a[i];
	sort (a,a+4);
	cout << a[0]*a[2] << endl;				// yg diambil adalah yg terbesar ke 2 dan ke 4 (observasi) 
	return 0;
}
