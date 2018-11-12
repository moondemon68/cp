#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string s;
		int y1,m1,d1,y2,m2,d2,c;
		cin >> s;
		scanf("%d/%d/%d",&y1,&m1,&d1);
		scanf("%d/%d/%d",&y2,&m2,&d2);
		cin >> c;
		cout << s << " ";
		int status;
		if (y1>=2010||y2>=1991) status=2;
		else if (c>40) status=0;
		else status=1;
		if (status==0) cout << "ineligible"; else if (status==1) cout << "coach petitions"; else cout << "eligible";
		cout << endl;
	}
	return 0;
}
