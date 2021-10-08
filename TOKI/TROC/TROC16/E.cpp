// C++ program to find Sum 
// of GCD over all subarrays 

#include <bits/stdc++.h> 
using namespace std; 

//int a[100001]; 
int SparseTable[100001][51]; 

// Build Sparse Table 
void buildSparseTable(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		SparseTable[i][0] = a[i]; 
	} 
	// Building the Sparse Table for GCD[L, R] Queries 
	for (int j = 1; j <= 19; j++) { 
		for (int i = 0; i <= n - (1 << j); i++) { 
			SparseTable[i][j] = __gcd(SparseTable[i][j - 1], 
					SparseTable[i + (1 << (j - 1))][j - 1]); 
		} 
	} 
} 

// Utility Function to calculate GCD in range [L,R] 
int queryForGCD(int L, int R) 
{ 
	int returnValue; 
	
	// Calculating where the answer is 
	// stored in our Sparse Table 
	int j = int(log2(R - L + 1)); 
	
	returnValue = __gcd(SparseTable[L][j], 
					SparseTable[R - (1 << j) + 1][j]); 
					
	return returnValue; 
} 

// Utility Function to find next-farther 
// position where gcd is same 
int nextPosition(int tempGCD, int startPointer, 
							int prevEndPointer, int n) 
{ 
	int high = n - 1; 
	int low = prevEndPointer; 
	int mid = prevEndPointer; 
	int nextPos = prevEndPointer; 
	
	// BinarySearch for Next Position 
	// for EndPointer 
	while (high >= low) { 
		
		mid = ((high + low) >> 1); 
		
		if (queryForGCD(startPointer, mid) == tempGCD) { 
			nextPos = mid; 
			low = mid + 1; 
		} 
		else { 
			high = mid - 1; 
		} 
	} 
	
	return nextPos + 1; 
} 

// Utility function to calculate 
// sum of gcd 
int calculateSum(int a[], int n) 
{ 
	buildSparseTable(a, n); 
	
	int endPointer, startPointer, prevEndPointer, tempGCD; 
	
	int tempAns = 0; 
	
	for (int i = 0; i < n; i++) { 
		// Initialising all the values 
		endPointer = i; 
		startPointer = i; 
		prevEndPointer = i; 
		tempGCD = a[i]; 
		while (endPointer < n) { 

			// Finding the next position for endPointer 
			endPointer = nextPosition(tempGCD, startPointer, 
											prevEndPointer, n); 

			// Adding the suitable sum to our answer 
            cout << tempGCD << " " << endPointer - prevEndPointer << endl;
			tempAns += ((endPointer - prevEndPointer) * tempGCD); 

			// Changing prevEndPointer 
			prevEndPointer = endPointer; 

			if (endPointer < n) { 
				// Recalculating tempGCD 
				tempGCD = __gcd(tempGCD, a[endPointer]); 
			} 
		} 
	} 
	return tempAns; 
} 

// Driver Code 
int main() 
{ 
	int n = 6; 
      
    int a[] = {2, 2, 2, 3, 5, 5}; 
	
	cout << calculateSum(a, n) << "\n"; 
	
	return 0; 
} 
