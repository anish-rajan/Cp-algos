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
#define N 6
#define mod 1000000007
#define INF INT_MAX

ll t;

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        v<v<ll>> arr(n, v<ll>(m, 0));
        if (!(n * a == m * b))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        ll d = 1;
        for (ll i = 1; i < m; i++)
        {
            if ((i * n) % m == 0)
                d = i;
        }
        for (ll i = 0, dx = 0; i < n; i++, dx += d)
        {
            for (int j = 0; j < a; j++)

                arr[i][(j + dx) % m] = 1;
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
}