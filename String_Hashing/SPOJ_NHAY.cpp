/* 
 * Needle in the haystack
*/

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 256;
const long long  PRIME = 1e9 + 9;
long long g_pow_p_len;

//Polynomial rolling hash function
long long rHash( string inp ){
    int p = SIZE;
    int m = PRIME;
    long long pow_p = 1;
    long long hash = 0;
    for( auto i = inp.rbegin(); i != inp.rend(); ++i ){
        char c = *i - 'a' + 1;
        hash = ( hash + c * pow_p ) % m;
        if( hash < 0 ){
            hash += m;
            hash %= m;
        }
        g_pow_p_len = pow_p;
        pow_p = ( pow_p * p ) % m; 
        if( pow_p < 0 ){
            pow_p += m;
            pow_p %= m;
        }
    }
    return hash;
}
long long roll( long long hash, char a, char b ){
    long long result = (hash - (a-'a' + 1) * g_pow_p_len) % PRIME;
    if( result < 0 ){
        result += PRIME;
        result %= PRIME;
     }
    result = ( result * SIZE ) % PRIME;
    if( result < 0 ){
        result += PRIME;
        result %= PRIME;
     }
    result += b - 'a' + 1;
    return result % PRIME;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len;
    while( cin >> len ){
        cin.ignore();
        string needle;
        string haystack;
        getline( cin, needle );
        int nHash = rHash( needle );
        while( len-- ){
            char c;
            cin.get( c );
            if( c == '\n' )
                break;
            haystack.push_back( c ); 
        }
        if( haystack.length() < needle.length() ){
            cout << endl;
            continue;
        }
        
        int index = 0;
        int hHash = rHash( haystack );
        while( cin ){
            //Rabin Karp string matching
            if( hHash == nHash ){
                if( haystack == needle ){
                    cout << index << endl;
                }
            }
            char c;
            index++;
            cin.get(c);
            if( c == '\n' ){
                break;
            }
            hHash = roll( hHash, haystack[0], c );
            haystack.erase(0, 1);
            haystack.push_back(c);
        } 
        cout << "\n";
    }
    return 0;
}


