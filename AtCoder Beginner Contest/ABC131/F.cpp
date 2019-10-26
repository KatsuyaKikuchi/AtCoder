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

struct Group
{
    vector<ll> v;
    ll g;
};

pll A[100005];

int main()
{
    ll N;
    cin >> N;
    vector<ll> X;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });
    vector<Group> G(X.size());
    REP(i, N)
    {
        ll x = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
        G[x].v.push_back(A[i].second);
    }

    UnionFind uf(X.size());
    REP(i, N - 1)
    {
        if (A[i].second == A[i + 1].second)
        {
            ll x0 = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
            ll x1 = lower_bound(X.begin(), X.end(), A[i + 1].first) - X.begin();
            uf.unit(x0, x1);
        }
    }

    REP(i, G.size())
    {
        G[i].g = uf.find(i);
    }
    sort(G.begin(), G.end(), [](Group a, Group b) { return a.g < b.g; });

    ll ans = 0;
    ll row = 0, col = 0;
    vector<ll> v;
    REP(i, G.size())
    {
        row++;
        col += G[i].v.size();
        REP(j, G[i].v.size())
        {
            v.push_back(G[i].v[j]);
        }

        if (i == G.size() - 1 || G[i].g != G[i + 1].g)
        {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());

            ans += std::max(0LL, static_cast<ll>(v.size() * row - col));
            v.clear();
            row = col = 0;
        }
    }

    cout << ans << endl;

    return 0;
}