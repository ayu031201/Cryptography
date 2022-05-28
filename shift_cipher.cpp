void shift_cipher(ifstream& newf, ofstream& outi){

    int key;
    cin>>key;

    string s;
    if(newf.is_open()){
        string s;
        while(getline(newf,s)){
            for(char x:s){
                if(islower(x)){
                    char c=( ( int ( x + key - 97 ) % 26) + 97);
                    outi<<c;
                }
                else if(isupper(x)){
                    char c=( ( int ( x + key - 65 ) % 26) + 65);
                    outi<<c;
                }
                else{
                    outi<<x;
                }
            }
            outi<<endl;
        }
    }
    else{
        cout<<"Can't open this File!! ";
        return ;
    }
}
