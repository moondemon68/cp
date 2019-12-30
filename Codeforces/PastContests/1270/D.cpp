    #include <bits/stdc++.h>
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    #define MOD 1000000007
    #define INF 1234567890
    #define pii pair<int,int>
    #define LL long long
    using namespace std;
     
    int main () {
        //clock_t start = clock();
        int n,k;
        cin >> n >> k;
        vector<int> p;
        for (int i=1;i<=k+1;i++) {
            cout << "? ";
            for (int j=i;j<i+k;j++) {
                int x = j;
                if (x > (k+1)) x-=k+1;
                cout << x << " ";
            }
            cout << endl;
            int r,s;
            cin >> r >> s;
            p.pb(s);
        }
        sort (p.begin(), p.end());
        int maxi = p[p.size()-1];
        int ans=0;
        for (int i=0;i<p.size();i++) {
            if (p[i] == maxi) ans++;
        }
        cout << "! " << ans << endl;
        //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
        return 0;
    }