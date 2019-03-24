#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int D[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int ma, da;
    cin >> ma >> da;
    int mb, db;
    cin >> mb >> db;

    int sum = db - da;
    FOR(i, mb, ma)
    {
        sum += D[i];
    }
    cout << sum << endl;
    return 0;
}