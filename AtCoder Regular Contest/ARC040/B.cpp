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
    ll N, R;
    cin >> N >> R;
    string S;
    cin >> S;

    ll last = 0;
    REP(i, N)
    {
        if (S[i] == '.')
            last = i;
    }

    ll ans = std::max(0LL, last - R + 1);
    int index = N - 1;
    while (index >= 0)
    {
        if (S[index] == 'o')
        {
            index--;
            continue;
        }
        ans++;
        index -= R;
    }
    cout << ans << endl;

    return 0;
}