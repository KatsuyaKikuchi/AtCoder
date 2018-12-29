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
    ll x;
    ll y;
    int i;
};
struct Cost
{
    int a;
    int b;
    ll c;
};
struct UnionFind
{
    void init(int n)
    {
        mN = n;
        mNodeTbl.resize(mN);
        mRankTbl.resize(mN);
        REP(i, mN)
        {
            mNodeTbl[i] = i;
            mRankTbl[i] = 0;
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
        if (x == y)
            return;
        if (mRankTbl[x] < mRankTbl[y])
        {
            mNodeTbl[x] = y;
        }
        else
        {
            mNodeTbl[y] = x;
            if (mRankTbl[x] == mRankTbl[y])
                mRankTbl[x]++;
        }
    }

    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
};

int N;
Node n[100005];
vector<Cost> C;
void push()
{
    REP(i, N)
    {
        if (i + 1 < N)
        {
            Cost t;
            t.a = n[i + 1].i;
            t.b = n[i].i;
            t.c = min(abs(n[i + 1].x - n[i].x), abs(n[i + 1].y - n[i].y));
            C.push_back(t);
        }
    }
}

int main()
{

    cin >> N;
    REP(i, N)
    {
        cin >> n[i].x >> n[i].y;
        n[i].i = i;
    }
    sort(n, n + N, [](Node a, Node b) { return a.x < b.x; });
    push();
    sort(n, n + N, [](Node a, Node b) { return a.y < b.y; });
    push();
    sort(C.begin(), C.end(), [](Cost a, Cost b) { return a.c < b.c; });
    UnionFind uf;
    uf.init(N);
    ll cost = 0;
    REP(i, C.size())
    {
        if (uf.same(C[i].a, C[i].b))
            continue;
        uf.unit(C[i].a, C[i].b);
        cost += C[i].c;
    }
    cout << cost << endl;
    return 0;
}