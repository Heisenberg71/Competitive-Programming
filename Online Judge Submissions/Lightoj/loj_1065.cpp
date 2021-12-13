#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
#define mat_int long long
using namespace std;

int pw[] = {1, 10, 100, 1000, 10000};

struct matrix{
    int dimR, dimC, MOD = 10000;
    vector <vector <mat_int> > mat;
    matrix(int _dimR, int _dimC){
        dimR = _dimR;
        dimC = _dimC;
        mat.clear();
        mat.resize(dimR, vector <mat_int> (dimC, 0));
        if(dimR == dimC){
            for(int i = 0; i < dimR; i++)
                mat[i][i] = 1;
        }
    }

    matrix operator * (const matrix &oth)
    {
        int nr = dimR;
        int nc = oth.dimC;
        matrix newMat(nr, nc);
        for(int i = 0; i < nr; i++){
            for(int j = 0; j < nc; j++){
                mat_int sum = 0;
                for(int k = 0; k < oth.dimR; k++)
                {
                    sum += (mat[i][k] * oth.mat[k][j]) % MOD;
                    sum %= MOD;
                }
                newMat.mat[i][j] = sum;
            }
        }
        return newMat;
    }

    matrix operator ^ (ll p)
    {
        matrix res(dimR, dimC);
        matrix x = *this;

        while(p){
            if(p % 2 == 1) res = x * res;
            x = x * x;
            p /= 2;
        }

        return res;
    }

    void print()
    {
        cout << "......" << endl;

        for(int i = 0; i < dimR; i++){
            for(int j = 0; j < dimC; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << "......" << endl;
    }

};

int main()
{
    int t, a, b, n, m, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &a, &b, &n, &m);
        matrix ma(2, 2), mb(2, 1);
        ma.mat[0][0] = 1;
        ma.mat[0][1] = 1;
        ma.mat[1][0] = 1;
        ma.mat[1][1] = 0;

        mb.mat[0][0] = b;
        mb.mat[1][0] = a;

        matrix mc = (ma ^ (n - 1)) * mb;
        //cout << ma.mat[0][0] << " " << ma.mat[0][1] << endl;
        //cout << ma.mat[1][0] << " " << ma.mat[1][1] << endl;
        printf("Case %d: %lld\n", cas++, mc.mat[0][0] % pw[m]);
    }
    return 0;
}
