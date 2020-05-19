#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 300005
ll n;
vector<ll> ans;
ll maxlength = 0;
vector<long long int> arr(N);
vector<vector<long long int>> st(N, vector<long long int>(log2(N) + 3));
vector<vector<long long int>> st1(N, vector<long long int>(log2(N) + 3));

long long int merge(long long int val)
{
    return val;
}

long long int merge(long long int val1, long long int val2)
{
    return __gcd(val1, val2);
}
long long int merge1(long long int val1, long long int val2)
{
    return min(val1, val2);
}

void createTable()
{
    long long int K = log2(N);
    for (int i = 0; i < N; i++)
    {
        st[i][0] = merge(arr[i]);
        st1[i][0] = merge(arr[i]);
    }

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
        {
            st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            st1[i][j] = merge1(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
        }
}

//queries which take order 1 time
pair<long long int, ll> rangequery(long long int L, long long int R)
{
    long long int j = log2(R - L + 1);
    long long int val = merge(st[L][j], st[R - (1 << j) + 1][j]);
    ll val2 = merge1(st1[L][j], st1[R - (1 << j) + 1][j]);
    return make_pair(val, val2);
}
vector<ll> compute(ll length)
{
    vector<ll> ans1;
    for (ll i = 0; i + length - 1 < n; i++)
    {
        pair<ll, ll> temp = rangequery(i, i + length - 1);
        // cout << i << " " << length << " " << temp.first << " " << temp.second << "\n";
        if (temp.first == temp.second)
        {
            ans1.push_back(i);
        }
    }
    return ans1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    createTable();
    ll l = 1, r = n;
    vector<ll> tempans;
    ll mid = 1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        tempans = compute(mid);
        if (tempans.size() > 0)
        {
            l = mid + 1;
            ans = tempans;
            maxlength = mid - 1;
        }
        else
            r = mid - 1;
    }
    cout << ans.size() << " " << maxlength << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}