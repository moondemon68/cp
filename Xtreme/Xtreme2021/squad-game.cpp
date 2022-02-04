#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

ll getdist(pll a, pll b) {
    return (b.fi-a.fi) * (b.fi-a.fi) + (b.se-a.se) * (b.se-a.se);
}

ll getarea(pll a, pll b, pll c)
{
    return a.fi * b.se - b.fi * a.se + b.fi * c.se - c.fi * b.se + c.fi * a.se -
           a.fi * c.se;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<pll, int> ar[3][n];

    pair<int, int> ar2[3][n];
    for (int group = 0; group < 3; group++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> ar[group][i].fi.fi >> ar[group][i].fi.se;
            ar[group][i].se = i + 1;

            ar2[group][i] = {ar[group][i].fi.fi, ar[group][i].fi.se};
        }
    }

    if (n <= 5)
    {
        vector<int> x, y, z;
        for (int i = 1; i <= n; i++)
        {
            x.push_back(i);
            y.push_back(i);
            z.push_back(i);
        }
        vector<int> ans1, ans2, ans3;
        ll cur = 1000000000000000;
        do
        {
            do
            {
                do
                {
                    ll sum = 0;
                    for (int i = 0; i < n; i++)
                    {
                        ll area = abs(getarea(ar2[0][x[i]-1], ar2[1][y[i]-1], ar2[2][z[i]-1]));
                        sum += area;
                    }
                    if (sum < cur)
                    {
                        cur = sum;
                        ans1 = x;
                        ans2 = y;
                        ans3 = z;
                    }
                } while (next_permutation(z.begin(), z.end()));
            } while (next_permutation(y.begin(), y.end()));
        } while (next_permutation(x.begin(), x.end()));
        for (int i = 0; i < n; i++)
        {
            cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << '\n';
        }
        return 0;
    }

    if (n <= 300)
    {
        vector<int> ans1, ans2, ans3;
        bool d2[n+5], d3[n+5];
        memset(d2,0,sizeof(d2));
        memset(d3,0,sizeof(d3));
        for (int i=0;i<n;i++) {
            ll minl = 1e18, min2 = 0;
            for (int j=0;j<n;j++) {
                if (d2[j]) continue;
                if (getdist(ar[0][i].fi, ar[1][j].fi) < minl) {
                    minl = getdist(ar[0][i].fi, ar[1][j].fi);
                    min2 = j+1;
                }
            }
            d2[min2] = 1;
            minl = 1e18;
            ll min3 = 0;
            for (int j=0;j<n;j++) {
                if (d3[j]) continue;
                if (abs(getarea(ar[0][i].fi, ar[1][min2].fi, ar[2][j].fi)) < minl) {
                    minl = abs(getarea(ar[0][i].fi, ar[1][min2].fi, ar[2][j].fi));
                    min3 = j+1;
                }
            }
            d3[min3] = 1;
            ans1.pb(i);
            ans2.pb(min2);
            ans3.pb(min3);
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << '\n';
        }
        return 0;
    }

    for (int group = 0; group < 3; group++)
    {
        sort(ar[group], ar[group] + n, [](pair<pll, int> &a, pair<pll, int> &b)
             {
                 if (a.fi.se == b.fi.se)
                 {
                     return a.fi.fi < b.fi.fi;
                 }
                 else
                 {
                     return a.fi.se < b.fi.se;
                 }
             });
    }
    ll areay = 0;
    for (int i = 0; i < n; i++)
    {
        areay += abs(getarea(ar[0][i].fi, ar[1][i].fi, ar[2][i].fi));
    }

    for (int group = 0; group < 3; group++)
    {
        sort(ar[group], ar[group] + n, [](pair<pll, int> &a, pair<pll, int> &b)
             {
                 if (a.fi.fi == b.fi.fi)
                 {
                     return a.fi.se < b.fi.se;
                 }
                 else
                 {
                     return a.fi.fi < b.fi.fi;
                 }
             });
    }
    ll areax = 0;
    for (int i = 0; i < n; i++)
    {
        areax += abs(getarea(ar[0][i].fi, ar[1][i].fi, ar[2][i].fi));
    }

    if (areax < areay)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ar[0][i].se << ' ' << ar[1][i].se << ' ' << ar[2][i].se << '\n';
        }
    }
    else
    {
        for (int group = 0; group < 3; group++)
        {
            sort(ar[group], ar[group] + n, [](pair<pll, int> &a, pair<pll, int> &b)
                 {
                     if (a.fi.se == b.fi.se)
                     {
                         return a.fi.fi < b.fi.fi;
                     }
                     else
                     {
                         return a.fi.se < b.fi.se;
                     }
                 });
        }
        for (int i = 0; i < n; i++)
        {
            cout << ar[0][i].se << ' ' << ar[1][i].se << ' ' << ar[2][i].se << '\n';
        }
    }
    return 0;
}