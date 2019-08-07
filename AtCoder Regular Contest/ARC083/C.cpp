#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! 水を100k g入れられるか？
bool W[50];
//! 砂糖をk g入れられるか？
bool S[1005];

int main()
{
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    memset(W, 0, sizeof(W));
    W[0] = true;
    REP(i, 31)
    {
        if (i - A >= 0 && W[i - A])
            W[i] = true;
        if (i - B >= 0 && W[i - B])
            W[i] = true;
    }
    memset(S, 0, sizeof(S));
    S[0] = true;
    REP(i, 1001)
    {
        if (i - C >= 0 && S[i - C])
            S[i] = true;
        if (i - D >= 0 && S[i - D])
            S[i] = true;
    }

    pll m = pll(100 * A, 0LL);
    for (int i = 0; i * 100 <= F; ++i)
    {
        if (!W[i])
            continue;
        for (int j = 0; j <= E * i; ++j)
        {
            if (!S[j])
                continue;
            if (100 * i + j > F)
                break;
            if (m.first * j > (i * 100 + j) * m.second)
            {
                m = pll(i * 100 + j, j);
            }
        }
    }
    cout << m.first << " " << m.second << endl;
    return 0;
}