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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll L = 0, R = 0;
    ll sum = 0;
    REP(i, N)
    {
        if (i == 0 || S[i - 1] != S[i])
        {
            if (S[i] == 'L')
                L++;
            else
                R++;
        }
        else
        {
            sum++;
        }
    }

    ll f = std::min(L, R);
    ll ans = std::min(N - 1, sum + std::min(f, K) * 2);
    cout << ans << endl;
    return 0;
}