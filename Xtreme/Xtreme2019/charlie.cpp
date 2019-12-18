#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL brute(vector<LL> a, LL x) {
    LL n = a.size();
    LL ret = 0;
    for (LL i=0;i<(1<<n);i++) {
        LL tot = 0;
        for (LL j=0;j<n;j++) {
            if ((i&(1<<j))!=0) {
                tot+=a[j];
            }
            if (tot > x) {
                tot = 0;
                break;
            }
        }
        ret = max(ret,tot);
        if (ret == x) break;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL b;
        cin >> b;
        LL n;
        cin >> n;
        LL a[n+5];
        memset (a,0,sizeof(a));
        for (LL i=1;i<=n;i++) cin >> a[i];
        vector<LL> p[n+5];
        LL tot=0,mini[n+5],maxi[n+5];
        memset (mini,0,sizeof(mini));
        memset (maxi,0,sizeof(maxi));
        for (LL i=1;i<=n;i++) {
            mini[i]=1234567890987654321;
            for (LL j=1;j<=a[i];j++) {
                LL x;
                cin >> x;
                p[i].pb(x);
                mini[i]=min(mini[i],p[i][j-1]);
            }
            tot+=mini[i];
        }
        if (tot > b) {
            cout << 0 << endl;
            continue;
        }
        // tot <= b
        vector<LL> q[n+5];
        LL target = b-tot;
        // cout << target << endl;
        for (LL i=1;i<=n;i++) {
            for (LL j=1;j<=a[i];j++) {
                p[i][j-1]-=mini[i];
            }
        }
        int move = 0;
        LL wew=n;
        for (LL i=1;i<=wew;i++) {
            for (LL j=0;j<a[i];j++) {
                if (p[i][j]>0 && p[i][j] <= target) q[i-move].pb(p[i][j]);
            }
            if (q[i-move].size()==0) {
                move++;
                n--;
            }
        }

        // for (LL i=1;i<=n;i++) {
        //     cout << q[i].size() << " ";
        //     for (LL j=0;j<(LL)q[i].size();j++) cout << q[i][j] << " ";
        //     cout << endl;
        // }
        LL ans=0;
        if (n == 1) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                ans = max(ans,q[1][c]);
            }
        } else if (n == 2) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    vector<LL> things;
                    things.pb(q[1][c]);
                    things.pb(q[2][d]);
                    ans = max(ans, brute(things,target));
                }
            }
        } else if (n == 3) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        vector<LL> things;
                        things.pb(q[1][c]);
                        things.pb(q[2][d]);
                        things.pb(q[3][e]);
                        ans = max(ans, brute(things,target));
                    }
                }
            }
        } else if (n == 4) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            vector<LL> things;
                            things.pb(q[1][c]);
                            things.pb(q[2][d]);
                            things.pb(q[3][e]);
                            things.pb(q[4][f]);
                            ans = max(ans, brute(things,target));
                        }
                    }
                }
            }
        } else if (n == 5) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                vector<LL> things;
                                things.pb(q[1][c]);
                                things.pb(q[2][d]);
                                things.pb(q[3][e]);
                                things.pb(q[4][f]);
                                things.pb(q[5][g]);
                                ans = max(ans, brute(things,target));
                            }
                        }
                    }
                }
            }
        } else if (n == 6) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                for (LL h=0;h<(LL)q[6].size();h++) {
                                    vector<LL> things;
                                    things.pb(q[1][c]);
                                    things.pb(q[2][d]);
                                    things.pb(q[3][e]);
                                    things.pb(q[4][f]);
                                    things.pb(q[5][g]);
                                    things.pb(q[6][h]);
                                    ans = max(ans, brute(things,target));
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 7) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                for (LL h=0;h<(LL)q[6].size();h++) {
                                    for (LL i=0;i<(LL)q[7].size();i++) {
                                        vector<LL> things;
                                        things.pb(q[1][c]);
                                        things.pb(q[2][d]);
                                        things.pb(q[3][e]);
                                        things.pb(q[4][f]);
                                        things.pb(q[5][g]);
                                        things.pb(q[6][h]);
                                        things.pb(q[7][i]);
                                        ans = max(ans, brute(things,target));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 8) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                for (LL h=0;h<(LL)q[6].size();h++) {
                                    for (LL i=0;i<(LL)q[7].size();i++) {
                                        for (LL j=0;j<(LL)q[8].size();j++) {
                                            vector<LL> things;
                                            things.pb(q[1][c]);
                                            things.pb(q[2][d]);
                                            things.pb(q[3][e]);
                                            things.pb(q[4][f]);
                                            things.pb(q[5][g]);
                                            things.pb(q[6][h]);
                                            things.pb(q[7][i]);
                                            things.pb(q[8][j]);
                                            ans = max(ans, brute(things,target));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 9) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                for (LL h=0;h<(LL)q[6].size();h++) {
                                    for (LL i=0;i<(LL)q[7].size();i++) {
                                        for (LL j=0;j<(LL)q[8].size();j++) {
                                            for (LL k=0;k<(LL)q[9].size();k++) {
                                                vector<LL> things;
                                                things.pb(q[1][c]);
                                                things.pb(q[2][d]);
                                                things.pb(q[3][e]);
                                                things.pb(q[4][f]);
                                                things.pb(q[5][g]);
                                                things.pb(q[6][h]);
                                                things.pb(q[7][i]);
                                                things.pb(q[8][j]);
                                                things.pb(q[9][k]);
                                                ans = max(ans, brute(things,target));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 10) {
            for (LL c=0;c<(LL)q[1].size();c++) {
                for (LL d = 0;d<(LL)q[2].size();d++) {
                    for (LL e = 0;e<(LL)q[3].size();e++) {
                        for (LL f = 0;f<(LL)q[4].size();f++) {
                            for (LL g = 0;g<(LL)q[5].size();g++) {
                                for (LL h=0;h<(LL)q[6].size();h++) {
                                    for (LL i=0;i<(LL)q[7].size();i++) {
                                        for (LL j=0;j<(LL)q[8].size();j++) {
                                            for (LL k=0;k<(LL)q[9].size();k++) {
                                                for (LL l=0;l<(LL)q[10].size();l++) {
                                                    vector<LL> things;
                                                    things.pb(q[1][c]);
                                                    things.pb(q[2][d]);
                                                    things.pb(q[3][e]);
                                                    things.pb(q[4][f]);
                                                    things.pb(q[5][g]);
                                                    things.pb(q[6][h]);
                                                    things.pb(q[7][i]);
                                                    things.pb(q[8][j]);
                                                    things.pb(q[9][k]);
                                                    things.pb(q[10][l]);
                                                    ans = max(ans, brute(things,target));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        tot+=ans;
        cout << tot << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
