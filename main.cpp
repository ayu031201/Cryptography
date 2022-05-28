#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define sz(s)  s.size()
#define pb push_back
using ll= long long;

int main(){

    ifstream newf;
    ofstream outi;
    ifstream outo;

    newf.open("input.txt");
    outi.open("output.txt");

    // shift_cipher(newf,outi);

    // keyed_cipher(newf,outi);  // key must be CAPITAL

    // affine_cipher(newf,outi);

    // keyless_cipher(newf,outi);

    // rsa_cipher(newf,outi);   // change newf.open("input2.txt");

    string s;
    outo.open("output.txt");
    while(getline(outo,s)){
        cout<<s<<endl;
    }
    
    return  0;
}