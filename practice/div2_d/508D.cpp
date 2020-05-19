#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define N1 62 * 62
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, c;
map<string, ll> a;
map<ll, string> b;
v<v<ll>> gr(N1, v<ll>(N1));
vector<string> subs(N);
v<ll> indeg(N1), outdeg(N1);
list<ll> ans;
void euler_path(ll node, list<ll>::iterator iter)
{
    for (ll i = 0; i < c; i++)
    {
        if (gr[node][i])
        {
            gr[node][i]--;
            euler_path(i, ans.insert(iter, i));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    c = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> subs[i];
        string s = subs[i].substr(0, 2), t = subs[i].substr(1, 2);
        if (a.count(s) == 0)
        {
            a[s] = c;
            b[c++] = s;
        }
        if (a.count(t) == 0)
        {
            a[t] = c;
            b[c++] = t;
        }
        gr[a[s]][a[t]]++;
        outdeg[a[s]]++;
        indeg[a[t]]++;
    }
    string ans1;
    ll f = 0, temp1 = 0, temp2 = 0, st = 0;
    for (ll i = 0; i < c; i++)
    {
        if (indeg[i] == outdeg[i] + 1)
            temp1++;
        else if (outdeg[i] == indeg[i] + 1)
            temp2++, st = i;
    }
    if (temp1 == temp2 && temp1 <= 1)
    {
        euler_path(st, ans.insert(ans.begin(), st));
        // cout << ans.size();
        if (ans.size() == n + 1)
        {
            f = 1;
            reverse(ALL(ans));
            auto iter = ans.begin();
            ans1 += b[*iter];
            iter++;
            for (; iter != ans.end(); iter++)
            {
                ans1 += b[*iter][1];
            }
            cout << "YES\n";
            cout << ans1 << "\n";
        }
        else
            f = 0;
    }
    if (f == 0)
        cout << "NO\n";
    return 0;
}