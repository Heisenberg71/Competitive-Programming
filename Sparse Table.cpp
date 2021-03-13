#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
using namespace std;

int arr[LIM], dp[LIM][22], log_array[LIM];  /// NEVER USE LOG/SQRT ETC. IN SIZE DECLARATION
                                            /// dp[array_size][log2(array_size)]
                                            /// dp[starting_index][range]

void construct(int n)   /// n = ARRAY SIZE
{
    log_array[1] = 0;
    for(int i = 2; i <= n; i++)
        log_array[i] = 1 + log_array[i / 2];    /// GENARATING 2 BASED LOG VALUES 1 TO n

    for(int i = 0; i < n; i++)
        dp[i][0] = arr[i];      /// SINGLE RANGE RESULTS

    int k = log_array[n] + 1;

    for(int j = 1; j <= k; j++){
        for(int i = 0; i + (1 << (j - 1)) < n; i++){
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

}

int query(int L, int R)
{
    int len = R - L + 1;
    //if(len <= 0) return INT_MAX;
    int lg = log_array[len];
    return min(dp[L][lg], dp[R - (1 << lg) + 1][lg]);   /// RETURN ANSWER FROM 2 OVERLAPPING RANGES
}
