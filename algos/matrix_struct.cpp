#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005

const ll MAT = 101;
struct Mat
{
    ll v[MAT][MAT];
    Mat() { memset(v, 0, sizeof(v)); };
};
ll mo = 1000000007;

Mat mulmat(Mat &a, Mat &b, ll n = MAT)
{
    ll mo2 = 4 * mo * mo;
    ll x, y, z;
    Mat r;
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] = 0;
    for (x = 0; x < n; x++)
        for (z = 0; z < n; z++)
            for (y = 0; y < n; y++)
            {
                r.v[x][y] += a.v[x][z] * b.v[z][y];
                if (r.v[x][y] > mo2)
                    r.v[x][y] -= mo2;
            }
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] %= mo;
    return r;
}

Mat powmat(ll p, Mat a, ll n = MAT)
{
    ll i, x, y;
    Mat r;
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            r.v[x][y] = 0;
    for (i = 0; i < n; i++)
        r.v[i][i] = 1;
    while (p)
    {
        if (p % 2)
            r = mulmat(r, a, n);
        a = mulmat(a, a, n);
        p >>= 1LL;
    }
    return r;
}