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
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;
    pll S, T;
    cin >> S.first >> S.second;
    cin >> T.first >> T.second;

    double a = (double)(B - A) / X;
    double sy = A + a * S.first;
    double ty = A + a * T.first;

    if ((sy > S.second && ty > T.second) || (sy < S.second && ty < T.second))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}