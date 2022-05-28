void affine_cipher(ifstream& newf, ofstream& outi){
    int a,b;
    cin>>a>>b;

    string s;
    while(getline(newf,s)){
        int n=sz(s);
        string ans;
        for(char x:s){
            char z;
            if(islower(x)){
                z=char((int((x-97) * a + b ) % 26) + 97);
            }
            else if(isupper(x)){
                z=char((int((x-65) * a + b ) % 26) + 65);
            }
            else{
                z=x;
            }
            ans.pb(z);
        }
        outi<<ans<<endl;
    }
}
