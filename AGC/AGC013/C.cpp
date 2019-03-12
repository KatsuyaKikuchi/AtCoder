#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll X[100005];
ll Y[100005];

int main()
{
    ll N, L, T;
    cin >> N >> L >> T;
    REP(i, N)
    {
        cin >> X[i].first >> X[i].second;
        if (X[i].second == 1)
            Y[i] = (X[i].first + T) % L;
        else
            Y[i] = (L + X[i].first - (T % L)) % L;
    }

    ll n = 0;
    bool same = false;
    FOR(i, N, 1)
    {
        if (X[i].second == X[0].second)
            continue;
        //! X[0]と何回ぶつかるか？
        ll l = X[i].first - X[0].first;
        if (X[0].second == 2)
            l = L - l;
        if (2LL * T - l < 0)
            continue;
        n += 1 + (2LL * T - l) / L;
        if ((2LL * T - l) % L == 0)
            same = true;
    }
    n %= N;
    //! Y[0]にいるindex
    int k = X[0].second == 1 ? n : (N - n) % N;
    ll x = Y[0];

    sort(Y, Y + N);
    int j = 0;
    REP(i, N)
    {
        if (x == Y[i])
        {
            j = i;
            break;
        }
    }
    int t = N + j - k;
    if (same && X[0].second == 1)
        t++;

    REP(i, N)
    {
        cout << Y[(i + t) % N] << endl;
    }
    return 0;
}