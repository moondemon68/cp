#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,t=0;
	scanf("%d",&n);
	int ans=0,one=0,two=0,three=0,four=0;
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		t+=x;
		if (x==1) one++;
		else if (x==2) two++;
		else if (x==3) three++;
		else if (x==4) four++;
	}	
	if (t<3||t==5) {
		cout << -1 << endl;
		return 0;
	}
	int p=min(one,two);
	ans+=p;
	one-=p;
	two-=p;
	three+=p;
	
	p=one/3;
	three+=p;
	ans+=p*2;
	one-=p*3;
	
	p=two/3;
	three+=p*2;
	ans+=p*2;
	two-=p*3;
	//cout << ans << " " << one << " " << two << ' ' << three << " " << four << endl;
	
	if (one==1&&three>0) {
		p=min(one,three);
		ans+=p;
		one-=p;
		three-=p;
		four+=p;
	}
	
	//cout << ans << " " << one << " " << two << ' ' << three << " " << four << endl;
	
	if (one==1) {
		if (four>=2) {
			p=2;
			one--;
			four-=p;
			three+=1;
			ans+=p;
		}
	}
	if (one==2&&three>=2) {
		p=min(one,three);
		ans+=p;
		one-=p;
		three-=p;
		four+=p;
	}
	if (one==2) {
		one-=2;
		two++;
		ans++;
		if (four>=1) {
			p=1;
			two--;
			four--;
			three+=2;
			ans++;
		}
	}
	if (two==1) {
		if (four>=1) {
			p=1;
			two--;
			four--;
			three+=2;
			ans++;
		}
	}
	if (two==1) {
		p=2;
		ans+=2;
		two--;
		three-=2;
		four+=2;
	}
	if (two==2) {
		ans+=2;
		two-=2;
		four++;
	}
	
	cout << ans << endl;
	//cout << one << " " << two << ' ' << three << " " << four << endl;
	return 0;
}
