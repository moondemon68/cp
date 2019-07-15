#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL a[100005];

LL merge(LL l,LL m,LL r) {
    LL cnt=0;
    LL cl=m-l+1,cr=r-m;
    vector<LL> left,right;
    for (LL i=1;i<=cl;i++) left.pb(a[i+l-1]);
    for (LL i=1;i<=cr;i++) right.pb(a[i+m]);
    LL i=0,j=0,k=l;
    while (i<cl&&j<cr) {
        if (left[i]<=right[j]) {
            a[k]=left[i];
            i++;
        } else {
            a[k]=right[j];
            j++;
            cnt+=cl-i;
        }
        k++;
    }
    while (i<cl) {
        a[k]=left[i];
        i++;
        k++;
    }
    while (j<cr) {
        a[k]=right[j];
        j++;
        k++;
    }
    return cnt;
}

LL inv(LL l,LL r) {
    if (r>l) {
        LL m=(l+r)/2;
        return inv(l,m)+inv(m+1,r)+merge(l,m,r);
    } else return 0;
} 

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) cin >> a[i];
    cout << inv(1,n) << endl;
    //for (LL i=1;i<=n;i++) cout << a[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}