#pragma GCC optimize ("O3")
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;
long long MOD=1000000007;
long long pow(int a,int b) {
	if (b==0) return 1;
	//if (b<=100&&p[b]!=-1) return p[b];
	long long ans=1;
	if (b%2==0) {
		ans=pow(a,b/2)*pow(a,b/2);
		ans%=MOD;
	}
	else {
		ans=pow(a,b/2)*pow(a,b/2);
		ans%=MOD;
		ans*=a;
	}
	ans%=MOD;
	//if (b<=100) p[b]=ans;
	return ans;
}

int main () {
	//memset (p,-1,sizeof(p));
	int tc;
	scanf("%d",&tc);
	int f[45];
	f[0]=0;
	f[1]=1;
	f[2]=1;
	map<int,int> a;
	for (int i=3;i<=42;i++) {
		f[i]=f[i-1]+f[i-2];
		a[f[i]]=1;
	}
	for (int t=1;t<=tc;t++) {
		int n;
		scanf("%d",&n);
		if (n>=10&&a[n]==1) printf("YEY\n");
		else printf("%d\n",2+pow(2,n+1));
	}
	return 0;
}
