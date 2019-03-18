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
    ll c;
};
struct Vertex
{
    vector<pll> node;
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

ll A[305][305];
ll M[305][305];
Vertex V[305];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> A[i][j];
            M[i][j] = INF;
            if (i == j)
                M[i][j] = 0;
        }
    }

    vector<Node> n;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            Node t;
            t.a = i;
            t.b = j;
            t.c = A[i][j];
            n.push_back(t);
        }
    }

    sort(n.begin(), n.end(), [](Node a, Node b) { return a.c < b.c; });

    UnionFind uf;
    uf.init(N);
    ll sum = 0;
    REP(i, n.size())
    {
        Node t = n[i];
        if (!uf.same(t.a, t.b))
        {
            sum += t.c;
            uf.unit(t.a, t.b);
            V[t.a].node.push_back(pll(t.b, t.c));
            V[t.b].node.push_back(pll(t.a, t.c));
            continue;
        }

        auto l = [](pll a, pll b) { return a.second > b.second; };
        priority_queue<pll, vector<pll>, decltype(l)> q(l);
        q.push(pll(t.a, 0));
        ll mc = M[t.a][t.b];
        while (!q.empty())
        {
            pll p = q.top();
            q.pop();
            if (p.first == t.b)
            {
                mc = std::min(mc, p.second);
            }
            REP(j, V[p.first].node.size())
            {
                ll cost = p.second + V[p.first].node[j].second;
                if (cost > t.c)
                    continue;
                if (M[t.a][V[p.first].node[j].first] < cost)
                    continue;
                M[t.a][V[p.first].node[j].first] = M[V[p.first].node[j].first][t.a] = cost;
                q.push(pll(V[p.first].node[j].first, cost));
            }
        }
        if (mc < t.c)
        {
            sum = -1;
            break;
        }
        if (mc > t.c)
        {
            sum += t.c;
            uf.unit(t.a, t.b);
            V[t.a].node.push_back(pll(t.b, t.c));
            V[t.b].node.push_back(pll(t.a, t.c));
        }
    }

    cout << sum << endl;
    return 0;
}