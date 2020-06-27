// CHFMOT18
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int S, N;
    cin >> S >> N;
    int coins = 0;
    if( S & 1 ){
        coins++;
        --S;
    }
    
    while( S > 0 ){
        coins += S / N;
        S = S % N;
        if( S > N )
            N -= 2;
        else
            N = S;
        
    }
    
    cout << coins << endl;
    
    
}
int main(){
    int T;
    cin >> T;
    while( T-- ){
        solve();
        
    }
    return 0;
}

