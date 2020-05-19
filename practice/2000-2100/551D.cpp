#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 5005
// #define mod 998244353

long long powmod(long long x, long long y, long long mod)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % mod;
        // cout << x << " " << mod << "\n";
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}
using S = long long int;
S a[2][2], temp[2][2], res[2][2];

S fast_fibo(S x, S mod)
{
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;
    while (x)
    {
        if (x & 1)
        {
            memset(temp, 0, sizeof(temp));
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        temp[i][j] = (temp[i][j] + res[i][k] * a[k][j]) % mod;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i][j] = temp[i][j];
        }
        memset(temp, 0, sizeof(temp));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    temp[i][j] = (temp[i][j] + a[i][k] * a[k][j]) % mod;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = temp[i][j];
        x /= 2;
    }
    return (res[0][1] + res[0][0]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, l, k, mod, one, zero;
    cin >> n >> k >> l >> mod;
    zero = fast_fibo(n, mod);
    one = (powmod(2LL, n, mod) - zero + mod) % mod;
    // cout << mod << "\n";
    // cout << one << "\n";
    // cout << one << " " << zero << "\n";
    if (l != 64 && l != 63)
    {
        ll temp = powmod(2, l, INT64_MAX);
        if (k >= temp)
        {
            cout << 0 << "\n";
            return 0;
        }
    }
    if (l == 0 && k == 0)
    {
        cout << 1 % mod << "\n";
        return 0;
    }
    ll ans = 1;
    for (ll i = 1; i <= l; i++)
    {
        if (k % 2 == 1)
            ans = (ans * one) % mod;
        else
            ans = (ans * zero) % mod;
        k /= 2;
        // cout << ans << " ";
    }
    cout << ans << "\n";
}