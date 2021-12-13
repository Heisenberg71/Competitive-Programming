#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
#define mat_int unsigned long long
#define ull unsigned long long
using namespace std;

struct matrix{
    int dimR, dimC;
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
                    sum += (mat[i][k] * oth.mat[k][j]);
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
    ll t, cas = 1, p, q, n;
    cin >> t;
    while(t--){
        cin >> p >> q >> n;
        matrix A(2,2), B(2, 1);
        A.mat[0][0] = p;
        A.mat[0][1] = -q;
        A.mat[1][0] = 1;
        A.mat[1][1] = 0;

        B.mat[0][0] = p;
        B.mat[1][0] = 2;

        matrix ans = (A ^ n) * B;

        printf("Case %lld: %llu\n",cas++, ans.mat[1][0]);
    }

    return 0;
}
