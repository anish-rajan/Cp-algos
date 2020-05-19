#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n;
v<ll> nos(N), counter(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    ll m1, m2 = -1, tempo = n;
    for (ll i = 0; i < n; i++)
    {
        cin >> nos[i];
    }
    m1 = nos[0];
    for (ll i = 1; i < n; i++)
    {
        if (nos[i] < m1 && nos[i] > m2)
        {
            counter[m1]++;
        }
        if (m1 < nos[i])
        {
            m2 = m1;
            m1 = nos[i];
        }
        else if (m2 < nos[i])
        {
            m2 = nos[i];
        }
        else if (nos[i] < m2)
        {
            tempo = min(tempo, nos[i]);
        }
    }
    ll ans = 1;
    m1 = counter[1];
    for (ll i = 1; i <= n; i++)
    {
        if (counter[i] > m1)
        {
            m1 = counter[i];
            ans = i;
        }
        // cout << counter[i] << "\n";
    }
    if (m1 == 0 || m1 == 1)
    {
        ans = tempo;
        if (tempo == n)
            ans = 1;
    }
    cout << ans << "\n";
}