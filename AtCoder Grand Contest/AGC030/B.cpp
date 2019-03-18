#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[200005];
//! 反時計回りにiまで進んだあと交互に燃やす移動距離
ll dpL[200005];
//! 時計回りにiまで進んだあと交互にもやす移動距離
ll dpR[200005];

int main()
{
    ll L, N;
    cin >> L >> N;
    REP(i, N)
    {
        cin >> X[i];
    }

    {
        ll s0 = 0;
        ll s1 = 0;
        dpL[N - 1] = 0;
        ll t = N - 1;
        for (int i = N - 2; i >= 0; --i)
        {
            s0 += L - X[N - 1 - (N - 2 - i) / 2];
            s1 += X[i] + X[i + 1] - X[t];
            dpL[i] = s0 + s1;
            if ((N - 1 - i) % 2 == 1)
                t--;
        }
    }
    {
        ll s0 = 0;
        ll s1 = 0;
        dpR[0] = 0;
        ll t = 0;
        FOR(i, N, 1)
        {
            s0 += X[(i - 1) / 2];
            s1 += (L - X[i]) + (L - X[i - 1]) - (L - X[t]);
            dpR[i] = s0 + s1;
            if (i % 2 == 1)
                t++;
        }
    }
    ll max = 0;
    //! 反時計回りにiまで進み、そこから交互に燃やしていく
    REP(i, N)
    {
        ll m = X[i] + dpL[i];
        //! X[N-1]->X[i+1]->X[N-2]->...
        max = std::max(m, max);
    }
    //! 時計回りにiまで進み、そこから交互に燃やす
    for (int i = N - 1; i >= 0; --i)
    {
        ll m = L - X[i] + dpR[i];
        //! X[0]->X[i-1]->X[1]->...
        max = std::max(m, max);
    }
    cout << max << endl;
    return 0;
}