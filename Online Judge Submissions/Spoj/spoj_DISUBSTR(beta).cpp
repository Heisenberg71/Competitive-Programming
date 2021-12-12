#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 1005
#define base 257
using namespace std;

char str[MAX + 5];
ull po[MAX + 5], prefixHash[MAX + 5];

void pre()
{
    po[0] = 1;
    for(int i = 1; i <= MAX; i++)
        po[i] = po[i - 1] * base;
}

void genHash(int n)
{
    prefixHash[0] = str[0];
    for(int i = 1; i < n; i++)
        prefixHash[i] = (prefixHash[i-1] * base) + str[i];
}

ull getHash(int L, int R)
{
    if(!L) return prefixHash[R];
    return prefixHash[R] - prefixHash[L-1] * po[R-L+1];
}

int main()
{
    pre();

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", &str);
        int n = strlen(str);
        genHash(n);
        int ans = 0;
        for(int len = 1; len <= n; len++){
            set <ull> ust;
            for(int i = 0; i + len - 1 < n; i++){
                ust.insert(getHash(i, i + len - 1));
            }
            ans += ust.size();
        }
        printf("%d\n", ans);
    }

    return 0;
}
