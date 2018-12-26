//!*******************************************************************
//! MEMO
//! コードめっちゃ汚い
//!*******************************************************************
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int H, W;
ll Max = 0, Min = INF;
ll A[2005][2005];
bool B[2005][2005];

void clear()
{
    REP(h, H)
    {
        REP(w, W)
        {
            B[h][w] = false;
        }
    }
}

bool check(ll m)
{
    ll min = INF, max = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            if (B[h][w])
                continue;
            min = std::min(min, A[h][w]);
            max = std::max(max, A[h][w]);
        }
    }
    // if (m == 18)
    // {
    //     REP(h, H)
    //     {
    //         REP(w, W)
    //         {
    //             if (B[h][w])
    //                 cout << "J";
    //             else
    //                 cout << "O";
    //         }
    //         cout << endl;
    //     }
    //         cout << endl;
    // }
    if (max - min <= m)
    {
        return true;
    }
    return false;
}

//! 標高差m以内の分割が可能か
bool isPossible(ll m)
{
    ll mn = std::max(Max - m, (ll)0), mx = Max;
    //! 左上がmaxの標高を含むと仮定
    {
        clear();
        ll mw = W;
        REP(h, H)
        {
            REP(w, mw)
            {
                if (A[h][w] >= mn && A[h][w] <= mx)
                {
                    B[h][w] = true;
                    continue;
                }
                mw = w;
                break;
            }
        }
        if (check(m))
            return true;
    }
    {
        clear();
        ll mw = W;
        for (ll h = H - 1; h >= 0; --h)
        {
            REP(w, mw)
            {
                if (A[h][w] >= mn && A[h][w] <= mx)
                {
                    B[h][w] = true;
                    continue;
                }
                mw = w;
                break;
            }
        }
        if (check(m))
            return true;
    }
    {
        clear();
        ll mh = H;
        for (int w = W - 1; w >= 0; --w)
        {
            REP(h, mh)
            {
                if (A[h][w] >= mn && A[h][w] <= mx)
                {
                    B[h][w] = true;
                    continue;
                }
                mh = h;
                break;
            }
        }
        if (check(m))
            return true;
    }
    {
        clear();
        ll mh = -1;
        for (int w = W - 1; w >= 0; --w)
        {
            for (ll h = H - 1; h > mh; --h)
            {
                if (A[h][w] >= mn && A[h][w] <= mx)
                {
                    B[h][w] = true;
                    continue;
                }
                mh = h;
                break;
            }
        }
        if (check(m))
            return true;
    }
    return false;
}

int main()
{
    cin >> H >> W;
    REP(h, H)
    {
        REP(w, W)
        {
            cin >> A[h][w];
            Max = std::max(Max, A[h][w]);
            Min = std::min(Min, A[h][w]);
        }
    }

    ll ok = Max - Min, ng = -1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (isPossible(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}