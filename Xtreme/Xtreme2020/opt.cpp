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

string solve(int i1, int i2, int i3) {
    int t[9999];
    vector<int> o;
    // var t = new Uint16Array(9999);
    memset (t,0,sizeof(t));
    string s;
    // cin >> s;
    int p = 0;
    p += 1;
    t[p] = i1;
    p += 1;
    t[p] = i2;
    p += 1;
    t[p] = i3;
    p -= 1;

    while (t[p] != 0) {
        t[p] -= 1;
        t[p + 1] -= 1;
        t[p + 2] += 1;
    };
    p += 2;

    t[p - 2] += t[p];
    t[p] = 0;
    p -= 3;

    while (t[p] != 0) {
        t[p] -= 1;
        t[p + 1] -= 1;
        t[p - 1] += 1;
    };
    p -= 1;

    t[p + 1] += t[p];
    t[p] = 0;
    t[p + 6] += 1;
    t[p + 13] += 1;
    p += 13;

    while (t[p] != 0) {
        t[p + 4] = 0;
        t[p + 3] = 0;
        t[p + 2] = 0;
        t[p + 1] = 0;
        t[p] = 0;
        p -= 12;

        t[p + 7] += t[p];
        t[p + 13] += t[p];
        t[p] = 0;
        p += 1;
        t[p + 7] += t[p];
        t[p + 13] += t[p];
        t[p] = 0;
        p += 1;
        t[p + 7] += t[p];
        t[p + 13] += t[p];
        t[p] = 0;
        t[p + 2] += 1;
        t[p + 3] += 1;
        p += 3;
        while (t[p] != 0) {
            t[p - 1] -= 1;
            p -= 1;
        };
        p -= 1;
        while (t[p] != 0) {
            cout << "gapernah?" << '\n';
            t[p] -= 1;
            t[p + 2] += 1;
            p -= 1;
        };
        p += 4;
        t[p - 7] += t[p];
        t[p] = 0;
        p += 1;
        t[p - 7] += t[p];
        t[p] = 0;
        p += 1;
        t[p - 7] += t[p];
        t[p] = 0;
        t[p + 7] += 1;
        p += 7;


        int cnt = 0;
        while (t[p] != 0) {
            t[p] -= 1;
            p -= 11;
            t[p + 2] += t[p];
            t[p + 4] += t[p];
            t[p] = 0;
            p += 1;
            t[p + 2] += t[p];
            t[p + 4] += t[p];
            t[p] = 0;
            p += 1;
            t[p - 2] += t[p];
            t[p] = 0;
            p += 1;
            t[p - 2] += t[p];
            t[p] = 0;
            t[p] += 1;
            // cout << "P: " << p << '\n';
            // cout << i1 << ' ' << i2 << ' ' << i3 << '\n';
            // for (int i = 1; i <= 17; i++) {
            //     cout << i << ' ' << t[i] << '\n';
            // }
            
            while (t[p] != 0) {
                t[p] = 0;
                t[p] += 1;
                p += 1;
                while (t[p] != 0) {
                    t[p - 1] -= 1;
                    p -= 1;
                };
                p -= 1;
                while (t[p] != 0) {
                    t[p] -= 1;
                    t[p + 2] -= 1;
                    p -= 1;
                };
                t[p + 2] -= 1;
                t[p + 5] += 1;
                p += 6;
                while (t[p] != 0) {
                    t[p - 1] -= 1;
                    p -= 1;
                };
                p -= 1;
                
                while (t[p] != 0) {
                    t[p] -= 1;
                    t[p + 1] += 1;
                    p += 2;
                    while (t[p] != 0) {
                        t[p] -= 1;
                        t[p - 1] -= 1;
                        p -= 1;
                    };
                    p -= 1;
                    while (t[p] != 0) {
                        p += 2;
                        while (t[p] != 0) {
                            t[p] -= 1;
                            t[p - 2] -= 1;
                            p -= 1;
                        };
                        t[p] -= 1;
                        p -= 2;
                        while (t[p] != 0) {
                            t[p] -= 1;
                            t[p + 1] -= 1;
                            t[p + 3] -= 1;
                            p -= 1;
                        };
                    };
                    p -= 1;
                };
                
                t[p + 2] -= 1;
                t[p - 3] += 1;
                p -= 2;
                while (t[p] != 0) {
                    t[p - 1] -= 1;
                    p -= 1;
                };
                p -= 1;
                while (t[p] != 0) {
                    p += 2;
                    while (t[p] != 0) {
                        t[p - 2] -= 1;
                        p -= 1;
                    };
                    p -= 2;
                    while (t[p] != 0) {
                        p -= 1;
                    };
                };
                t[p + 1] -= 1;
                p += 1;
                
            };
            t[p + 8] += 1;
            p += 8;
        };
        t[p] -= 1;
        t[p - 4] += 1;
        t[p - 3] += 1;
        p -= 3;
        while (t[p] != 0) {
            t[p - 1] -= 1;
            p -= 1;
        };
        p -= 1;
        while (t[p] != 0) {
            t[p + 2] += 1;
            p += 2;
            while (t[p] != 0) {
                t[p - 2] -= 1;
                p -= 1;
            };
            p -= 2;
            while (t[p] != 0) {
                t[p + 3] += 1;
                p += 3;
                while (t[p] != 0) {
                    t[p - 3] -= 1;
                    p -= 1;
                };
                p -= 3;
                while (t[p] != 0) {
                    p -= 1;
                };
            };
        };
        t[p + 1] -= 1;
        p += 1;
    };
    t[p + 4] = 0;
    t[p - 10] = 0;
    t[p - 8] += 1;
    t[p - 7] += 1;
    p -= 7;
    while (t[p] != 0) {
        t[p - 1] -= 1;
        p -= 1;
    };
    p -= 1;
    while (t[p] != 0) {
        t[p] -= 1;
        t[p + 2] += 1;
        p -= 1;
    };
    t[p + 1] += 1;
    p += 2;
    while (t[p] != 0) {
        t[p - 1] -= 1;
        p -= 1;
    };
    p -= 1;
    while (t[p] != 0) {
        p += 2;
        while (t[p] != 0) {
            t[p - 2] -= 1;
            p -= 1;
        };
        p -= 2;
        while (t[p] != 0) {
            p -= 1;
        };
    };
    t[p + 1] -= 1;
    p += 1;
    while (t[p] != 0) {
        t[p] += 1;
        t[p + 6] += 10;
        t[p] += 1;
        p += 1;
        while (t[p] != 0) {
            t[p - 1] -= 1;
            p -= 1;
        };
        p -= 1;
        while (t[p] != 0) {
            p += 2;
            while (t[p] != 0) {
                t[p - 2] -= 1;
                p -= 1;
            };
            p -= 2;
            while (t[p] != 0) {
                p -= 1;
            };
        };
        t[p + 1] -= 1;
        p += 1;
        while (t[p] != 0) {
            t[p] += 2;
            p += 1;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                t[p] -= 1;
                t[p + 2] -= 1;
                p -= 1;
            };
            t[p + 2] -= 1;
            t[p + 4] += 1;
            t[p + 6] += 1;
            t[p + 7] -= 1;
            p += 7;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                p -= 2;
                t[p + 3] += t[p];
                t[p] = 0;
                t[p + 5] += 1;
                t[p + 6] += 1;
                p += 6;
                while (t[p] != 0) {
                    t[p - 1] -= 1;
                    p -= 1;
                };
                p -= 1;
                while (t[p] != 0) {
                    t[p] -= 1;
                    t[p + 2] += 1;
                    p -= 1;
                };
                t[p - 2] -= 1;
                p -= 3;
            };
            t[p - 4] += 1;
            p -= 3;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                p += 2;
                while (t[p] != 0) {
                    t[p - 2] -= 1;
                    p -= 1;
                };
                p -= 2;
                while (t[p] != 0) {
                    p -= 1;
                };
            };
            t[p + 1] -= 1;
            p += 1;
        };
        t[p + 2] += 8;
        p += 2;
        t[p + 1] += t[p] * 6;
        t[p] = 0;
        p += 1;
        t[p - 4] += t[p];
        t[p] = 0;
        t[p + 5] += 1;
        p += 6;
        while (t[p] != 0) {
            t[p - 1] -= 1;
            p -= 1;
        };
        p -= 1;
        while (t[p] != 0) {
            p += 2;
            while (t[p] != 0) {
                t[p - 2] -= 1;
                p -= 1;
            };
            p -= 2;
            while (t[p] != 0) {
                p -= 1;
            };
        };
        t[p + 1] -= 1;
        p += 1;
        while (t[p] != 0) {
            t[p] += 2;
            p += 1;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                t[p] -= 1;
                t[p + 2] -= 1;
                p -= 1;
            };
            t[p + 2] -= 1;
            t[p - 6] += 1;
            t[p - 5] += 1;
            p -= 5;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                t[p] -= 1;
                t[p + 2] += 1;
                p -= 1;
            };
            t[p + 8] += 1;
            p += 9;
            while (t[p] != 0) {
                t[p - 1] -= 1;
                p -= 1;
            };
            p -= 1;
            while (t[p] != 0) {
                p += 2;
                while (t[p] != 0) {
                    t[p - 2] -= 1;
                    p -= 1;
                };
                p -= 2;
                while (t[p] != 0) {
                    p -= 1;
                };
            };
            t[p + 1] -= 1;
            p += 1;
        };
        t[p - 2] = 0;
        t[p - 7] += 1;
        p -= 6;
        while (t[p] != 0) {
            t[p - 1] -= 1;
            p -= 1;
        };
        p -= 1;
        while (t[p] != 0) {
            p += 2;
            while (t[p] != 0) {
                t[p - 2] -= 1;
                p -= 1;
            };
            p -= 2;
            while (t[p] != 0) {
                p -= 1;
            };
        };
        t[p + 1] -= 1;
        p += 1;
    };
    p -= 2;
    while (t[p] != 0) {
        o.push_back(t[p]);
        p -= 1;
    };
    string ret = "";
    for (auto x : o) ret += (char)x;
    return ret;
};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        cout << solve((int)s[0],(int)s[1], (int)s[2]) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}