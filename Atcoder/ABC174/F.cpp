#include <cstdio>
#include <algorithm>

using namespace std;

struct req {
    int l, r, val, idx;
    bool t;
};

bool operator <( req a, req b ) {
    if ( a.r == b.r ) {
        return a.t < b.t;
    }
    return a.r < b.r;
}

int bit[ 500001 ];

void add( int y, int val ) {
    while ( y <= 500000 ) {
        bit[ y ] += val;
        y += ( y & -y );
    }
}

int sum( int y ) {
    int res = 0;
    while ( y > 0 ) {
        res += bit[ y ];
        y -= ( y & -y );
    }
    return res;
}

bool visited[ 2000001 ];
req arr[ 1000005 ];
int main() {
    int N, Q, i;
    int *prev = new int[ 2000001 ];
    for ( i = 0; i <= 2000000; ++i ) {
        visited[ i ] = false;
        prev[ i ] = 0;
    }
    scanf( "%d", &N );
    scanf( "%d", &Q );
    for ( i = 1; i <= N; ++i ) {
        add( i, 1 );
    }
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", &arr[ i ].val );
        arr[ i ].idx = i + 1;
        arr[ i ].t = 0;
        arr[ i ].r = i + 1;
    }
    for ( i = N; i < N + Q; ++i ) {
        scanf( "%d%d", &arr[ i ].l, &arr[ i ].r );
        arr[ i ].idx = i - N;
        arr[ i ].t = 1;
    }
    sort( arr, arr + N + Q );
    int ans[ Q ];
    for ( i = 0; i < N + Q; ++i ) {
        if ( arr[ i ].t ) {
            ans[ arr[ i ].idx ] = sum( arr[ i ].r ) - sum( arr[ i ].l - 1 );
        }
        else {
            if ( visited[ arr[ i ].val ] ) {
                if ( prev[ arr[ i ].val ] != 0 ) {
                    add( prev[ arr[ i ].val ], -1 );
                }
            }
            visited[ arr[ i ].val ] = true;
            prev[ arr[ i ].val ] = arr[ i ].idx;
        }
    }
    for ( i = 0; i < Q; ++i ) {
        printf( "%d\n", ans[ i ] );
    }
    return 0;
}