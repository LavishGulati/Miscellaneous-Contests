#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double xl, yl, xw, yw, f;
    cin >> xl >> yl >> xw >> yw >> f;

    double si, ei, mid, alpha, beta;
    if(xw == xl) mid = xw;
    else if(xw > xl){
        si = xl;
        ei = xw;
        while(ei-si >= 0.0000001){
            mid = (si+ei)/2;
            alpha = (mid-xl);
            alpha /= sqrt((mid-xl)*(mid-xl)+(yl*yl));
            beta = (xw-mid);
            beta /= sqrt((xw-mid)*(xw-mid) + (yw*yw));
            if(alpha/beta == f) break;
            else if(alpha/beta < f) si = mid+0.0000001;
            else ei = mid-0.0000001;
        }
    }
    else{
        si = xw;
        ei = xl;
        while(ei-si >= 0.0000001){
            mid = (si+ei)/2;
            alpha = (xl-mid);
            alpha /= sqrt((mid-xl)*(mid-xl)+(yl*yl));
            beta = (mid-xw);
            beta /= sqrt((xw-mid)*(xw-mid) + (yw*yw));
            if(alpha/beta == f) break;
            else if(alpha/beta < f) ei = mid-0.0000001;
            else si = mid+0.0000001;
        }
    }
    printf("%.6lf\n", mid);
}
