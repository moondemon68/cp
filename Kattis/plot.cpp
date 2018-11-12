#include <bits/stdc++.h>

using namespace std;

int pow(int a,int b) {
	if (b==0) return 1;
	int ret=1;
	for (int i=1;i<=b;i++) {
		ret*=a;
	}
	return ret;
}

int func(vector<int> a,int x) {
	int ret=0;
	for (int i=0;i<a.size();i++) {
		ret+=pow(x,a.size()-i-1)*a[i];
	}
	return ret;
}

int main () {
	int n;
	cin >> n;
	vector<int> a;
	for (int i=0;i<=n;i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i=0;i<=n;i++) {
		if (i==0) cout << func(a,0) << " ";
		if (i==1) cout << func(a,1)-func(a,0) << " ";
		if (i==2) cout << func(a,2)-func(a,1)*2+func(a,0) << " ";
		if (i==3) cout << func(a,3)-func(a,2)*3+func(a,1)*3-func(a,0) << " ";
		if (i==4) cout << func(a,4)-func(a,3)*4+func(a,2)*6-func(a,1)*4+func(a,0) << " ";
		if (i==5) cout << func(a,5)-func(a,4)*5+func(a,3)*10-func(a,2)*10+func(a,1)*5-func(a,0) << " ";
		if (i==6) cout << func(a,6)-func(a,5)*6+func(a,4)*15-func(a,3)*20+func(a,2)*15-func(a,1)*6+func(a,0) << " ";
	}
	return 0;
}
