
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

ll lcm(ll a, ll b){
    ll gcd=__gcd(a,b);
    return ((a/gcd)*b);
}

ll mpow(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp % 2 == 1){
		res = (res * base) % mod;
	}
	exp >>= 1;
	base = (base * base) % mod;
	}
	return res;
	}
ll minv(ll base, ll mod) {
	return mpow(base, mod - 2,mod);
}

void rsa_cipher(ifstream& newf,ofstream& outi){
    string s;
    srand(time(NULL));
    
    while(getline(newf,s)){
        int n=sz(s);
        vector<int>prime(2);
        vector<int>totient;
        
        int curr=0;
        while(curr<2){
            int ran=rand() % 50 + 5;
            if(is_prime(ran)){
                prime[curr]=ran;
                curr++;
                if(curr==2 && prime[1]==prime[0]){
                    curr--;
                }
            }
        }
        ll num=prime[0]*prime[1];
        int lambda=lcm(prime[0]-1,prime[1]-1);

        curr=2;
        int e;
        while(curr<lambda){
            int gcd=__gcd(curr,lambda);
            if(gcd==1){
                totient.pb(curr);
            }
            curr++;
        }

        again:   // again calculating the value of e

        int ran=rand()%sz(totient);
        e=totient[ran];

        int d=minv(e,lambda);

        for(int i=0;i<n;i++){
            int msg=(int)(s[i]);
        
            ll encrypted=mpow(msg,e,num);

            ll rev_encrypted=minv(e,lambda);

            cout<<"Our Message is "<<msg<<endl;
            cout<<"Our Two Primes are "<<prime[0]<<" & "<<prime[1]<<endl;
            cout<<"Our Number is "<<num<<endl;
            cout<<"Our Totient Function ( Lambda )is "<<lambda<<endl;
            cout<<"Our Co-Prime ( e ) is "<<e<<endl;
            cout<<"Our Public Key is "<<num<<" & "<<e<<endl;
            cout<<"Our Private Key is "<<num<<" & "<<rev_encrypted<<endl;
            cout<<"Our Encrypted number is "<<encrypted<<endl;
            cout<<"Our Reverse Encrypted number is "<<rev_encrypted<<endl;
            cout<<endl;

            if(e==rev_encrypted){
                cout<<endl;
                cout<<"Here Our Reverse Encrypted Number Matches with Co-Prime ( e ) !!"<<endl;
                cout<<"So, We have to Continue Again !!"<<endl;
                i--;
                cout<<endl;
                goto again;
            }

            ll decrypted = mpow(encrypted,rev_encrypted,num);

            cout<<"Decrypted Text is "<<(char)decrypted<<" and in ASCII is "<<decrypted<<endl;
            cout<<endl;
            outi<<(char)decrypted<<endl;

        }
    }
}
