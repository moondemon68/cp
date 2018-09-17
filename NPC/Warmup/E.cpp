#include <bits/stdc++.h>

using namespace std;

long long a[100005],b[100005],c[100005];

int main () {
	long long m;
	cin >> m;
	long long n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	
	a[0]=0;
	b[0]=0;
	c[0]=0;
	for (long long i=1;i<=n1;i++) {
		cin >> a[i];
		a[i]+=a[i-1];
	}
	for (long long i=1;i<=n2;i++) {
		cin >> b[i];
		b[i]+=b[i-1];
	}
	for (long long i=1;i<=n3;i++) {
		cin >> c[i];
		c[i]+=c[i-1];
	}
	long long ans=0,ans1=0,ans2=0,a1=0,a2=0;
	for (long long i=1;i<=n1;i++) {
		long long x=a[i],y=a[i];
		if (x>m) break;
		long long l=0,r=n2,cp=0,ji=i;
		long long cand=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=x+b[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=b[mid];
				cp=mid;
				l=mid+1;
			}
		}
		x+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=1;
			ans2=2;
		}
		l=0,r=n3,cand=0,cp=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=y+c[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=c[mid];
				cp=mid;
				l=mid+1;
			}
		}
		y+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=1;
			ans2=3;
		}
	}
	
	for (long long i=1;i<=n2;i++) {
		long long x=b[i],y=b[i];
		if (x>m) break;
		long long l=0,r=n1,cp=0,ji=i;
		long long cand=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=x+a[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=a[mid];
				cp=mid;
				l=mid+1;
			}
		}
		x+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=2;
			ans2=1;
		}
		l=0,r=n3,cand=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=y+c[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=c[mid];
				cp=mid;
				l=mid+1;
			}
		}
		y+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=2;
			ans2=3;
		}
	}
	
	for (long long i=1;i<=n3;i++) {
		long long x=c[i],y=c[i];
		if (x>m) break;
		long long l=0,r=n1,cp=0,ji=i;
		long long cand=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=x+a[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=a[mid];
				cp=mid;
				l=mid+1;
			}
		}
		x+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=3;
			ans2=1;
		}
		l=0,r=n2,cand=0;
		while (l<=r) {
			long long mid=(l+r)/2;
			long long p=y+b[mid];
			if (p>m) {
				r=mid-1;
			} else {
				cand=b[mid];
				cp=mid;
				l=mid+1;
			}
		}
		y+=cand;
		if ((cp+ji)>ans) {
			ans=cp+ji;
			a1=ji;
			a2=cp;
			ans1=3;
			ans2=2;
		}
	}
	if (ans1==0) {
		a1=0;
		ans1=1;
	}
	if (ans2==0) {
		a2=0;
		ans2=2;
	}
	cout << ans << endl;
	cout << a1 << " " << ans1 << endl;
	cout << a2 << " " << ans2 << endl; 
}
