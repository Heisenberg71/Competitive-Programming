/// NEVER UNDERESTIMATE THE POWER OF CONDITIONS IN BINARY SEARCH
bool bs(int x, int n)
{
    int lo = 0, hi = n, md, prev = -1;
    while(lo < hi){
        md = (lo+hi)/2;
        if(v[md] == x) return 1;
        else if(x < v[md]) hi = md;
        else lo = md;

        if(prev == md) break;
        prev = md;
    }
    return 0;
}

/// LOWER BOUND
int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

/// UPPER BOUND
int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

/// SPECIAL CONTITIONS

/// ARRAY IDX = [0, 1, 2, 3, 4, 5, (6), 7, 8, 9, ...] = [FALSE, FLASE, FALSE, FLASE, FALSE, TRUE, TRUE, TRUE, TRUE, TRUE, ...]
/// WHEN THE FIRST TRUE INDEX IS TO FIND OUT IN THE ARRAY IN THIS FORMATION FOR HERE WHICH IS INDEX NO. 6

ll spbs1(ll lo, ll hi)
{
    ll lo = 0, hi = n-1; /// ELEMENTS OF THE ARRAY MUST CONTAIN FROM [0 TO N-1] INDESES 
    while(lo+1 < hi){
        ll md = (lo+hi)/2;
        if() /// THE CONDITION FOR TRUE
            lo = md;
        else
            hi = md;
    }
    return lo;
}


/// ARRAY IDX = [0, 1, 2, 3, 4, 5, (6), 7, 8, 9, ...] = [TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, ...]
/// WHEN THE LAST TRUE INDEX IS TO FIND OUT IN THE ARRAY IN THIS FORMATION FOR HERE WHICH IS INDEX NO. 6
ll sbps2(ll lo, ll hi)
{
    ll lo = 0, hi = n-1; /// ELEMENTS OF THE ARRAY MUST CONTAIN FROM [0 TO N-1] INDESES 
    while(lo+1 < hi){
        ll md = (lo+hi)/2;
        if() /// THE CONDITION FOR TRUE
             hi = md;
        else
            lo = md;
    }
    return hi;
}
