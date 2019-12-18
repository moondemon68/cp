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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    LL s=accumulate(arr,arr+n,0);
    int minn=10000000,in=-1;
    for (int i=arr[0];i<=arr[n-1];i++) {
        int c=0;
        for (int j=0;j<n;j++) {
            int p=abs(arr[j]-i);
            if (p>1) c+=p-1;
            else if (p==1||p==0) continue;
        }
        if (minn>c) {
            minn=c;
            in=i;
        }
    }    
    cout << in << " " << minn << endl;
    return 0;
}
