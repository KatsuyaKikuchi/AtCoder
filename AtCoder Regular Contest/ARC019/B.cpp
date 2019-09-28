#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    string S;
    cin >> S;
    ll N = S.length();
    int dif = 0;
    REP(i, N / 2)
    {
        if (S[i] != S[N - 1 - i])
            dif++;
    }

    ll ans = 0;
    if (dif == 0)
    {
        //! すでに回文なので、真ん中以外どれ変えてもいい
        ans = (N / 2) * 50;
    }
    else if (dif == 1)
    {
        //! 1つ変えると回文
        ans = 25 * (N - 2) + 24 * 2;
    }
    else
    {
        //! 変えても回文にならない
        ans = N * 25;
    }
    cout << ans << endl;

    return 0;
}