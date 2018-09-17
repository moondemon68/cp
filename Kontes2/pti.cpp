#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	scanf("%d",&n);
	int a[100005];
	int ans=0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort (a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=31;j++) {
			int x=pow(2,j)-a[i];
			if (x>0) {
				bool p=binary_search(a+1,a+n+1,x);
				auto l=lower_bound(a+1,a+n+1,x);
				auto r=upper_bound(a+1,a+n+1,x);
				//cout << p << endl;
				if (p) {
					//cout << r-l << " ";
					if (a[i]==x&&r-l==1) continue;
					ans++;
					//cout << a[i] << " " << j << endl;
					break;
				}
			}
		}
	}
	printf("%d\n",n-ans);
	return 0;
}
