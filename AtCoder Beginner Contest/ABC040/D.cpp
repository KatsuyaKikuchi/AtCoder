#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class UnionFind
{
public:
    UnionFind(int n)
        : mN(n)
    {
        REP(i, n)
        {
            mNodeTbl.push_back(i);
            mRankTbl.push_back(0);
            mNumTbl.push_back(1);
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
    int get(int x)
    {
        x = find(x);
        return mNumTbl[x];
    }
    void unit(int x, int y)
    {
        x = find(x);
        y = find(y);
        int nx = mNumTbl[x];
        int ny = mNumTbl[y];
        if (x == y)
            return;
        if (mRankTbl[x] < mRankTbl[y])
        {
            mNodeTbl[x] = y;
            mNumTbl[y] = nx + ny;
        }
        else
        {
            mNodeTbl[y] = x;
            mNumTbl[x] = nx + ny;
            if (mRankTbl[x] == mRankTbl[y])
                mRankTbl[x]++;
        }
    }

private:
    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
    vector<int> mNumTbl;
};

struct Edge
{
    ll a;
    ll b;
    ll y;
};
struct People
{
    ll v;
    ll y;
    ll i;
};

int main()
{
    ll N, M;
    cin >> N >> M;
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q([](Edge a, Edge b) { return a.y < b.y; });
    REP(i, M)
    {
        ll a, b, y;
        cin >> a >> b >> y;
        q.push(Edge{a - 1, b - 1, y});
    }
    ll Q;
    cin >> Q;
    priority_queue<People, vector<People>, function<bool(People a, People b)>> r([](People a, People b) { return a.y < b.y; });
    REP(i, Q)
    {
        ll v, w;
        cin >> v >> w;
        r.push(People{v - 1, w, i});
    }
    vector<ll> ans(Q);
    UnionFind uf(N);
    while (!q.empty())
    {
        auto edge = q.top();
        q.pop();

        while (!r.empty() && r.top().y >= edge.y)
        {
            auto people = r.top();
            r.pop();
            ans[people.i] = uf.get(people.v);
        }
        uf.unit(edge.a, edge.b);
    }

    while (!r.empty())
    {
        auto people = r.top();
        r.pop();
        ans[people.i] = uf.get(people.v);
    }

    REP(i, Q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}