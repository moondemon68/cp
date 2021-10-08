#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<Point<double>> pos, neg, all;
        for (int i = 0; i < n; i++) {
            double x,y;
            cin >> x >> y;
            Point<double> p(x,y);
            int type;
            cin >> type;
            if (type > 0) pos.pb(p);
            else neg.pb(p);
            all.pb(p);
        }

        bool yes = 0;
        for (int i=0; i<n; i++) {
            Point<double> origin(0,0);
            int sidePos = 0, k = 0;
            while (sidePos == 0 && k < pos.size()) {
                sidePos = sideOf(pos[k], origin, all[i]);
                k++;
            }
            int sideNeg = 0;
            k = 0;
            while (sideNeg == 0 && k < neg.size()) {
                sideNeg = sideOf(neg[k], origin, all[i]);
                k++;
            }
            bool can = 1;
            for (int j=0;j<pos.size();j++) {
                if (sideOf(pos[j], origin, all[i]) != 0 && sideOf(pos[j], origin, all[i]) != sidePos) {
                    can = 0;
                    break;
                }
            }
            for (int j=0;j<neg.size();j++) {
                if (sideOf(neg[j], origin, all[i]) != 0 && sideOf(neg[j], origin, all[i]) != sideNeg) {
                    can = 0;
                    break;
                }
            }
            if (can) yes = 1;
        }

        if (yes) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}