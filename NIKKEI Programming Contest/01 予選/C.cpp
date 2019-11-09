#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];
pll C[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i] >> B[i];
        C[i] = pll(A[i], B[i]);
    }
    sort(C, C + N, [](pll a, pll b) { return a.first + a.second > b.first + b.second; });

    ll t = 0, a = 0;
    REP(i, N)
    {
        if (i % 2 == 0)
            t += C[i].first;
        else
            a += C[i].second;
    }
    cout << t - a << endl;
    return 0;
}