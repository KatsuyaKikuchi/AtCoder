#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll V[60];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> V[i];
    }

    ll max = 0;
    for (int n = 0; n <= std::min(N, K); ++n)
    {
        //! n個取る
        for (int l = 0; l <= n; ++l)
        {
            ll sum = 0;
            vector<ll> v;
            //! 左からl個、右からr個
            int r = n - l;
            REP(i, l)
            {
                sum += V[i];
                v.push_back(V[i]);
            }
            REP(i, r)
            {
                int index = N - 1 - i;
                sum += V[index];
                v.push_back(V[index]);
            }
            sort(v.begin(), v.end());
            REP(i, std::min(K - n, (ll)v.size()))
            {
                if (v[i] >= 0)
                    break;
                sum += abs(v[i]);
            }
            max = std::max(sum, max);
        }
    }
    cout << max << endl;
    return 0;
}