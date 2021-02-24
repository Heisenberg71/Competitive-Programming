/// NEVER UNDERESTIMATE THE POWER OF CONDITIONS IN BINARY SEARCH
bool bs(int x, int n)
{
    ll lo = 0, hi = n, md, prev = -1;
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
ll bs_lower_bound(int a[], int n, int x) {
    ll lo = 0, hi = n, md;
    while(lo < hi){
        md = (lo+hi)/2;
        if(x <= arr[md]) hi = md;
        else lo = md+1;
    }
    return lo;
}

/// UPPER BOUND
ll bs_upper_bound(int a[], int n, int x) {
    ll lo = 0, hi = n, md;
    while(lo < hi){
        md = (lo+hi)/2;
        if(x < arr[md]) hi = md;
        else lo = md+1;
    }
    return lo;
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
