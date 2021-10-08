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

const LL MAXN = 300000;
LL a[MAXN + 5];

const LL inf = 1e16;
struct Node {
	Node *l = 0, *r = 0;
	LL lo, hi, mset = inf, madd = 0, val = -inf;
	Node(LL lo,LL hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<LL>& v, LL lo, LL hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			LL mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	LL query(LL L, LL R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(LL L, LL R, LL x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(LL L, LL R, LL x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			LL mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main () {
    //clock_t start = clock();
    LL n,q;
    cin >> n >> q;
    vector<LL> v;
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        v.pb(x);
    }
    Node* tr = new Node(v, 0, sizeof(v));
    // for (LL i=0;i<n;i++) cout << tr->query(0,i+1) << " ";
    // cout << endl;
    while (q--) {
        LL type;
        cin >> type;
        if (type == 1) {
            LL x;
            cin >> x;
            x--;
            LL cnt = 0;
            // for (LL i=x;i>=1;i--) {
            //     if (a[i] > a[x]) break; else cnt++;
            // }
            // for (LL i=x;i<=n;i++) {
            //     if (a[i] > a[x]) break; else cnt++;
            // }
            LL l = 0, r = x, ans = x;
            while (l <= r) {
                LL m = (l + r) / 2;
                if (tr->query(m,x+1) <= v[x]) {
                    ans = m;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            cnt += x - ans;
            l = x, r = n-1, ans = x;
            while (l <= r) {
                LL m = (l + r) / 2;
                if (tr->query(x,m+1) <= v[x]) {
                    ans = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            cnt += ans - x;
            cout << cnt + 1 << endl;
        } else if (type == 2) {
            LL i,x;
            cin >> i >> x;
            i--;
            tr->set(i,i+1,x);
            v[i] = x;
        } else {
            LL i,j,x;
            cin >> i >> j >> x;
            i--;
            j--;
            tr->set(i,j+1,x);
            for (LL k=i;k<=j;k++) {
                // updateRange(1,1,n,k,k,x-a[k]);
                v[k] = x;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}