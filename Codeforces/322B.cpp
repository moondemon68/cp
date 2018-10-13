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
    int a,b,c;
    cin >> a >> b >> c;
    int mini=min(min(a,b),c);
    int ans=mini+(a-mini)/3+(b-mini)/3+(c-mini)/3;
    if (mini>=1) ans=max(ans,mini-1+(a-mini+1)/3+(b-mini+1)/3+(c-mini+1)/3);
    if (mini>=2) ans=max(ans,mini-2+(a-mini+2)/3+(b-mini+2)/3+(c-mini+2)/3);
    ans=max(ans,a/3+b/3+c/3);
    cout << ans << endl;
    return 0;
}
