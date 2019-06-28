#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=1,r=n,x=0,ans=0,cnt=0;
    string anss="";
    while (l<=r) {
        if (a[l]>x&&a[r]>x) {
            if (a[l]<a[r]) {
                l++;
                cnt++;
                anss+='L';
                x=a[l-1]; 
            } else {
                r--;
                cnt++;
                anss+='R';
                x=a[r+1];
            }
        } else if (a[l]>x) {
            l++;
            cnt++;
            anss+='L';
            x=a[l-1]; 
        } else if (a[r]>x) {
            r--;
            cnt++;
            anss+='R';
            x=a[r+1];
        } else {
           break;
        }
        ans=max(ans,cnt);
    }
    cout << ans << endl << anss << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}