/*
  Solution of problem: https://lightoj.com/problem/curious-robin-hood
*/

#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
using namespace std;

int n, arr[LIM];
int bit[LIM];

int getNext(int index)
{
    return index + (index & -index);
    //return index + (index & (~index + 1));
}

int getParent(int index)
{
    return index - (index & -index);
}

void findIndexAndRanges()
{
    for(int i = 1; i <= n; i++)
    {
        int indexValueTemp = i, cnt = 0;
        while(!(indexValueTemp&1))
        {
            indexValueTemp >>= 1;
            cnt++;
        }
        int start = (i^(1 << cnt)), rangeSize = (1 << cnt);
//        cout << start << " Left:Right " << start + rangeSize - 1 << '\n';
    }
}

void constructBIT()
{
    for(int i = 1; i <= n; i++)
        bit[i] = 0;

    for(int i = 1; i <= n; i++)
    {
        int index = i;
        while(index <= n)
        {
            bit[index] += arr[i - 1];
            index = getNext(index);
        }
    }

//    for(int i = 1; i <= n; i++)
//        cout << bit[i] << " ";
//    cout << '\n';
}

int prefixSum(int index)
{
    int sum = 0;
    while(index)
    {
        sum += bit[index];
        index = getParent(index);
    }
    return sum;
}

int rangeQuery(int L, int R)
{
    return prefixSum(R + 1) - prefixSum(L);
}

void updateQuery(int index, int value)
{
    int difference = value;
    index++;

    while(index <= n)
    {
        bit[index] += difference;
        index = getNext(index);
    }
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--)
    {
        int q;
        cin >> n >> q;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        findIndexAndRanges();
        constructBIT();

        cout << "Case " << cas++ << ":\n";

        while(q--)
        {
            int typ;
            cin >> typ;
            if(typ == 3)  /// range query
            {
                int L, R;
                cin >> L >> R; /// zero-based
                cout << rangeQuery(L, R) << '\n'; /// zero-based
            }
            else if(typ == 2) /// update query
            {
                int index, value;
                cin >> index >> value;
                updateQuery(index, value);
            }
            else{
                int index;
                cin >> index;
                int x = rangeQuery(index, index);
                cout << x << '\n';
                updateQuery(index, -x);
            }
        }
    }

    return 0;
}

/**

11
3 2 -1 6 5 4 -3 3 7 2 3

*/
