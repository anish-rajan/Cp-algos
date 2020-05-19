#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF INT_MAX

using S = long long int;

vector<S> a(N);

typedef struct data
{
    S sum, pref, suff, ans;
} data;

struct data tree[4 * N];
// data lazy[4 * N];

struct data combine(struct data l, struct data r)
{
    struct data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
struct data make_data(S val)
{
    struct data res;
    res.sum = val;
    res.pref = res.suff = val;
    return res;
}

void build(S v, S tl, S tr)
{
    if (tl == tr)
    {
        tree[v] = make_data(a[tl]);
    }
    else
    {
        S tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
struct data query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
    {
        return tree[node];
    }
    S tm = (tl + tr) / 2;
    struct data temp = combine(query(node * 2, tl, tm, l, min(r, tm)), query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}
void update(S node, S tl, S tr, S pos, S new_val)
{
    if (tl == tr)
    {
        tree[node] = make_data(new_val);
    }
    else
    {
        S tm = (tl + tr) / 2;
        if (pos <= tm)
            update(node * 2, tl, tm, pos, new_val);
        else
            update(node * 2 + 1, tm + 1, tr, pos, new_val);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

// Lazy updates... currently queries for minimum in a range... lazy may have to be modified for other queries.
S lazy[4 * N];

void push(S node)
{
    tree[node * 2].sum += lazy[node];
    lazy[node * 2] += lazy[node];
    tree[node * 2 + 1].sum += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void lazy_update(S node, S tl, S tr, S l, S r, S addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[node].sum += addend;
        lazy[node] += addend;
    }
    else
    {
        push(node);
        S tm = (tl + tr) / 2;
        lazy_update(node * 2, tl, tm, l, min(r, tm), addend);
        lazy_update(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }
}

struct data lazy_query(S node, S tl, S tr, S l, S r)
{
    if (l > r)
        return make_data(INF);
    if (l <= tl && tr <= r)
        return tree[node];
    push(node);
    S tm = (tl + tr) / 2;
    struct data temp = combine(lazy_query(node * 2, tl, tm, l, min(r, tm)), lazy_query(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return temp;
}