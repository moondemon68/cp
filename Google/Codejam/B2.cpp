#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
#define N 6
using namespace std;


void swap_row(LL mat[N][N+1], LL i, LL j) 
{ 
    //printf("Swapped rows %d and %d\n", i, j); 
  
    for (LL k=0; k<=N; k++) 
    { 
        LL temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 
LL forwardElim(LL mat[N][N+1]) 
{ 
    for (LL k=0; k<N; k++) 
    { 
        // Initialize maximum value and index for pivot 
        LL i_max = k; 
        LL v_max = mat[i_max][k]; 
  
        /* find greater amplitude for pivot if any */
        for (LL i = k+1; i < N; i++) 
            if (abs(mat[i][k]) > v_max) 
                v_max = mat[i][k], i_max = i; 
  
        /* if a prinicipal diagonal element  is zero, 
         * it denotes that matrix is singular, and 
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max]) 
            return k; // Matrix is singular 
  
        /* Swap the greatest value row with current row */
        if (i_max != k) 
            swap_row(mat, k, i_max); 
  
  
        for (LL i=k+1; i<N; i++) 
        { 
            /* factor f to set current row kth elemnt to 0, 
             * and subsequently remaining kth column to 0 */
            LL f = mat[i][k]/mat[k][k]; 
  
            /* subtract fth multiple of corresponding kth 
               row element*/
            for (LL j=k+1; j<=N; j++) 
                mat[i][j] -= mat[k][j]*f; 
  
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0; 
        } 
  
        //print(mat);        //for matrix state 
    } 
    //print(mat);            //for matrix state 
    return -1; 
} 
  
// function to calculate the values of the unknowns 
void backSub(LL mat[N][N+1]) 
{ 
    LL x[N];  // An array to store solution 
  
    /* Start calculating from last equation up to the 
       first */
    for (LL i = N-1; i >= 0; i--) 
    { 
        /* start with the RHS of the equation */
        x[i] = mat[i][N]; 
  
        /* Initialize j to i+1 since matrix is upper 
           triangular*/
        for (LL j=i+1; j<N; j++) 
        { 
            /* subtract all the lhs values 
             * except the coefficient of the variable 
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j]; 
        } 
  
        /* divide the RHS by the coefficient of the 
           unknown being calculated */
        x[i] = x[i]/mat[i][i]; 
    } 
    for (LL i=0; i<N; i++) cout << x[i] << " ";
    cout << endl;
} 
void gaussianElimination(LL mat[N][N+1]) 
{ 
    /* reduction into r.e.f. */
    LL singular_flag = forwardElim(mat); 
  
    /* if matrix is singular */
    if (singular_flag != -1) 
    { 
        printf("Singular Matrix.\n"); 
  
        /* if the RHS of equation corresponding to 
           zero row  is 0, * system has infinitely 
           many solutions, else inconsistent*/
        if (mat[singular_flag][N]) 
            printf("Inconsistent System."); 
        else
            printf("May have infinitely many "
                   "solutions."); 
  
        return; 
    } 
  
    /* get solution to system and print it using 
       backward substitution */
    backSub(mat); 
} 
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,w;
    cin >> tc >> w;
    for (int t=1;t<=tc;t++) {
        LL a=0,b=0,c=0,d=0,e=0,f=0;
        cout << 1 << endl;
        cin >> a;
        cout << 2 << endl;
        cin >> b;
        cout << 3 << endl;
        cin >> c;
        cout << 4 << endl;
        cin >> d;
        cout << 5 << endl;
        cin >> e;
        cout << 6 << endl;
        cin >> f;
        LL mat[N][N+1]={{2,1,1,1,1,1,a},{4,2,1,1,1,1,b},{8,4,2,1,1,1,c},{16,8,4,2,1,1,d},{32,16,8,4,2,1,e},{64,32,16,8,4,2,f}};
        gaussianElimination(mat);
        cin >> a;
        if (a==-1) return 0;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}