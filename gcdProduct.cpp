#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;

bool isprime[15000001];
// array declaration
int factor[15000000];

const long MOD = pow(10, 9) + 7;

long long solve(long long a, long long b, long long n){
    long long c = 1, d = a;
    while (b){
        if (b& 1) {
           c = (c*d) % n;
        }
        d = (d*d) % n;
        b >>= 1;
    }
    return c;
}

int main(){
    int n, m;
    cin >> n >> m;
    // 1 is true
    memset(&isprime, true, sizeof(isprime));
    // 0 is false 
    isprime[0]  = false;
    isprime[1] = false;
    int count = 0, i = 2;
    while( i <= min(n, m)){
        if (isprime[i]){
            for (int j = 2*i; j <= min(n, m); j += i) {
                isprime[j] = false; // 0 is false
            }
            factor[count++] = i;
        }
        i++;
    }

    long long ans = 1;

    for (int i = 0; i < count; i++){
        long long tmp = 0, now = factor[i];
        while (n / now && m / now){
            tmp += (n / now) * (m / now);
            now *= factor[i];
        }
        ans = (ans * solve(factor[i], tmp, MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}

