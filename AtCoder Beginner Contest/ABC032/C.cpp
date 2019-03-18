#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    bool isZero = false;
    REP(i, N)
    {
        cin >> S[i];
        if (S[i] == 0)
            isZero = true;
    }

    ll max = 0;
    if (isZero)
    {
        max = N;
    }
    else if (K != 0)
    {
        ll M = 1;
        int left = 0;
        REP(i, N)
        {
            M *= S[i];
            if (M == 0)
            {
                max = N;
                break;
            }
            if (M <= K)
            {
                max = std::max(i - left + 1, max);
                continue;
            }
            while (M > K)
            {
                M /= S[left++];
            }
        }
    }
    cout << max << endl;
    return 0;
}