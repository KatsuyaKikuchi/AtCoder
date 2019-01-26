#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll P[100005];
ll Q[100005];

int main()
{
    int W, H;
    cin >> W >> H;
    REP(i, W)
    {
        cin >> P[i];
    }
    REP(i, H)
    {
        cin >> Q[i];
    }
    sort(P, P + W);
    P[W] = INF;
    sort(Q, Q + H);
    Q[H] = INF;
    int pi = 0, qi = 0;
    ll sum = 0;
    ll w = W, h = H;
    while (pi < w || qi < h)
    {
        ll p = P[pi], q = Q[qi];
        if (p < q)
        {
            W--;
            pi++;
            sum += p * (H + 1);
        }
        else
        {
            H--;
            qi++;
            sum += q * (W + 1);
        }
    }
    cout << sum << endl;
    return 0;
}