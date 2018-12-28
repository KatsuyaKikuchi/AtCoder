#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Node
{
    int a;
    int b;
    int c;
    int t;
};
struct Cost
{
    double n;
    int a;
    int b;
};
struct UnionFind
{
    void init(int n)
    {
        mN = n;
        mNodeTbl.resize(mN);
        REP(i, mN)
        {
            mNodeTbl[i] = i;
        }
    }
    int find(int x)
    {
        if (x == mNodeTbl[x])
            return x;
        return mNodeTbl[x] = find(mNodeTbl[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    void unit(int x, int y)
    {
        x = find(x);
        y = find(y);
        mNodeTbl[x] = y;
    }

    int mN;
    vector<int> mNodeTbl;
};

int N, M;
Node n[10005];

//! 時給m以内で全ての村をつなぐ橋がかけられるか
bool check(double m)
{
    vector<Cost> c(M);
    REP(i, M)
    {
        Cost t;
        t.n = n[i].c - n[i].t * m;
        t.a = n[i].a;
        t.b = n[i].b;
        c[i] = t;
    }
    sort(c.begin(), c.end(), [](Cost a, Cost b) { return a.n < b.n; });
    double cost = 0;
    UnionFind uf;
    uf.init(N);
    REP(i, M)
    {
        if (c[i].n > 0)
        {
            if (uf.same(c[i].a, c[i].b))
                continue;
        }
        cost += c[i].n;
        uf.unit(c[i].a, c[i].b);
    }
    return cost<=0.0;
}

int main()
{
    cin >> N >> M;

    ll sum = 0;
    REP(i, M)
    {
        cin >> n[i].a >> n[i].b >> n[i].c >> n[i].t;
        sum += n[i].c;
    }

    double ok = INF, ng = 0;
    REP(i, 100)
    {
        double mid = (ok + ng) * 0.5;
        if (check(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << OF64 << ok << endl;
    return 0;
}