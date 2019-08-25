#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[30];
int main()
{
    ll N, L;
    cin >> N >> L;
    REP(i, L + 2)
    {
        std::getline(std::cin, S[i]);
    }

    ll ans = 0;
    REP(i, 2 * N - 1)
    {
        if (S[L + 1][i] == 'o')
            ans = i;
    }
    for (int i = L; i >= 0; --i)
    {
        if (ans > 0 && S[i][ans - 1] == '-')
            ans -= 2;
        else if (ans < 2 * N - 1 && S[i][ans + 1] == '-')
            ans += 2;
    }
    cout << ans / 2 + 1 << endl;
    return 0;
}