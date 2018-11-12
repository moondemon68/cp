#include <bits/stdc++.h>

using namespace std;

int pow(int a,int b) {
	if (b==1) return a;
	else return pow(a*2,b-1);
}

int main () {
	int n=0,l=1,r=2;
	string a;
	getline(cin,a);
	string s="";
	for (int i=0;i<a.size();i++) {
		if (a[i]=='L'||a[i]=='R') s+=a[i];
		else if (a[i]>='0'&&a[i]<='9') {
			n+=a[i]-'0';
			n*=10;
		}
	}
	n/=10;
	int num=pow(2,n+1)-1;
	if (s=="") {
		cout << num << endl;
		return 0;
	}
		for (int i=0;i<s.size();i++) {
			int down;
			if (s[i]=='L') down=l; else down=r;
			num-=down;
			int newl=down+l,newr=down+r;
			l=newl;
			r=newr;
			//cout << num << " ";
		}
		cout << num << endl;
}
