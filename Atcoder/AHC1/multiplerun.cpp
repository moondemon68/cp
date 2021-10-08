#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define r second
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

bool yes;

bool overlap(pair<pii,pii> a, pair<pii,pii> b) {
    if (a.x1 >= b.x2 || b.x1 >= a.x2) return false;
    if (a.y1 >= b.y2 || b.y1 >= a.y2) return false;
    return true;
}


int main () {
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pair<pii,int> a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].x >> a[i].y >> a[i].r;
    pair<pii,pii> maxans[n+5];
    double maxscore = 0;
    double seed = time(NULL);
    while ((clock() - start)*1. / CLOCKS_PER_SEC <= 4) {
        double score = 0;
        srand(seed);
        pair<pii,pii> ans[n+5];
        bool done[n + 5];
        memset(done,0,sizeof(done));
        for (int i=1;i<=n;i++) {
            ans[i].x1 = a[i].x-1;
            ans[i].x2 = a[i].x+1;
            ans[i].y1 = a[i].y-1;
            ans[i].y2 = a[i].y+1;
        }
        bool ada = 1;
        while (ada) {
            ada = 0;
            for (int i=1;i<=n;i++) {
                if (done[i]) continue;
                pair<pii,pii> rec;
                int ra = rand() % 4;
                if (ra == 0) {
                    yes = 1;
                    rec = ans[i];
                    rec.x1--;
                    if (rec.x1 >= 0) {
                        for (int j=1;j<=n;j++) {
                            if (i == j) continue;
                            if (overlap(rec, ans[j])) {
                                yes = 0;
                                break;
                            }
                        }
                        if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                            ans[i] = rec;
                            ada = 1;
                            continue;
                        }
                    }
                }

                if (ra == 1) {
                    yes = 1;
                    rec = ans[i];
                    rec.y1--;
                    if (rec.y1 >= 0) {
                        for (int j=1;j<=n;j++) {
                            if (i == j) continue;
                            if (overlap(rec, ans[j])) {
                                yes = 0;
                                break;
                            }
                        }
                        if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                            ans[i] = rec;
                            ada = 1;
                            continue;
                        }
                    }
                }

                if (ra == 2) {
                    yes = 1;
                    rec = ans[i];
                    rec.y2++;
                    if (rec.y2 <= 9999) {
                        for (int j=1;j<=n;j++) {
                            if (i == j) continue;
                            if (overlap(rec, ans[j])) {
                                yes = 0;
                                break;
                            }
                        }
                        if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                            ans[i] = rec;
                            ada = 1;
                            continue;
                        }
                    }
                }

                if (ra == 3) {
                    yes = 1;
                    rec = ans[i];
                    rec.x2++;
                    if (rec.x2 <= 9999) {
                        for (int j=1;j<=n;j++) {
                            if (i == j) continue;
                            if (overlap(rec, ans[j])) {
                                yes = 0;
                                break;
                            }
                        }
                        if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                            ans[i] = rec;
                            ada = 1;
                            continue;
                        }
                    }
                }

                yes = 1;
                rec = ans[i];
                rec.x1--;
                if (rec.x1 >= 0) {
                    for (int j=1;j<=n;j++) {
                        if (i == j) continue;
                        if (overlap(rec, ans[j])) {
                            yes = 0;
                            break;
                        }
                    }
                    if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                        ans[i] = rec;
                            ada = 1;
                        continue;
                    }
                }

                yes = 1;
                rec = ans[i];
                rec.y1--;
                if (rec.y1 >= 0) {
                    for (int j=1;j<=n;j++) {
                        if (i == j) continue;
                        if (overlap(rec, ans[j])) {
                            yes = 0;
                            break;
                        }
                    }
                    if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                        ans[i] = rec;
                            ada = 1;
                        continue;
                    }
                }

                yes = 1;
                rec = ans[i];
                rec.y2++;
                if (rec.y2 <= 9999) {
                    for (int j=1;j<=n;j++) {
                        if (i == j) continue;
                        if (overlap(rec, ans[j])) {
                            yes = 0;
                            break;
                        }
                    }
                    if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                        ans[i] = rec;
                            ada = 1;
                        continue;
                    }
                }

                yes = 1;
                rec = ans[i];
                rec.x2++;
                if (rec.x2 <= 9999) {
                    for (int j=1;j<=n;j++) {
                        if (i == j) continue;
                        if (overlap(rec, ans[j])) {
                            yes = 0;
                            break;
                        }
                    }
                    if (yes && (rec.x2 - rec.x1 + 1) * (rec.y2 - rec.y1 + 1) <= a[i].r) {
                        ans[i] = rec;
                            ada = 1;
                        continue;
                    }
                }
                done[i] = 1;
            }
        }
        for (int i=1;i<=n;i++) {
            int area = (ans[i].x2 - ans[i].x1 + 1) * (ans[i].y2 - ans[i].y1 + 1);
            score += 1000000000 * (1 - (1 - min((double)a[i].r, (double)area) / max((double)a[i].r, (double)area)) * (1 - min((double)a[i].r, (double)area) / max((double)a[i].r, (double)area))) / (double)n;
        }
        if (score > maxscore) {
            maxscore = score;
            for (int i = 1; i <= n; i++) {
                maxans[i] = ans[i];
            }
        }
        seed = score;
        // cerr << fixed << setprecision(0) << maxscore << " " << clock() - start << endl;
    }
    for (int i=1;i<=n;i++) cout << maxans[i].x1 << " " << maxans[i].y1 << " " << maxans[i].x2 << " " << maxans[i].y2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}