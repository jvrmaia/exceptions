int r[50010];
int mm[50010][18]; // or n and log(n) +1

void construct() {
    int i,j,b;
    for(i=0;i<n;i++) mm[i][0]=r[i];
    for(i=1;i<18;i++)
    {
        for(j=0; (j+(1<<i)-1)<n; j+=(1<<i))
            mm[j][i]=max(mm[j][i-1], mm[j+(1<<(i-1))][i-1]);
    }
}

int getmax(int a, int b) {
    if(a>b) return -1;
    for(int i=17; i>=0; i--)
    {
        if((a%(1<<i))==0 && (a+(1<<i)-1)<=b)
            return max(mm[a][i], getmax(a+(1<<i), b));
    }
}

