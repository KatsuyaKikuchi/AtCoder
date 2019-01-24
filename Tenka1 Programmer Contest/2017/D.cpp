#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll S[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> S[i].first >> S[i].second;
    }

    ll max = 0;
    REP(i, 31)
    {
        ll m = 0;
        REP(j, N)
        {
            ll a = S[j].first;
            bool e = true;
            REP(k, 30)
            {
                if (((K >> i) & 1) == 1)
                {
                    if (k < i)
                        continue;
                    if (k == i && ((a >> i) & 1) == 1)
                    {
                        e = false;
                        break;
                    }
                    else if (((a >> k) & 1) > ((K >> k) & 1))
                    {
                        e = false;
                        break;
                    }
                }
                else
                {
                    if (((a >> k) & 1) > ((K >> k) & 1))
                    {
                        e = false;
                        break;
                    }
                }
            }
            if (e)
                m += S[j].second;
        }
        max = std::max(max, m);
    }
    cout << max << endl;
    return 0;
}