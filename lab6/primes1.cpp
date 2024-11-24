// Lab 6: Is it prime?
/*
judah benjamin
geeks4geeks: literal defintion of a prime number to help with planning how to calculate a prime number 
*/
#include <iostream>
#include <cstdlib>
using namespace std;
// prime checking function 
bool isPrime(int n)
{
  int primecnt = 0;
  int numprint;
  for (int i = 1; i <= n; i++)
  {
    // if number mod by iterated number is 0 it may be prime
    if (n % i == 0)
    {
      primecnt++;
    }
  }
  // if more then 2 then its not prime, if not it is. 
  if (!(primecnt > 2))
  {
    cout << n << ", ";
    
    numprint++;
  }
  if (numprint >= 20)
  {
    cout << endl;
    numprint = 0;
  }
  
}

int main(int argc, char *argv[])
{
  int n;  
  cin >> n;
  // iterate through list 
  for (int i = 2; i < n; i++)
  {
    isPrime(i);
  }
  return 0;
}
