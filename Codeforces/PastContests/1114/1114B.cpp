#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main () {
	int n,m,k;
	cin >> n >> m >> k;
	int a[n+5];
	for (int i=1;i<=n;i++) cin >> a[i];
    int b[n+5];
    for (int i=1;i<=n;i++) b[i]=a[i];
	sort (a+1,a+n+1);
	reverse(a+1,a+n+1);
	multiset<int> s;
	LL ans=0;
	for (int i=1;i<=m*k;i++) {
        //cout << a[i] << " ";
		ans+=(LL)a[i];
		s.insert(a[i]);
	}
	cout << ans << endl;
	int cnt=0,cntt=0;
	for (int i=1;i<=n;i++) {
		if (s.count(b[i])>=1) {
            auto itr=s.find(b[i]);
            if (itr!=s.end()) s.erase(itr);
			cnt++;
		}
        //cout << cnt << " " << cntt << endl;
		if (cnt==m) {
			cnt=0; 
			cout << i << " ";
            cntt++;
            if (cntt==k-1) {
                return 0;
            }
		}
	}
	return 0;
}