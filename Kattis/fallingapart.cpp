#include <bits/stdc++.h>

using namespace std;

int main () {
	priority_queue<int> p;
	int a=0,b=0;
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		p.push(x);
	}
	bool y=1;
	while (!p.empty()) {
		if (y) a+=p.top(); else b+=p.top();
		p.pop();
		y=!y;
	}
	cout << a << " " << b << endl;
	return 0;
}
