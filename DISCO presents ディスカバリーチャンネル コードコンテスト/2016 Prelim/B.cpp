#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double L[100005];

int main()
{
    double R;
    ll N, M;
    cin >> R >> N >> M;
    FOR(i, N, 1)
    {
        double d = 2 * R / N;
        double h = 0;
        if (N % 2 == 0)
            h = abs(N / 2 - i) * d;
        else
            h = fabs((double)N / 2 - i) * d;

        L[i] = 2 * sqrt(R * R - h * h);
    }
    double sum = 0;
    FOR(i, N + M, 1)
    {
        int n = i;
        int m = i - M;
        double nl = 0, ml = 0;
        if (m >= 0)
            ml = L[m];
        if (n <= N)
            nl = L[n];

        sum += std::max(nl, ml);
    }
    cout << OF64 << sum << endl;
    return 0;
}