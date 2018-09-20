#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
	if(a.first==b.first) return a.second<b.second;
	else return a.first>b.first;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	assert(n!=1);
	int a[100005],b[100005];
	vector<pair<int,int> > v;
	for (int i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
		v.push_back(make_pair(a[i]-b[i],i));
	}
	sort(v.begin(),v.end(),cmp);
	int l=0,r=n-1,ans=0;
	vector<pair<int,int> > f;
	while(l<=r) {
		if (v[l].second<v[r].second) {
			ans+=b[v[l].second]+a[v[r].second];
			l++;
			r--;
		} else {
			f.push_back(v[l]);
			l++;
		}
	}
//cout<<ans << " " << f.size() << endl;

	for (int i=0;i<f.size()/2;i++) {
		//cout<<f[i].first<< " " <<f[i].second<< endl;
		if(f[i].second<f[f.size()-1-i].second) ans+=b[f[i].second]+a[f[f.size()-1-i].second];
		else ans+=a[f[i].second]+b[f[f.size()-1-i].second];
	}
	cout<<ans<<endl;
	return 0;
}
