#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;
#define N 2002
#define N1 8000001
#define N2 4000000
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, k;
v<ll> arr(N), b(N), cum(N);
v<ll> check(N1);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    for (ll i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    cum[0] = arr[0];
    for (ll i = 1; i < k; i++)
    {
        cum[i] = cum[i - 1] + arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        check[b[i] + N2] = 1;
    }
    set<ll> ans;
    for (ll i = 0; i < k; i++)
    {
        set<ll> temp;
        ll poss = b[0] - cum[i];
        // cout << poss << " ";
        for (ll j = 0; j < k; j++)
        {
            poss += arr[j];
            if (poss >= -1 * N2 && poss <= N2)
            {
                if (check[poss + N2])
                {
                    temp.insert(poss);
                }
            }
        }
        // cout << temp.size() << " ";
        ll c = 0;
        for (ll j = 0; j < n; j++)
        {
            auto itr = temp.find(b[j]);
            // cout << *itr << " ";
            if (itr != temp.end())
            {
                c++;
            }
        }
        // cout << c << "\n";
        if (c == n)
        {
            ans.insert(b[0] + cum[i]);
        }
    }
    cout << ans.size() << "\n";
}