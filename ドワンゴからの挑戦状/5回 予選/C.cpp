#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, Q;
string S;

ll solve(ll k)
{
    ll s = 0;
    ll sum = 0;
    ll D = 0, M = 0, C = 0;
    REP(i, N)
    {
        if (i - s >= k)
        {
            if (S[s] == 'D')
            {
                D--;
                C -= M;
            }
            else if (S[s] == 'M')
                M--;
            s++;
        }

        if (S[i] == 'D')
            D++;
        else if (S[i] == 'M')
        {
            M++;
            C += D;
        }
        else if (S[i] == 'C')
            sum += C;
    }
    return sum;
}

int main()
{
    cin >> N >> S >> Q;
    REP(i, Q)
    {
        ll k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}