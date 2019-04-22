#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
//! 点iから右/左に進んで点iに戻ってくる時の最小値
ll LE[200005];
ll RE[200005];

//! 点iから右/左に進んで戻ってこない時の最小値
ll LO[200005];
ll RO[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    {
        ll sum = 0;
        LE[0] = 0;
        FOR(i, N + 1, 1)
        {
            sum += A[i - 1];
            ll t = A[i - 1] % 2;
            if (A[i - 1] == 0)
                t = 2;
            LE[i] = std::min(LE[i - 1] + t, sum);
        }
    }

    {
        ll sum = 0;
        RE[N] = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            sum += A[i];
            ll t = A[i] % 2;
            if (A[i] == 0)
                t = 2;
            RE[i] = std::min(RE[i + 1] + t, sum);
        }
    }
    LO[0] = 0;
    FOR(i, N + 1, 1)
    {
        ll t = 1 - (A[i - 1] % 2);
        LO[i] = std::min(LO[i - 1] + t, LE[i - 1] + t);
    }
    RO[N] = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        ll t = 1 - (A[i] % 2);
        RO[i] = std::min(RO[i + 1] + t, RE[i + 1] + t);
    }

    ll min = INF;
    REP(i, N + 1)
    {
        //! 右に行ってから左に行く
        ll m0 = RE[i] + std::min(LE[i], LO[i]);
        min = std::min(min, m0);
        //! 左に行ってから右に行く
        ll m1 = LE[i] + std::min(RE[i], RO[i]);
        min = std::min(min, m1);
    }
    cout << min << endl;
    return 0;
}