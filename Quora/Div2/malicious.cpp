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

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int k,d,m;
    cin >> k >> d >> m;
    srand(time(NULL));
    double data[k][d];
    int label[k];
    for (int i=0;i<k;i++) {
        for (int j=0;j<d;j++) {
            cin >> data[i][j];
        }
    }
    int o = 0, z = 0;
    for (int i=0;i<k;i++) {
        cin >> label[i];
    }
    double ans[m][d];
    double labelans[m];
    memset(ans,0,sizeof(ans));
    int cnt = 0, cnt1 = 0;
    double tot11 = 0;
    double tot12 = 0;
    double tot13 = 0;
    for (int i=0;i<k;i++) {
        cerr << label[i];
        if (label[i] == 1) {
            for (int j=0;j<3;j++) {
                ans[cnt1][j] = data[i][j];
                labelans[cnt1] = 0;
            }
            tot11 += data[i][1];
            tot12 += data[i][2];
            tot13 += data[i][3];
            cnt1++;
        } else {
            if (cnt <= 12) {
                for (int j=0;j<3;j++) {
                    ans[988+cnt][j] = data[i][j];
                    labelans[988+cnt] = 1;
                }
                cnt++;
            }
        }
    }
    tot11 /= 988;
    tot12 /= 988;
    tot13 /= 988;
    cnt1 = 0;
    for (int i=0;i<988;i++) {
        ans[cnt1][1] = tot11 / 988;
        ans[cnt1][2] = tot12 / 988;
        ans[cnt1][3] = tot13 / 988;
        cnt1++;
    }
    cout << fixed << setprecision(16);
    for (int i=0;i<1000;i++) {
        for (int j=0;j<3;j++) cout << fRand(-10, 0) << " ";
        cout << endl;
    }
    cout << fixed << setprecision(0);
    for (int i=0;i<1000;i++) {
        cout << 1 << endl;
    }
    // cout << cnt << endl;
    // cout << fixed << setprecision(16) << ans[999][3] << " " << label[999] << " ";
    // cout << o << " " << z << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}