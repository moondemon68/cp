#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;
  
LL _mergeSort(LL arr[], LL temp[], LL left, LL right);  
LL merge(LL arr[], LL temp[], LL left, LL mid, LL right);  
  
/* This function sorts the input array and returns the  
number of inversions in the array */
LL mergeSort(LL arr[], LL array_size)  
{  
    LL* temp = (LL*)malloc(sizeof(LL) * array_size);  
    return _mergeSort(arr, temp, 0, array_size - 1);  
}  
  
/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */
LL _mergeSort(LL arr[], LL temp[], LL left, LL right)  
{  
    LL mid, inv_count = 0;  
    if (right > left)  
    {  
        /* Divide the array LLo two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2;  
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count = _mergeSort(arr, temp, left, mid);  
        inv_count += _mergeSort(arr, temp, mid + 1, right);  
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);  
    }  
    return inv_count;  
}  
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
LL merge(LL arr[], LL temp[], LL left,  
                        LL mid, LL right)  
{  
    LL i, j, k;  
    LL inv_count = 0;  
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))  
    {  
        if (arr[i] <= arr[j]) 
        {  
            temp[k++] = arr[i++];  
        }  
        else 
        {  
            temp[k++] = arr[j++];  
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);  
        }  
    }  
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1)  
        temp[k++] = arr[i++];  
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right)  
        temp[k++] = arr[j++];  
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)  
        arr[i] = temp[i];  
  
    return inv_count;  
}  
  
int main () {
    //clock_t start = clock();
    LL n;
    while (1>0) {
        scanf("%lld",&n);
        LL a[n+5];
        if (n==0) return 0;
        for (LL i=0;i<n;i++) scanf("%lld",&a[i]);
        printf("%lld\n",mergeSort(a,n));
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}