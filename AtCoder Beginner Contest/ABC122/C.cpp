#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll D[100005];

int main()
{
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    D[0] = 0;
    REP(i, N)
    {
        D[i + 1] = D[i];
        if (i > 0 && S[i] == 'C' && S[i - 1] == 'A')
        {
            D[i + 1]++;
        }
    }
    REP(i, Q)
    {
        ll l, r;
        cin >> l >> r;
        ll s = D[r] - D[l - 1];
        if (l - 2 >= 0 && S[l - 2] == 'A' && S[l - 1] == 'C')
            s--;
        cout << s << endl;
    }
    return 0;
}