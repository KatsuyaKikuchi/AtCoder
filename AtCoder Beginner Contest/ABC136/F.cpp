#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll)1e15;

class BinaryIndexTree
{
public:
    BinaryIndexTree(int n)
        : mN(n)
    {
        mPow = 1;
        while (mPow < n)
            mPow <<= 1;
        node.resize(n + 1);
        REP(i, n + 1)
        {
            node[i] = 0;
        }
    }
    ~BinaryIndexTree()
    {
        node.resize(0);
    }

    //! 1-index get
    ll sum(int index)
    {
        ll sum = 0;
        for (int i = index; i > 0; i -= i & (-i))
            sum += node[i];
        return sum;
    }

    //! 1-index add
    void add(int index, ll value)
    {
        for (int i = index; i <= mN; i += i & (-i))
            node[i] += value;
    }

    int lowerBound(ll value)
    {
        if (value <= 0)
            return 0;
        int x = 0;
        for (int k = mPow; k > 0; k >>= 1)
        {
            if (x + k <= mN && node[x + k] < value)
            {
                value -= node[x + k];
                x += k;
            }
        }
        return x + 1;
    }

private:
    vector<ll> node;
    ll mN;
    ll mPow;
};

pll S[200005];
ll P[200005];
pll L[200005];
pll R[200005];

int main()
{
    ll N;
    cin >> N;
    vector<ll> y;
    REP(i, N)
    {
        cin >> S[i].first >> S[i].second;
        y.push_back(S[i].second);
    }

    sort(S, S + N, [](pll a, pll b) { return a.first < b.first; });
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    P[0] = 1;
    REP(i, N)
    {
        P[i + 1] = (2LL * P[i]) % MOD;
    }

    BinaryIndexTree bitl(N + 5);
    REP(i, N)
    {
        ll yn = lower_bound(y.begin(), y.end(), S[i].second) - y.begin();
        yn++;
        ll down = bitl.sum(yn);
        L[i] = pll(i - down, down);
        bitl.add(yn, 1);
    }
    BinaryIndexTree bitr(N + 5);
    for (int i = N - 1; i >= 0; --i)
    {
        ll yn = lower_bound(y.begin(), y.end(), S[i].second) - y.begin();
        yn++;
        ll down = bitr.sum(yn);
        R[i] = pll(N - 1 - i - down, down);
        bitr.add(yn, 1);
    }

    ll ans = 0;

    REP(i, N)
    {
        ll p = P[N] - 1;
        {
            //! 四隅だけ
            ll t = 0;
            t += P[R[i].first] - 1;
            t += P[R[i].second] - 1;
            t += P[L[i].first] - 1;
            t += P[L[i].second] - 1;
            t %= MOD;
            p = (MOD + p - t) % MOD;
        }

        {
            //! 隣り合う二つだけ
            ll t = 0;
            t += (P[R[i].first] - 1) * (P[R[i].second] - 1);
            t += (P[R[i].second] - 1) * (P[L[i].second] - 1);
            t += (P[L[i].second] - 1) * (P[L[i].first] - 1);
            t += (P[L[i].first] - 1) * (P[R[i].first] - 1);
            t %= MOD;
            p = (MOD + p - t) % MOD;
        }
        ans += p;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}