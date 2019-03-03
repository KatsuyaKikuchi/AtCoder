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

  private:
    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
};

pll B[100005];
//! そのノードに属するVertexの数
ll VN[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> B[i].first >> B[i].second;
    }
    REP(i, N)
    {
        VN[i] = 1;
    }

    UnionFind uf(N);

    ll sum = N * (N - 1) / 2;
    vector<ll> ans(M, 0);
    for (int i = M - 1; i >= 0; --i)
    {
        ans[i] = sum;
        pll n = B[i];
        if (uf.same(n.first, n.second))
            continue;

        ll a = VN[uf.find(n.first)];
        ll b = VN[uf.find(n.second)];
        sum -= (a * b);
        uf.unit(n.first, n.second);
        VN[uf.find(n.first)] = a + b;
    }

    REP(i, M)
    {
        cout << ans[i] << endl;
    }
    return 0;
}