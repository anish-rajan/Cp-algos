#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 1003
ll t, b, t1, t2;
v<ll> ans(102);
v<pair<ll, ll>> arrs(102);
v<pair<ll, ll>> rel(102);
// 0 means nothing
// 1 means reversal
//2 means complement
//3 means both
ll outp(ll val)
{
    ll t1;
    cout << val << endl;
    cin >> t1;
    // if (t1 == 'N')
    //     exit(0);
    // else
    return t1;
}
pair<ll, ll> comp1(ll temp, ll val1, ll val2)
{
    if (val1 == val2)
    {
        if (temp == 0 || temp == 1)
            return mp(val1, val2);
        else if (temp == 2 || temp == 3)
            return mp(!val1, !val2);
    }
    else
    {
        if (temp == 0 || temp == 3)
            return mp(val1, val2);
        else if (temp == 1 || temp == 2)
            return mp(!val1, !val2);
    }
    return mp(0, 0);
}
ll comp(ll t1, ll t2, ll x, ll z)
{
    if (t1 == -1)
    {
        return t2 == z ? 0 : 2;
    }
    else if (t2 == -1)
    {
        return t1 == x ? 0 : 2;
    }
    else
    {
        if (t1 == x)
        {
            if (t2 == z)
                return 0;
            else
                return 3;
        }
        else
        {
            if (t2 == z)
                return 1;
            else
                return 2;
        }
    }
}
ll comp3(ll i, ll &counter)
{
    ll t1 = -1, t2 = -1;
    if (rel[(i - 1) / 5 + 1].fi != 0)
    {
        t1 = outp(rel[(i - 1) / 5 + 1].fi);
        rel[1].fi = rel[(i - 1) / 5 + 1].fi;
    }
    else
    {
        outp(1);
    }
    if (rel[(i - 1) / 5 + 1].se != 0)
    {
        t2 = outp(rel[(i - 1) / 5 + 1].se);
        rel[1].se = rel[(i - 1) / 5 + 1].se;
    }
    else
        outp(1);
    counter += 2;
    return comp(t1, t2, arrs[rel[(i - 1) / 5 + 1].fi].fi, arrs[rel[(i - 1) / 5 + 1].se].fi);
}
string comp_outp()
{
    string s;
    for (ll i = 1; i <= b / 2; i++)
    {
        ans[i] = arrs[i].fi;
        ans[b - i + 1] = arrs[i].se;
    }
    for (ll i = 1; i <= b; i++)
    {
        s += (ans[i] + '0');
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t >> b;
    for (ll i = 0; i < t; i++)
    {
        fill(rel.begin(), rel.end(), mp(0, 0));
        fill(arrs.begin(), arrs.end(), mp(0, 0));
        for (ll i = 1; i <= (b / 2); i++)
        {
            t1 = outp(i);
            if (t1 == 'N')
            {
                exit(0);
            }
            t2 = outp(b - i + 1);
            if (t2 == 'N')
            {
                exit(0);
            }
            arrs[i].first = t1;
            arrs[i].second = t2;
            if (t1 != t2)
            {
                rel[(i - 1) / 5 + 1].fi = i;
            }
            else
            {
                rel[(i - 1) / 5 + 1].se = i;
            }
        }
        ll counter = 0;
        for (ll i = 1; i <= b / 2; i += 5)
        {
            if (counter <= 8)
            {
                ll temp = comp3(i, counter);
                for (ll j = i; j < i + 5; j++)
                {
                    pair<ll, ll> temp1 = comp1(temp, arrs[j].fi, arrs[j].se);
                    arrs[j].fi = temp1.fi, arrs[j].se = temp1.se;
                }
            }
            else if (counter <= 30)
            {
                if (counter == 10 || counter == 20)
                {
                    ll temp = comp3(1, counter);
                    for (ll j = 1; j < i; j++)
                    {
                        pair<ll, ll> temp1 = comp1(temp, arrs[j].fi, arrs[j].se);
                        arrs[j].fi = temp1.fi, arrs[j].se = temp1.se;
                    }
                }
                ll temp = comp3(i, counter);
                for (ll j = i; j < i + 5; j++)
                {
                    pair<ll, ll> temp1 = comp1(temp, arrs[j].fi, arrs[j].se);
                    arrs[j].fi = temp1.fi, arrs[j].se = temp1.se;
                }
            }
        }
        char p;
        string s = comp_outp();
        cout << s << endl;
        cin >> p;
        if (p == 'N')
            exit(0);
    }
    exit(0);
}