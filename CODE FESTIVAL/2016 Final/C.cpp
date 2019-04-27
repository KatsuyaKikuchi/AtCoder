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

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf(M);
    vector<int> L;
    REP(i, N)
    {
        int k;
        cin >> k;
        REP(j, k)
        {
            int l;
            cin >> l;
            if (j > 0)
                uf.unit(L[L.size() - 1], l);
            L.push_back(l);
        }
    }
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    REP(i, L.size() - 1)
    {
        if (uf.same(L[i], L[i + 1]))
            continue;
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}