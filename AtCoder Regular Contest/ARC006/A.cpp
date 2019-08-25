#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool A[10];
bool C[10];

int main()
{
    memset(A, 0, sizeof(A));
    memset(C, 0, sizeof(C));
    REP(i, 6)
    {
        ll a;
        cin >> a;
        A[a] = true;
    }
    ll B;
    cin >> B;
    REP(i, 6)
    {
        ll c;
        cin >> c;
        C[c] = true;
    }
    ll sum = 0;
    REP(i, 10)
    {
        if (A[i] && C[i])
            sum++;
    }

    if (sum == 6)
        cout << 1 << endl;
    else if (sum == 5 && C[B])
        cout << 2 << endl;
    else if (sum == 5)
        cout << 3 << endl;
    else if (sum == 4)
        cout << 4 << endl;
    else if (sum == 3)
        cout << 5 << endl;
    else
        cout << 0 << endl;
    return 0;
}