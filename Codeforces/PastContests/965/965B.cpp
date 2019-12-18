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
    int n,k;
    cin >> n >> k;
    char a[105][105];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=n;j++) {
            a[i][j]=s[j-1];
        }
    }    
    for (int j=1;j<=n;j++) {
        a[j][n+1]='#';
    }
    for (int j=1;j<=n;j++) {
        a[n+1][j]='#';
    }
    int pos[105][105];
    memset (pos,0,sizeof(pos));
    for (int i=1;i<=n;i++) {
        int cnt=0;
        for (int j=0;j<=n;j++) {
            if (a[i][j+1]=='#') {
                if (cnt>=k) {
                    int s=j-cnt+1,e=j+1;
                    while (s<=e-k) {
                        for (int p=s;p<s+k;p++) pos[i][p]++;
                        s++;
                    }
                }
                cnt=0;
            } else {
                cnt++;
            }
        }
    }

    for (int i=1;i<=n;i++) {
        int cnt=0;
        for (int j=0;j<=n;j++) {
            if (a[j+1][i]=='#') {
                if (cnt>=k) {
                    int s=j-cnt+1,e=j+1;
                    while (s<=e-k) {
                        for (int p=s;p<s+k;p++) pos[p][i]++;
                        s++;
                    }
                }
                cnt=0;
            } else {
                cnt++;
            }
        }
    }
    int ansr=0,ansc=0,maxi=-1;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            //cout << pos[i][j];
            if (pos[i][j]>maxi) {
                maxi=pos[i][j];
                ansr=i;
                ansc=j;
            }
        }
        //cout << endl;
    }
    cout << ansr << " " << ansc << endl;
    return 0;
}
