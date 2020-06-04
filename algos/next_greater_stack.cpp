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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 31622779
#define mod 998244353

using S = ll;

//// pass third parameter like this lesser////////

bool lesser(S a, S b)
{
    return a <= b;
}
bool great(S a, S b)
{
    return a >= b;
}

vector<pair<S, S>> pge(vector<S> a, S n, function<bool(S, S)> func)
{
    vector<pair<S, S>> L(n + 1, {0, 0});
    stack<S> s;
    for (int i = 1; i <= n; i++)
    {
        while (s.size() && func(a[s.top()], a[i]))
            s.pop();
        if (s.size())
            L[i].fi = s.top();
        s.push(i);
        L[i].se = i;
    }
    return L;
}
vector<pair<S, S>> pge1(vector<S> a, S n, function<bool(S, S)> func)
{
    vector<pair<S, S>> L(n + 1, {n + 1, n + 1});
    stack<S> s;
    for (int i = n; i >= 1; i--)
    {
        while (s.size() && func(a[s.top()], a[i]))
            s.pop();
        if (s.size())
            L[i].fi = s.top();
        s.push(i);
        L[i].se = i;
    }
    return L;
}