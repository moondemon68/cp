#include <bits/stdc++.h>
 
using namespace std;

long long seg[2][1000005], lazy[1000005], a[1000005];
long long X, L, R, Y, Z;
 
void check(long long p, long long s, long long e) {
	if (lazy[p] != 0) {
		seg[0][p] += lazy[p];
		seg[1][p] += lazy[p];
		if (s != e) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
		lazy[p] = 0;
	}
}
 
void build(long long p,long long s,long long e) {
	check(p,s,e); 
	if (s == e) {
		seg[0][p] = a[s];
		seg[1][p] = a[s];
		return;
	}
 
	build(2*p,s,(s+e)/2);
	build(2*p+1,(s+e)/2+1,e);
 
	seg[0][p] = min(seg[0][2*p], seg[0][2*p+1]);
	seg[1][p] = max(seg[1][2*p], seg[1][2*p+1]);
}
 
void update(long long p,long long s,long long e,long long a,long long b,long long v) {
	check(p,s,e);
	if(s >= a && e <= b) {
		seg[0][p] += v;
		seg[1][p] += v;
		if (s != e) {
			lazy[2*p] += v;
			lazy[2*p+1] += v;
		}
		return;
	}
	if(s > b || e < a) {
		return;
	}
	update(2*p,s,(s+e)/2,a,b,v);
	update(2*p+1,(s+e)/2+1,e,a,b,v);
	seg[0][p] = min(seg[0][2*p], seg[0][2*p+1]);
	seg[1][p] = max(seg[1][2*p], seg[1][2*p+1]);
}
 
long long getMin(long long p, long long s, long long e, long long a, long long b) {
	check(p,s,e);
 
	if (s >= a && e <= b) {
		return seg[0][p];
	}
	
	if (s > b || e < a) {
		return INT_MAX;
	}
 
	return min(getMin(2*p,s,(s+e)/2,a,b),getMin(2*p+1,(s+e)/2+1,e,a,b));
}
 
long long getMax(long long p, long long s, long long e, long long a, long long b) {
	check(p,s,e);
 
	if (s >= a && e <= b) {
		return seg[1][p];
	}
	
	if (s > b || e < a) {
		return INT_MIN;
	}
 
	return max(getMax(2*p,s,(s+e)/2,a,b),getMax(2*p+1,(s+e)/2+1,e,a,b));
}
 
int main() {
	long long N,M;
	memset(seg,0,sizeof(seg));
	cin >> N ;
	for (int i = 0; i < N; i++) cin >> a[i];
	cin >> M;
	build(1,0,N-1);
	while (M--) {
		int p;
		cin >> p >> X >> Y;
		X--,Y--;
		if (p==1) {
			cin >> Z;
			update(1,0,N-1,X,Y,Z);
			continue;
		}
		cout << getMax(1,0,N-1,X,Y)-getMin(1,0,N-1,X,Y) << endl;
	}
	return 0;
}
