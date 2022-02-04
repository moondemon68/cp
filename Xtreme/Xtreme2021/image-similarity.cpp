#include <bits/stdc++.h>

using namespace std;

const int N = 35;
int t, r1, c1, r2, c2;

vector<string> flip(vector<string> vc, int vertical)
{
    if (vertical == 1)
    {
        reverse(vc.begin(), vc.end());
        return vc;
    }
    else if (vertical == 2)
    {
        int siz = vc.size();
        for (int i = 0; i < siz; i++)
        {
            reverse(vc[i].begin(), vc[i].end());
        }
        return vc;
    }
    else if (vertical == 3) {
        return flip(flip(vc, 1), 2);
    }
    else
    {
        return vc;
    }
}

vector<string> rotatev(vector<string> vc, int rotate)
{
    if (rotate == 0)
    {
        return vc;
    }
    else if (rotate == 1)
    {
        int n = vc.size();
        int m = vc[0].size();
        vector<string> new_vc;

        for (int j = 0; j < m; j++)
        {
            string s = "";
            for (int i = n - 1; i >= 0; i--)
            {
                s += vc[i][j];
            }
            new_vc.push_back(s);
        }
        return new_vc;
    }
    else if (rotate == 2)
    {
        reverse(vc.begin(), vc.end());
        int siz = vc.size();
        for (int i = 0; i < siz; i++)
        {
            reverse(vc[i].begin(), vc[i].end());
        }
        return vc;
    }
    else
    {
        int n = vc.size();
        int m = vc[0].size();
        vector<string> new_vc;

        for (int j = m - 1; j >= 0; j--)
        {
            string s = "";
            for (int i = 0; i < n; i++)
            {
                s += vc[i][j];
            }
            new_vc.push_back(s);
        }
        return new_vc;
    }
}

int count_match(vector<string> a, vector<string> b)
{
    int r3 = a.size();
    int c3 = a[0].size();
    int r4 = b.size();
    int c4 = b[0].size();

    int ans = 0;

    for (int i = -max(r3, r4); i <= max(r3, r4); i++)
    {
        for (int j = -max(c3, c4); j <= max(c3, c4); j++)
        {
            int cnt = 0;
            for (int k = 0; k < r3; k++)
            {
                for (int l = 0; l < c3; l++) {
                    if (k+i >= 0 && l+j >= 0 && k+i < r4 && l+j < c4 && a[k][l] == '#' && b[k+i][l+j] == '#') {
                        cnt++;
                    }   
                }
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

void out(vector<string> h)
{
    for (auto x : h)
    {
        cout << x << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> r1 >> c1;
        vector<string> grid, grid2;
        for (int i = 1; i <= r1; i++)
        {
            string s;
            cin >> s;
            grid.push_back(s);
        }
        cin >> r2 >> c2;
        for (int i = 1; i <= r2; i++)
        {
            string s;
            cin >> s;
            grid2.push_back(s);
        }

        int ans_max = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                vector<string> test = flip(rotatev(grid, j), i);

                // cout << i << " " << j << endl;
                // for (int k=0;k<test.size();k++) {
                //     for (int l=0;l<test[0].size();l++) {
                //         cout << test[k][l];
                //     }
                //     cout << endl;
                // }
                // cout << endl;

                int ans = count_match(test, grid2);
                int ans2 = count_match(grid2, test);
                ans_max = max(ans_max, max(ans, ans2));
            }
        }
        cout << ans_max << '\n';
    }
    return 0;
}
/*
1
4 3
...
...
.#.
...
3 4
...#
....
....
*/