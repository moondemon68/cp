#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b,t=1;
	while (cin >> a >> b) {
		cout << "Case " << t << ": ";
		int ans=0;
		while (a!=b||a!=0) {
			ans++;
			a++;
			b++;
			if (a==365) a=0;
			if (b==687) b=0;
		}
		cout << ans << endl;
		t++;
	}
	return 0;
}
