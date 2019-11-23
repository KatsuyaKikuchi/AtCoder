#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
pll S[100005];

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

    ll numGroup()
    {
        ll num = 1;
        REP(i, N - 1)
        {
            ll a = find(i);
            ll b = find(i + 1);
            if (a != b)
                num++;
        }
        return num;
    }

private:
    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
};

bool solve()
{
    vector<ll> A, B;
    REP(i, N)
    {
        A.push_back(S[i].first);
        B.push_back(S[i].second);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    REP(i, N)
    {
        if (A[i] > B[i])
            return false;
    }
    sort(S, S + N, [](pll a, pll b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });

    B.erase(unique(B.begin(), B.end()), B.end());
    if (B.size() < N)
        return true;
    UnionFind uf(N);
    REP(i, N)
    {
        ll t = lower_bound(B.begin(), B.end(), S[i].second) - B.begin();
        uf.unit(t, i);
    }

    return uf.numGroup() > 1;
}
int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> S[i].first;
    }
    REP(i, N)
    {
        cin >> S[i].second;
    }

    if (solve())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}