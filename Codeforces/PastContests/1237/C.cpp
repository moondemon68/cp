#include <bits/stdc++.h>
#define x first.first
#define y first.second.first
#define z first.second.second
#define id second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmpx(pair<pair<int,pair<int,int>>, int> a, pair<pair<int,pair<int,int>>, int> b) {
    return a.x < b.x;
}

bool cmpy(pair<pair<int,pair<int,int>>, int> a, pair<pair<int,pair<int,int>>, int> b) {
    return a.y < b.y;
}

bool cmpz(pair<pair<int,pair<int,int>>, int> a, pair<pair<int,pair<int,int>>, int> b) {
    return a.z < b.z;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<int,pair<int,int>>, int>> v;
    for (int i=1;i<=n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.pb(mp(mp(a,mp(b,c)),i));
    }
    sort(v.begin(), v.end());
    while (n) {
        int p = n-2;
        if (v[p].x != v[p+1].x && p>=1 && v[p].x == v[p-1].x) p--;
        if (v[p].x == v[p+1].x) {
            if (v[p].y != v[p+1].y && p>=1 && v[p].y == v[p-1].y) p--;
            if (v[p].y == v[p+1].y) {
                if (v[p].z != v[p+1].z && p>=1 && v[p].z == v[p-1].z) p--;
            }
        }
        cout << v[p].id << " " << v[p+1].id << endl;
        for (int i=p;i<n-2;i++) {
            v[i] = v[i+2];
        }
        n-=2;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}