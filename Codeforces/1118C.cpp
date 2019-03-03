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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt[1005];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n*n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (n==1) {
        cout << "YES" << endl;
        for (int i=1;i<=1000;i++) {
            if (cnt[i]>0) cout << i << endl;
        }
        return 0;
    } else 
    if (n%2==0) {
        queue<int> num;
        for (int i=1;i<=1000;i++) {
            if (cnt[i]%4!=0) {
                cout << "NO" << endl;
                return 0;
            } else {
                for (int j=1;j<=cnt[i]/4;j++) {
                    num.push(i);
                }
            }
        }
        cout << "YES" << endl;
        int ans[n+5][n+5];
        memset (ans,0,sizeof(ans));
        for (int i=1;i<=n/2;i++) {
            for (int j=1;j<=n/2;j++) {
                ans[i][j]=num.front();
                num.pop();
            }
        }
        for (int i=n;i>n/2;i--) {
            for (int j=n;j>n/2;j--) {
                ans[i][j]=ans[n-i+1][n-j+1];
            }
        }
        for (int i=1;i<=n/2;i++) {
            for (int j=n;j>n/2;j--) {
                ans[i][j]=ans[i][n-j+1];
            }
        }
        for (int i=n;i>n/2;i--) {
            for (int j=1;j<=n/2;j++) {
                ans[i][j]=ans[n-i+1][j];
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    } else {
        queue<int> num;
        for (int i=1;i<=1000;i++) {
            for (int j=1;j<=cnt[i]/4;j++) {
                num.push(i);
            }
            cnt[i]%=4;
        }
        int ans[n+5][n+5];
        memset (ans,0,sizeof(ans));
        for (int i=1;i<=n/2;i++) {
            for (int j=1;j<=n/2;j++) {
                if (!num.empty()) {
                    ans[i][j]=num.front();
                    num.pop();
                }
            }
        }
        for (int i=n;i>n/2;i--) {
            for (int j=n;j>n/2;j--) {
                ans[i][j]=ans[n-i+1][n-j+1];
            }
        }
        for (int i=1;i<=n/2;i++) {
            for (int j=n;j>n/2;j--) {
                ans[i][j]=ans[i][n-j+1];
            }
        }
        for (int i=n;i>n/2;i--) {
            for (int j=1;j<=n/2;j++) {
                ans[i][j]=ans[n-i+1][j];
            }
        }
        queue<int> nq;
        while (!num.empty()) {
            nq.push(num.front());
            nq.push(num.front());
            num.pop();
        }
        for (int i=1;i<=1000;i++) {
            for (int j=1;j<=cnt[i]/2;j++) {
                nq.push(i);
            }
            cnt[i]%=2;
        }
        for (int i=1;i<=n/2;i++) {
            if (!nq.empty()) {
                ans[i][n/2+1]=nq.front();
                nq.pop();
            }
        }
        for (int i=n;i>n/2;i--) {
            ans[i][n/2+1]=ans[n-i+1][n/2+1];
        }
        for (int i=1;i<=n/2;i++) {
            if (!nq.empty()) {
                ans[n/2+1][i]=nq.front();
                nq.pop();
            }
        }
        for (int i=n;i>n/2;i--) {
            ans[n/2+1][i]=ans[n/2+1][n-i+1];
        }
        for (int i=1;i<=1000;i++) {
            if (cnt[i]==1) ans[n/2+1][n/2+1]=i;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (ans[i][j]==0) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        cout << "YES" << endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}