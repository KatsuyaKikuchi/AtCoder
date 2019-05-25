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

int X[100005], Y[100005], Z[100005];
bool U[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    REP(i, M)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;

        uf.unit(X[i], Y[i]);
    }
    memset(U, 0, sizeof(U));
    REP(i, N)
    {
        U[uf.find(i)] = true;
    }
    int ans = 0;
    REP(i, N)
    {
        if (U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}