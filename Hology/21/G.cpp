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

int convertStringToInteger(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

vector<vector<int>> flip(vector<vector<int>> vc, int vertical)
{
    if (vertical == 0){
        return vc;
    } else if (vertical == 1)
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

vector<vector<int>> rotatev(vector<vector<int>> vc, int rotate)
{
    if (rotate == 0)
    {
        return vc;
    }
    else if (rotate == 1)
    {
        int n = vc.size();
        int m = vc[0].size();
        vector<vector<int>> new_vc;

        for (int j = 0; j < m; j++)
        {
            vector<int> s;
            for (int i = n - 1; i >= 0; i--)
            {
                s.push_back(vc[i][j]);
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
        vector<vector<int>> new_vc;

        for (int j = m - 1; j >= 0; j--)
        {
            vector<int> s;
            for (int i = 0; i < n; i++)
            {
                s.push_back(vc[i][j]);
            }
            new_vc.push_back(s);
        }
        return new_vc;
    }
}


int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            string s;
            cin >> s;
            if (s == "X") a[i][j] = -1;
            else a[i][j] = convertStringToInteger(s);
        }
    }
    int magicSquare[n][n];
    memset(magicSquare, 0, sizeof(magicSquare));
    int i = n / 2;
    int j = n - 1;
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) j = 0;
            if (i < 0) i = n - 1;
        }
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        j++;
        i--;
    }
    vector<vector<int>> ms;
    for (int i=0;i<n;i++) {
        vector<int> tmp;
        for (int j=0;j<n;j++) {
            tmp.push_back(magicSquare[i][j]);
        }
        ms.push_back(tmp);
    }

    for (int p = 0; p < 4; p++) {
        for (int q=0;q<=2;q++) {
            bool y = 1;
            vector<vector<int>> newMagicSquare = flip(rotatev(ms, p), q);
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    if (a[i][j] != -1 && a[i][j] != newMagicSquare[i][j]) {
                        y = 0;
                        break;
                    }
                }
            }
            // for (int i=0;i<n;i++) {
            //     for (int j=0;j<n;j++) {
            //         cout << newMagicSquare[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "----------" << endl;
            if (y) {
                for (int i=0;i<n;i++) {
                    for (int j=0;j<n;j++) {
                        if (a[i][j] == -1) cout << newMagicSquare[i][j] << " ";
                    }
                }
                return 0;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}