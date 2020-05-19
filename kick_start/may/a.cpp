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
#define N 200005
#define mod 1000000007
#define INF INT64_MAX
ll t;
ll n, k;
v<ll> a(N), b(N);
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

vector<long long int> prefix_function()
{
    long long int n = (long long int)b.size();
    vector<long long int> pi(n);
    for (long long int i = 1; i < n; i++)
    {
        long long int j = pi[i - 1];
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];
        if (b[i] == b[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll KMPSearch()
{
    long long int m = k;
    ll count = 0;
    vector<long long int> pi;
    pi = prefix_function();

    long long int i = 0; // index for txt[]
    long long int j = 0; // index for pat[]
    while (i < n)
    {
        if (b[j] == a[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            count++;
            j = pi[j - 1];
        }

        // mismatch after j matches
        else if (i < n && b[j] != a[i])
        {
            // Do not match pi[0..pi[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = pi[j - 1];
            else
                i = i + 1;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> k;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < k; i++)
            b[i] = k - i;
        ll count = KMPSearch();
        cout << "Case #" << i << ": " << count << "\n";
    }
}