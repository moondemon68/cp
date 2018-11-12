#include <bits/stdc++.h>

using namespace std;

int main () {
	string key="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s;
	cin >> s;
	int a[15005],b[15005];
	for (int i=0;i<s.size();i++) {
		if (i<s.size()/2) a[i]=s[i]-'A'; else b[i-s.size()/2]=s[i]-'A';
	}
	int val=0;
	for (int i=0;i<s.size()/2;i++) {
		val+=a[i];
	}
	val%=26;
	for (int i=0;i<s.size()/2;i++) {
		a[i]+=val;
		if (a[i]>25) a[i]-=26;
	}
	val=0;
	for (int i=0;i<s.size()/2;i++) {
		val+=b[i];
	}
	val%=26;
	for (int i=0;i<s.size()/2;i++) {
		b[i]+=val;
		if (b[i]>25) b[i]-=26;
	}
	for (int i=0;i<s.size()/2;i++) {
		a[i]+=b[i];
		if (a[i]>25) a[i]-=26;
		cout << key[a[i]];
	}
	return 0;
}
