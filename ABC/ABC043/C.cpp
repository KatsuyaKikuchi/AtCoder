#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[105];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll min = INF;
    for (int i = -100; i <= 100; ++i)
    {
        ll s = 0;
        REP(j, N)
        {
            s += pow(abs(i - A[j]), 2);
        }
        min = std::min(min, s);
    }
    cout << min << endl;
    return 0;
}