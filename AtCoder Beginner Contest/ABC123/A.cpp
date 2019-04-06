#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[5];

int main()
{
    REP(i, 5)
    {
        cin >> A[i];
    }
    sort(A, A + 5);
    int k;
    cin >> k;
    if (A[4] - A[0] <= k)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
    return 0;
}