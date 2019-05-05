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
    ll H, W, N;
    cin >> H >> W >> N;
    pll s;
    cin >> s.first >> s.second;
    s.first--;
    s.second--;
    string S, T;
    cin >> S >> T;

    //! 高橋が左右から脱出できるか見る
    bool e = false;
    ll wr = s.second;
    ll wl = s.second;
    REP(i, N)
    {
        //! 高橋の手番
        if (S[i] == 'L')
            wl--;
        else if (S[i] == 'R')
            wr++;

        if (wr >= W || wl < 0)
            e = true;

        //! 青木の手番
        if (T[i] == 'L')
            wr = std::max(0LL, wr - 1);
        else if (T[i] == 'R')
            wl = std::min(W - 1, wl + 1);
    }

    //! 高橋が上下から脱出できるか
    ll hu = s.first;
    ll hd = s.first;
    REP(i, N)
    {
        //! 高橋の手番
        if (S[i] == 'U')
            hu--;
        else if (S[i] == 'D')
            hd++;

        if (hu < 0 || hd >= H)
            e = true;
        //! 青木の手番
        if (T[i] == 'U')
            hd = std::max(0LL, hd - 1);
        else if (T[i] == 'D')
            hu = std::min(H - 1, hu + 1);
    }

    if (e)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}