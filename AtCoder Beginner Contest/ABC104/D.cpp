#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! i番目の左にあるA/?の数
ll LA[100005];
ll L[100005];
//! i番目の右にあるC/?の数
ll RC[100005];
ll R[100005];

//! 3-Q mod;
ll T[100005];

int main()
{
    string S;
    cin >> S;
    LA[0] = 0;
    L[0] = 0;
    REP(i, S.length())
    {
        LA[i + 1] = LA[i];
        L[i + 1] = L[i];
        if (S[i] == 'A')
            LA[i + 1]++;
        if (S[i] == '?')
            L[i + 1]++;
    }
    RC[S.length() - 1] = 0;
    R[S.length() - 1] = 0;
    for (int i = S.length() - 1; i >= 1; --i)
    {
        RC[i - 1] = RC[i];
        R[i - 1] = R[i];
        if (S[i] == 'C')
            RC[i - 1]++;
        if (S[i] == '?')
            R[i - 1]++;
    }

    T[0] = 1;
    REP(i, S.length())
    {
        T[i + 1] = (T[i] * 3) % MOD;
    }
    ll ans = 0;
    FOR(i, S.length() - 1, 1)
    {
        if (S[i] == 'B' || S[i] == '?')
        {
            //! ?以外を使う
            ll s0 = ((LA[i]*RC[i]%MOD)*T[L[i]+R[i]])%MOD;
            //! 左側の?を使う
            ll s1 =(L[i]*RC[i]%MOD)*T[std::max(0LL,L[i]+R[i]-1)]%MOD;
            //! 右側の?を使う
            ll s2 =(LA[i]*R[i]%MOD)*T[std::max(0LL,L[i]+R[i]-1)]%MOD;
            //! 左右?を使う
            ll s3 =(L[i]*R[i]%MOD)*T[std::max(0LL,L[i]+R[i]-2)]%MOD;

            ans = (ans + s0+s1+s2+s3) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}