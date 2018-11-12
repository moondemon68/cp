#include <bits/stdc++.h>

using namespace std;

int main () {
	int e,f,c;
	cin >> e >> f >> c;
	int ans=0;
	e+=f;
	while (e/c>0) {
		ans+=e/c;
		//cout << e/c << " ";
		int x=e%c;
		e/=c;
		e+=x;
	}
	cout << ans << endl;
	return 0;
}
