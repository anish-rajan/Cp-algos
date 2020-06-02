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
#define N1 12
#define N2 100005
#define mod 1000000007
#define INF INT_MAX

ll n;
v<ll> a(N), c(N);

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
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], c[a[i]]++;
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 1, currans = 1, ind = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (a[i - 1] == a[i])
            currans++;
        else if (a[i - 1] == (a[i] - 1))
        {
            if (currans == 1)
                currans++;
            else if (c[a[i - 1]] >= 2)
                currans++;
            else
                currans = 2;
        }
        else
            currans = 1;
        if (currans > ans)
            ans = currans, ind = i;
    }
    cout << ans << "\n";
    v<ll> ans1;
    set<ll> nos;
    ll st = ind - ans + 1;
    for (ll i = st; i <= ind; i++)
    {
        nos.insert(a[i]);
    }
    for (auto itr = nos.begin(); itr != nos.end(); itr++)
    {
        ans1.pb(*itr);
    }
    auto itr = nos.end();
    itr--;
    for (;; itr--)
    {
        ll temp = *itr;
        while (c[temp] > 1)
            ans1.pb(temp), c[temp]--;
        if (itr == nos.begin())
            break;
    }
    for (ll i = 0; i < ans1.size(); i++)
        cout << ans1[i] << " ";
    cout << "\n";
}