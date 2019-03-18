#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! レベルNバーガーの枚数
ll M[55];
//! レベルNバーガーに含まれるパティの数
ll P[55];

//! レベルnバーガーのx下からxマイ目までにパティが何枚含まれるか
ll num(ll n, ll x)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    ll sum = 0;
    //! 一番下はバン
    x--;
    if (x <= M[n - 1])
    {
        return num(n - 1, x);
    }
    sum += P[n - 1];
    x -= M[n - 1];
    if (x > 0)
    {
        sum++;
        x--;
    }
    if (x <= M[n - 1])
    {
        return sum + num(n - 1, x);
    }
    return sum + P[n - 1];
}

int main()
{
    ll N, X;
    cin >> N >> X;
    M[0] = 1;
    P[0] = 1;
    FOR(i, N + 1, 1)
    {
        M[i] = M[i - 1] * 2 + 3;
        P[i] = P[i - 1] * 2 + 1;
    }

    cout << num(N, X) << endl;
    return 0;
}