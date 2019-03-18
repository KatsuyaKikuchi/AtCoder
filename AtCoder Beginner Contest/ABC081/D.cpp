#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[55];

int main()
{
    int N;
    cin >> N;
    ll max = 0, min = 0;
    REP(i, N)
    {
        cin >> A[i];
        if (A[max] < A[i])
            max = i;
        if (A[min] > A[i])
            min = i;
    }

    //! 一番大きい要素、または小さい要素を全体に足すと、全体はマイナスかプラスのどちらかになる
    if (abs(A[max]) > abs(A[min]))
    {
        cout << 2 * N - 1 << endl;
        cout << max + 1 << " " << max + 1 << endl;
        REP(i, N)
        {
            if (max == i)
                continue;
            cout << max + 1 << " " << i + 1 << endl;
        }
        //! 全部プラスになっている
        REP(i, N - 1)
        {
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    else
    {
        cout << 2 * N - 1 << endl;
        cout << min + 1 << " " << min + 1 << endl;
        REP(i, N)
        {
            if (min == i)
                continue;
            cout << min + 1 << " " << i + 1 << endl;
        }
        //! 全部マイナスになっている
        for (int i = N; i > 1; --i)
        {
            cout << i << " " << i - 1 << endl;
        }
    }
    return 0;
}