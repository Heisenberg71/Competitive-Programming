#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define LIM 200005
#define nl "\n"
#define pii pair<int, int>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update>

int arr[LIM];
ordered_set os;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        os.insert({arr[i], i});
    }
    while(q--){
        char ch;
        scanf(" %c", &ch);
        if(ch == '!'){
            int k, x;
            scanf("%d %d", &k, &x);
            os.erase({arr[k - 1], k - 1});
            arr[k - 1] = x;
            os.insert({x, k - 1});
        }
        else{
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%d\n", os.order_of_key({R + 1, 0}) - os.order_of_key({L, 0}));
        }
    }

    return 0;
}
