#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[205];

int main()
{
    int H, W;
    cin >> H >> W;
    ll A, B;
    cin >> A >> B;
    REP(i, H)
    {
        cin >> M[i];
    }

    ll an = 0, bn = 0, cn = 0;
    ll n = 0;
    REP(h, H / 2)
    {
        REP(w, W / 2)
        {
            int s = 0;
            if (M[h][w] == 'S')
                s++;
            if (M[h][W - w - 1] == 'S')
                s++;
            if (M[H - h - 1][w] == 'S')
                s++;
            if (M[H - h - 1][W - w - 1] == 'S')
                s++;

            if (s == 2)
            {
                if (M[h][w] == M[H - h - 1][w])
                    an++;
                else if (M[h][w] == M[h][W - w - 1])
                    bn++;
                else
                    n++;
            }
            if (s == 3)
            {
                an++;
                bn++;
            }
            if (s == 4)
            {
                cn++;
            }
            n += s % 2;
        }
    }

    ll sum = A + B;
    //! 東西/南北に対称な石の点数を追加
    n += std::min(A * an, B * bn);
    if (n == 0)
    {
        n += std::max(an, bn);
        an = std::max(0LL, an - 1);
        bn = std::max(0LL, bn - 1);
    }
    sum += std::max(A * an, B * bn);

    //! 東西南北に対象な石の点数を追加
    sum += cn * (A + B + std::max(A, B));
    if (n == 0)
        sum -= A + B;

    cout << sum << endl;
    return 0;
}