#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
// #define ll int
string s;
ll k;
vector<ll> no(N);

string find_ans(vector<ll> sa, ll k, ll sz)
{
    ll n = sa.size();
    ll n1 = s.size();
    ll i = 0, var = 0;
    while (k > 0)
    {
        ll j = i, temp = k;
        for (; j < n; j++)
        {
            temp -= sz - sa[j];
            if (j != n - 1)
            {
                if (s[sa[j]] != s[sa[j + 1]])
                {
                    var = j;
                    break;
                }
            }
            else
            {
                var = j;
                break;
            }
        }
        if (temp <= 0)
            break;
        else
        {
            k = temp;
            i = j + 1;
        }
        // cout << k << "\n";
    }
    // cout << i << " " << var << "\n";
    if (i == var)
    {
        return s.substr(sa[i], k);
    }
    string ans;
    ans += s[sa[i]];
    if (k > (var - i + 1))
    {
        k -= var - i + 1;
        vector<ll> sa1;
        for (ll j = i; j <= var; j++)
        {
            sa[j]++;
            if (sa[j] < sz)
                sa1.push_back(sa[j]);
        }
        return ans + find_ans(sa1, k, sz);
    }
    else
    {
        return ans;
    }
}

struct SA
{
    ll MAXN = 1 << 21;
    string s;
    ll sz, gap;
    vector<ll> sa, pos, tmp, lcp;

    SA(string t)
    {
        s = t;
        sz = s.size();
        sa.resize(sz);
        pos.resize(sz);
        tmp.resize(sz);
        lcp.resize(sz);
    }

    bool sufCmp(ll i, ll j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < sz && j < sz) ? pos[i] < pos[j] : i > j;
        // return i > j;
    }

    void buildSA()
    {
        for (ll i = 0; i < sz; i++)
        {
            sa[i] = i;
            pos[i] = s[i];
        }
        for (gap = 1;; gap *= 2)
        {
            sort(sa.begin(), sa.begin() + sz, [=](ll i, ll j) -> bool {
                if (pos[i] != pos[j])
                    return pos[i] < pos[j];
                i += gap;
                j += gap;
                return (i < sz && j < sz) ? pos[i] < pos[j] : i > j;
            });
            for (ll i = 0; i < sz - 1; i++)
                tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            for (ll i = 0; i < sz; i++)
                pos[sa[i]] = tmp[i];
            if (tmp[sz - 1] == sz - 1)
                break;
        }
    }

    void buildLCP()
    {
        buildSA();
        for (ll i = 0, k = 0; i < sz; ++i)
            if (pos[i] != sz - 1)
            {
                for (ll j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
                    ++k;
                lcp[pos[i]] = k;
                if (k)
                    --k;
            }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> k;
    SA sa(s);
    // sa.buildSA();
    sa.buildLCP();
    string ans;
    if (k > (sa.sz * (sa.sz + 1)) / 2)
    {
        ans = "No such line.";
    }
    else
    {
        ans = find_ans(sa.sa, k, sa.sz);
    }
    cout << ans << "\n";
}