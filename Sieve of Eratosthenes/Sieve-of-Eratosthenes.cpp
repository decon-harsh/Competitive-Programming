// Sieve of Eratosthenes - Nishant Giri

#include<iostream>
using namespace std;
const long long SIZE = 1000001;
vector<long long>isPrime(SIZE, true);
vector<long long>SPF(SIZE);
vector<long long>prime;
void manipulatedSeive(int num)
{
    long long int i, j;
    isPrime[0] = isPrime[1] = false ;
    for(i = 2; i < num ; i++)
    {
        if(isPrime[i])
        {
            prime.pushBack(i);
            SPF[i] = i;
        }
        for(j = 0; (j < (int)prime.size()) && (i * prime[j] < N) && (prime[j] <= SPF[i]); j++)
        {
            isPrime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
}
int main()
{
    int i, num;
    cout<<"Enter Any Number: ";
    cin>>num;
    manipulatedSeive(num);
    cout<<"\nPrime Number Less Than "<<num<<":\n\n";
    for(i = 0; (i < prime.size()) && (prime[i] <= num); i++)
        cout<<prime[i]<<" ";
    cout<<"\n";
    return 0;
}