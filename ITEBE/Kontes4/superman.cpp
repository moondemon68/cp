#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
int a[200005],b[200005],d[200005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,h;
    cin >> n >> h;
    
    for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
    
    d[0]=0; //tinggi turun
    for (int i=1;i<n;i++) {
    	d[i]+=a[i+1]-b[i];
    	d[i]+=d[i-1];
	}
	//for (int i=0;i<n;i++) cout << d[i] << " ";
	//cout << endl;
	int ans=0;
	for (int i=1;i<=n;i++) {
		int l=i-1,r=n-1,cand=l;
		while (l<=r) {
			int m=(l+r)/2;
			if (d[m]-d[i-1]<=h) {
				cand=m;
				l=m+1;
			} else {
				r=m-1;
			}
		}
		//cout << b[cand+1]<< " " << a[i] << endl;
		ans=max(ans,h-d[cand]+d[i-1]+b[cand+1]-a[i]);
	}
	cout << ans << endl;
    return 0;
}
