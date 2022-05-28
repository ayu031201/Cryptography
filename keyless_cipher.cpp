void keyless_cipher(ifstream& newf, ofstream& outi){
    string s;
    while(getline(newf,s)){
        string ans;
        string up="",down="";
        int n=sz(s);
        bool flag=1;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                if(flag){
                    up+=s[i];
                    flag=0;
                }
                else{
                    flag=1;
                    down+=s[i];
                }
            }
            else{
                up+=s[i];
            }
        }
        ans=up+down;
        outi<<ans<<endl;
    }
}