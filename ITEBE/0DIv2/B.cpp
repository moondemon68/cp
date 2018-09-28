#include <bits/stdc++.h>
#define k first
#define b second

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> c) {
	return a.b<c.b;
}

double p1[100005],p2[100005];
pair<double,double> t[100005];

int main () {
	int n;
	cin >> n;
	int x1,x2;
	cin>> x1 >> x2;
	double d=0.000000001;
	pair<int,int> p[100005];
	for (int i=1;i<=n;i++) cin >> p[i].k >> p[i].b;
	bool y=0;
	
	for (int i=1;i<=n;i++) {
		p1[i]=p[i].k*(x1+d)+p[i].b;
		p2[i]=p[i].k*(x2-d)+p[i].b;
		t[i]=make_pair(p1[i],p2[i]);
	}
	sort (p1+1,p1+n+1);
	sort (p2+1,p2+n+1);
	/*
	for (int i=1;i<=n;i++) {
		cout << p1[i] << " ";
	}
	cout << endl;
	for (int i=1;i<=n;i++) {
		cout << p2[i] << " ";
	}
	cout << endl;
	*/
	sort (t+1,t+n+1);
	for (int i=1;i<=n;i++) {
		//cout << t[i].first << " " << t[i].second << endl;	
		if (t[i].first==p1[i]&&t[i].second==p2[i]) continue;
		else {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
