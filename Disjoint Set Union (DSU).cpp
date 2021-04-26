int findP(int u)
{
    if(pr[u] == u) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);

    pr[u] = v;
}

/// findP(value)  NEED TO CALL FROM MAIN
/// connect(x, y) NEED TO CALL FROM MAIN
/// INITIALIZE VALUE OF pr[] FROM MAIN
