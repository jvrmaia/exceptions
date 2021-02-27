// Factorize an integer N
//   factorize(60) returns => (2,2), (3,1), (5,1)
template<class T> inline vector<pair<T,int> > factorize(T n){
    vector<pair<T,int> > R;
    for(T i=2;n>1;){
        if(n%i==0){
            int C=0;
            for(;n%i==0;C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if(i>n/i) i=n;
    }
    if(n>1) R.push_back(make_pair(n,1));
    return R;
}
