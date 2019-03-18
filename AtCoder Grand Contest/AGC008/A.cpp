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
    ll x, y;
    cin >> x >> y;
    ll s = abs(abs(x) - abs(y));
    //! 反転ボタンを押す数を決める
    if (y < x && (x < 0 || y > 0))
        s += 2;
    else if (y < x && 0 <= x)
        s++;
    else if (x < y && y > 0 && x < 0)
        s++;
    cout << s << endl;
    return 0;
}