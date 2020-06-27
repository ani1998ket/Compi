// INCRDEC
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    vector< int > arr( N, 0 );
    for( auto& e : arr ){
        cin >> e;
    }
    sort( arr.begin(), arr.end() );
    vector<int> left, right;
    for( auto e : arr ){
       if( left.empty() || left.back() != e ){
            left.push_back( e );
       }else if( right.empty() || right.back() != e ){
            right.push_back( e );
       }else{
            cout << "NO" << endl;
            return;
       }
    }
    if( !right.empty() && left.back() == right.back() )
    {    
        cout << "NO" << endl;
        return;
    }
    
    sort( right.rbegin(), right.rend() );
    cout << "YES" << endl;
    for( auto e : left )
        cout << e << " ";
    for( auto e : right )
        cout << e << " ";

    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;

    while( T-- ){
        solve();
    }
    return 0;
}

