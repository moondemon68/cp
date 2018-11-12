#include <bits/stdc++.h>

using namespace std;

int main () {
	int b,br,bs,a,as;
	cin >> b >> br >> bs >> a >> as;
	int s=(br-b)*bs;
	int now=0;
	while (now<=s) {
		now+=as;
		a++;
	}
	cout << a;
	return 0;
}
