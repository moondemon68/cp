// C++ Implementation of above approach 
#include <bits/stdc++.h> 
#define LL long long
using namespace std; 
#define mod 1000000007 

// Function to return (x^y) mod p 
LL power(LL x, unsigned LL y, LL p) 
{ 
	LL res = 1; 

	x = x % p; 

	while (y > 0) { 

		if (y & 1) 
			res = (res * x) % p; 
		y = y >> 1; 
		x = (x * x) % p; 
	} 
	return res; 
} 

// Declaring size array globally 
LL sz[300005]; 
LL freq[300004]; 
vector<pair<LL, pair<LL, LL> > > edges; 

// Initializing DSU data structure 
void initialize(LL Arr[], LL N) 
{ 
	for (LL i = 0; i < N; i++) { 
		Arr[i] = i; 
		sz[i] = 1; 
	} 
} 

// Function to find the root of ith 
// node in the disjoLL set 
LL root(LL Arr[], LL i) 
{ 
	while (Arr[i] != i) { 
		i = Arr[i]; 
	} 
	return i; 
} 

// Weighted union using Path Compression 
void weighted_union(LL Arr[], 
					LL sz[], LL A, LL B) 
{ 
	LL root_A = root(Arr, A); 
	LL root_B = root(Arr, B); 

	// size of set A is small than size of set B 
	if (sz[root_A] < sz[root_B]) { 
		Arr[root_A] = Arr[root_B]; 
		sz[root_B] += sz[root_A]; 
	} 

	// size of set B is small than size of set A 
	else { 
		Arr[root_B] = Arr[root_A]; 
		sz[root_A] += sz[root_B]; 
	} 
} 

// Function to add an edge in the tree 
void AddEdge(LL a, LL b, LL w) 
{ 
	edges.push_back({ w, { a, b } }); 
} 

// Function to return the required product 
LL MinProduct() 
{ 
	LL result = 0; 

	// Sorting the edges with respect to its weight 
	sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end()); 

	// Start iterating in decreasing order of weight 
	for (LL i = edges.size() - 1; i >= 0; i--) { 

		// Determine Curret edge values 
		LL curr_weight = edges[i].first; 
		LL Node1 = edges[i].second.first; 
		LL Node2 = edges[i].second.second; 

		// Calculate root of each node 
		// and size of each set 
		LL Root1 = root(freq, Node1); 
		LL Set1_size = sz[Root1]; 
		LL Root2 = root(freq, Node2); 
		LL Set2_size = sz[Root2]; 

		// Using the formula 
		LL prod = Set1_size * Set2_size; 
		LL Product = (curr_weight*prod)%mod;
        // cout << prod << " " << curr_weight << endl;

		// Calculating final result 
		result = ((result % mod) + (Product % mod)) % mod; 

		// Weighted union using Path Compression 
		weighted_union(freq, sz, Node1, Node2); 
	} 
	return result % mod; 
} 

// Driver code 
int main() 
{ 
	LL n; 
    cin >> n;

	initialize(freq, n); 
    for (LL i=1;i<n;i++) {
        LL x,y,z;
        cin >> x >> y >> z;
        AddEdge(x-1,y-1,z);
    }

	cout << MinProduct(); 
} 
