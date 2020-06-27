#include <bits/stdc++.h>
using namespace std;
    
char decide( int num ){
    char c1, c2;
    char c3, c4;
    cout << num << endl;
    cin >> c1;
    if( c1 == 'E' ){
        return 'E';
    }
    cout << num << endl;
    cin >> c2;
    if( c1 == c2 ){
        if( c1 == 'L' )
            return 'L';
        else
            return 'G';
    }
    else{
        //cout << num << endl;
        //cin >> c3;
        // cout << num << endl;
        // cin >> c4;
        // if( c3 == c4 ){
        //     if( c3 == 'L' )
        //         return 'L';
        //     else
        //         return 'G';
        // }else 
        //if( c3 == c2 ){
        //    if( c3 == 'L' )
        //        return 'L';
        //    else
        //        return 'G'; 
       // }
    }
    return 'U';
}
int main(){
    int N;
    cin >> N;
    pair<int, int> p( 1, N );
    list< pair<int, int> > queue;
    int mid = ( p.first + p.second ) / 2;
    char decision = decide( mid );
    
    while( decision != 'E' ){

        if( decision == 'L') {
            p.second = mid - 1;
            if( p.first <= p.second ){
                queue.push_back( p );
                queue.remove_if( [ & ]( const pair<int, int>& val){ return val.first > mid; } );
            }
        }
        else if ( decision == 'G' && p.first < p.second){
            p.first = mid + 1;
            if( p.first <= p.second ){
                queue.push_back( p );
                queue.remove_if( [ & ]( const pair<int, int>& val){ return val.second < mid; } );
            }
        }
        else{ 
            if( p.first <= mid - 1 ){
                queue.push_back( pair<int, int>(p.first, mid - 1) );
            }
            if( mid + 1 <= p.second ){
                queue.push_back( pair<int, int>( mid + 1, p.second) );
            }

        }
        //for( auto i : queue ){
            //cout << i.first << "," << i.second << endl;
        //}
        p = queue.front();
        queue.pop_front();        
        mid = ( p.first + p.second ) / 2;
        decision = decide( mid );
    }
    return 0;
}


