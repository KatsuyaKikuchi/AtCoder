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
    ll A, B, C;
    cin >> A >> B >> C;
    ll ta = A, tb = B, tc = C;
    int n = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
    {
        ll a = A / 2, b = B / 2, c = C / 2;
        A = b + c;
        B = a + c;
        C = a + b;
        n++;
        if (A == ta && B == tb && C == tc)
        {
            n = -1;
            break;
        }
    }
    cout << n << endl;
    return 0;
}