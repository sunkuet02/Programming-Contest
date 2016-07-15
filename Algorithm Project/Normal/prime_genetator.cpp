
/******************************PRIME GENERATOR***************************/


bool prime[MAX];
void seive()
{
    for(int i=2;i<=MAX;i++)
        prime[i]=true;
    for(int i=4;i<=MAX;i+=2) prime[i]=false;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }
}


/*******************************PRIME BITSET**************************/

bitset<20000010>bs;
vector<int> primes;
void seive(long upper)
{
    sieve_size = upper + 1;
    bs.set();
    bs[0]=0;
    bs[1]=0;
    for(long i=4;i<sieve_size;i+=2)
        bs[i]=0;
    for(int i=3;i<sqrt(sieve_size);i+=2)
        if(bs[i]==1)
            for(int j=i*i;j<sieve_size;j+=(2*i))
                bs[j]=0;
}

/****************************For finding primes********************/
vector<int> primes;
void seive()
{
    primes.push_back(2);
    for(int i = 3 ; i<MAX ; i+=2)
        prime[i] = true;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }
    for(int i=3 ; i< MAX ; i+=2)
        if(prime[i])
            primes.push_back(i);
}
