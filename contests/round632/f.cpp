#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 500005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
string s;
ll n;
v<ll> primes, prime_check(N), mpd(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 2; i <= n; i++)
    {
        if (!prime_check[i])
            for (ll j = 2 * i; j <= n; j += i)
            {
                if (!mpd[j])
                    mpd[j] = i;
                prime_check[j] = 1;
            }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (!prime_check[i])
        {
            mpd[i] = i;
            primes.push_back(i);
        }
    }
    ll counter = 2;
    cout << 1 << " ";
    for (ll j = 1; j < primes.size() && counter < n; j++, counter++)
        cout << 1 << " ";
    for (ll i = 2; counter < n; i++)
    {
        for (ll j = 0; primes[j] <= mpd[i] && counter < n; j++, counter++)
        {
            if (i * primes[j] <= n && primes[j] <= i)
                cout << i << " ";
            else
                break;
        }
    }
    cout << endl;
    return 0;
}