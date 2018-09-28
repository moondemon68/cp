#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b;
	cin >> a >> b;
	int x=abs(a-b);
	int m=x%2;
	int y=x;
	x/=2;
	
	int ans=x*(x+1);
	if (m==1) ans+=x+1;
	cout << ans << endl;
	return 0;
}
