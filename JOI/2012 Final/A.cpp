#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N;
int A[100005];

int calc(int odd, int even)
{
    ll m = 0;
    int s = 0, e = -1;
    REP(i, N)
    {
        if (!(i % 2 == 0 && A[i] == even) &&
            !(i % 2 == 1 && A[i] == odd))
        {
            if (i == 0 || A[i] != A[i - 1])
            {
                e = i;
            }
            else
            {
                s = e + 1;
                e = i;
            }
        }
        m = std::max(m, i - s + 1);
    }
    return m;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    int m = 0;
    //! 偶数番目を1にする変換の最大値
    m = std::max(m, calc(0, 1));
    //! 偶数番目を0にする変換の最大値
    m = std::max(m, calc(1, 0));
    cout << m << endl;
    return 0;
}