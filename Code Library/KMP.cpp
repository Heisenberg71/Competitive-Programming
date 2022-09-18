#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
using namespace std;

char temp[LIM];
string text, pat;
int prefix[LIM];

void calcPrefix()
{
    prefix[0] = prefix[1] = 0;

    for(int i = 2; i < pat.size(); i++){
        int p = i - 1;
        while(1){
            if(pat[i] == pat[ prefix[p] + 1 ]){
                prefix[i] = prefix[p] + 1;
                break;
            }
            else if(!p) break;
            else p = prefix[p];
        }
    }
}

int kmp() /// returns the # of matched substrings
{
    int p = 0, ans = 0;
    for(int j = 0; j < text.size(); j++){
        while(p && pat[p + 1] != text[j]){
            p = prefix[p];
        }
        if(pat[p + 1] == text[j]){
            p++;
        }
        if(p + 1 == pat.size()){
            ans++;
        }
    }
    return ans;
}

int main()
{
    int cas = 1, t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", temp); text = temp;
        scanf("%s", temp); pat = temp;
        pat = "#" + pat;
        calcPrefix();
        printf("Case %d: %d\n", cas++, kmp());
    }

    return 0;
}
