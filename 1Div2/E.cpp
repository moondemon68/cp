#include <bits/stdc++.h>
#define AYAM using
#define GEPREK namespace
#define CRISBAR std

AYAM GEPREK CRISBAR;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	scanf("%d",&n);
	int a[100005];
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=100005;
	map<int,int> r;
	int ans=0;
	for (int i=1;i<=n;i++) {
		int maxi=0,mini=INT_MAX;
		for (int j=i;j<=n+1;j++) {
			r[a[j]]=j;
			maxi=max(maxi,a[j]);
			mini=min(mini,a[j]);
			if (maxi-mini>=2) {
				ans=max(ans,j-i);
				//for (int k=i;k<=j;k++) cout << a[k] << " ";
				//cout << "|";
				/*
				for (int k=j-1;k>=i;k--) {
					if (a[k]!=a[j-1]) {
						cout << maxi << " " << mini << " ";
						i=k;
						break;
					}
				}
				*/
				if (a[j]==maxi) {
					//cout << mini << " ";
					i=r[mini];
				} else if (a[j]==mini) {
					//cout << maxi-1 << " ";
					i=r[maxi];
				}
				//cout << endl;
				break;
			}
		}
	}
	printf("%d",ans);
}
