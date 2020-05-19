#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 1002
#define N1 62 * 62
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> primes;
    vector<ll> prime_check(N);
    for (ll i = 2; i < N; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j < N; j += i)
            {
                prime_check[j] = 1;
            }
    }
    for (ll i = 2; i < N; i++)
    {
        if (!prime_check[i])
            primes.push_back(i);
    }
    cin >> t;
    while (t--)
    {
        ll n, colors = 0;
        v<ll> prime_c(N);
        cin >> n;
        v<ll> arr(n), color(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            ll temp = arr[i];
            ll f = 0;
            for (ll j = 0; j < primes.size(); j++)
            {
                if (temp % primes[j] == 0 && prime_c[primes[j]])
                {
                    f = 1;
                    color[i] = prime_c[primes[j]];
                    break;
                }
            }
            if (f == 0)
            {
                colors++;
                for (ll j = 0; j < primes.size(); j++)
                {
                    if (temp % primes[j] == 0)
                    {
                        prime_c[primes[j]] = colors;
                        color[i] = colors;
                        break;
                    }
                }
            }
        }
        cout << colors << "\n";
        for (ll i = 0; i < n; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
    }
}