#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[100005];

int main()
{
    ll N, C;
    cin >> N >> C;
    REP(i, N)
    {
        cin >> L[i];
    }
    sort(L, L + N);
    int fi = 0, li = N - 1;
    ll sum = 0;
    while (fi <= li)
    {
        if (L[fi] + L[li--] + 1 <= C)
            fi++;
        sum++;
    }
    cout << sum << endl;

    return 0;
}