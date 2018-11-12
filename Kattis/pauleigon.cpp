#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,p,q;
	cin >> n >> p >> q;
	if (((p+q+1)/n+((p+q+1)%n>0))%2==1) cout << "paul" << endl;
	 else cout << "opponent" << endl;
	 return 0;
}
