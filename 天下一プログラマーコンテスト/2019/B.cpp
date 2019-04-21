#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    REP(i, N)
    {
        if (S[i] == S[K - 1])
            continue;
        S[i] = '*';
    }
    cout << S << endl;
    return 0;
}