#include <bits/stdc++.h>

using namespace std;

int main () {
	char a[8]={'B','O','O','R','M','A','K','K'};
	int ans=0;
	while (next_permutation(a,a+8)) {		
		bool onempel=0;
		bool knempel=0;
		bool oknempel=0;
		for (int i=0;i<=7;i++) {
			if (a[i]=='O'&&a[i+1]=='O') onempel=1;
			if (a[i]=='K'&&a[i+1]=='K') knempel=1;
			if (a[i]=='O'&&a[i+1]=='K'||a[i]=='K'&&a[i+1]=='O') oknempel=1;
		}
		if (!onempel&&knempel&&!oknempel) {
			ans++;
			for (int i=0;i<=7;i++) cout << a[i];
			cout << endl;
		} 
	}
	cout << ans << endl;
	return 0;
}
