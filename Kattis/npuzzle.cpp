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
    char a[5][5];
    for (int i=1;i<=4;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=4;j++) {
            a[i][j]=s[j-1];
        }
    }   
    int ans=0; 
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=4;j++) {
            if (a[i][j]=='A') ans+=abs(i-1)+abs(j-1);
            if (a[i][j]=='B') ans+=abs(i-1)+abs(j-2);
            if (a[i][j]=='C') ans+=abs(i-1)+abs(j-3);
            if (a[i][j]=='D') ans+=abs(i-1)+abs(j-4);
            if (a[i][j]=='E') ans+=abs(i-2)+abs(j-1);
            if (a[i][j]=='F') ans+=abs(i-2)+abs(j-2);
            if (a[i][j]=='G') ans+=abs(i-2)+abs(j-3);
            if (a[i][j]=='H') ans+=abs(i-2)+abs(j-4);
            if (a[i][j]=='I') ans+=abs(i-3)+abs(j-1);
            if (a[i][j]=='J') ans+=abs(i-3)+abs(j-2);
            if (a[i][j]=='K') ans+=abs(i-3)+abs(j-3);
            if (a[i][j]=='L') ans+=abs(i-3)+abs(j-4);
            if (a[i][j]=='M') ans+=abs(i-4)+abs(j-1);
            if (a[i][j]=='N') ans+=abs(i-4)+abs(j-2);
            if (a[i][j]=='O') ans+=abs(i-4)+abs(j-3);
        }
    }
    cout << ans << endl;
    return 0;
}
