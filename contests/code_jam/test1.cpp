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
ll t, b;
// 0 means nothing
// 1 means reversal
//2 means complement
//3 means both
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
        return t2 == z ? 1 : 2;
    }
    else if (t2 == -1)
    {
        return t1 == x ? 3 : 2;
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
ll comp3(ll i, v<pair<ll, ll>> &rel, v<pair<ll, ll>> vals, ll &counter)
{
    ll t1 = -1, t2 = -1;
    ll temp;
    if (rel[(i - 1) / 5 + 1].fi != 0)
    {
        cout << rel[(i - 1) / 5 + 1].fi << endl;
        fflush(stdout);
        cin >> t1;
        if (t1 == 'N')
            return 0;
        rel[1].fi = rel[(i - 1) / 5 + 1].fi;
        counter++;
    }
    if (rel[(i - 1) / 5 + 1].se != 0)
    {
        cout << rel[(i - 1) / 5 + 1].se << endl;
        fflush(stdout);
        cin >> t2;
        if (t2 == 'N')
            return 0;
        rel[1].se = rel[(i - 1) / 5 + 1].se;
        counter++;
    }
    temp = comp(t1, t2, vals[rel[(i - 1) / 5 + 1].fi].fi, vals[rel[(i - 1) / 5 + 1].se].fi);
    return temp;
}
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
char outp_string(string s)
{
    char p;
    cout << s << endl;
    cin >> p;
    // if (p == 'N')
    //     exit(0);
    // else
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    ll t1;
    for (ll i = 0; i < t; i++)
    {
        cin >> b;
        // t1 = outp(101);
        char p = outp_string("1010101010");
        // if (p == 'Y')
        //     continue;
        // else
        //     return 0;
    }
}