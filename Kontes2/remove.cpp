#include <bits/stdc++.h>
#define mp make_pair
#define num first
#define id second
#define LL long long

using namespace std;

bool cmp(pair<LL,LL> a,pair<LL,LL> b) {
	return a.id<b.id;
}

int main () {
	int n;
	cin >> n;
	vector< pair<LL,LL> > ans;
	priority_queue< pair<LL,LL>, vector< pair<LL,LL> >, greater<pair<LL,LL> > > p;
	for (int i=1;i<=n;i++) {
		LL x;
		cin >> x;
		p.push(mp(x,i));
	}
	//while (!p.empty()) {
	//	cout << p.top().num << " " << p.top().id << endl;
	//	p.pop();
	//}
	while (p.size()>1) {
		pair<LL,LL> f=p.top();
		p.pop();
		pair<LL,LL> g=p.top();
		p.pop();
		if (f.num==g.num) {
			p.push(mp(f.num*2,g.id));
		} else {
			ans.push_back(mp(f.num,f.id));
			p.push(g);
		}
	}
	while (!p.empty()) {
		ans.push_back(mp(p.top().num,p.top().id));
		p.pop();
	}
	sort (ans.begin(),ans.end(),cmp);
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++) {
		cout << ans[i].num <<" ";
	}
	return 0;
}
