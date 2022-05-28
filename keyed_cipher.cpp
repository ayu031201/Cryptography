string keyed_cipher_encoding(string s){
    bitset<30>flag(0);
    int n=sz(s);
    string ans="";
    for(int i=0;i<n;i++){
        if(isupper(s[i])){
            if(!flag[s[i]-65]){
                ans+=s[i];
                flag[s[i]-65]=1;
            }
        }
        else if(islower(s[i])){
            if(!flag[s[i]-97]){
                ans+=(s[i]-32);
                flag[s[i]-97]=1;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(!flag[i]){
            flag[i]=1;
            ans+=char(i+65);
        }
    }
    return ans;

}



void keyed_cipher(ifstream& newf, ofstream& outi){

    string key;  // key must be capital
    cin>>key;
    int k=key.size();
    string enco=keyed_cipher_encoding(key);
    
    string s;
    while(getline(newf,s)){
        int n=s.size();
        string ans(n,0);
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                ans[i]=enco[s[i]-97];
            }
            else if(isupper(s[i])){
                ans[i]=enco[s[i]-65];
            }
            else{
                ans[i]=s[i];
            }
        }
        outi<<ans<<endl;
    }
}
