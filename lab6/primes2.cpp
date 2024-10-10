// Lab 6: Is it prime?
/*
judah benjamin
lab6
sources: 
geeks4geeks: how to use find()
google: definition of prime number: for calulations
stack: how to declare vector
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
// prime checking function 
bool isPrime(int n)
{
      // if number mod by iterated number is 0 it may be prime
  int primecnt = 0;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      primecnt++;
      return false;
    }
  }
    // if more then 2 then its not prime, if not it is. 
  if (primecnt > 2)
  {
    return false;
  }
  return true;
};

int main()
{
  vector<int> v;
  int n;
  int oldmax = 1;
  //read in numbers 
  while (cin >> n)
  {
    if (n > oldmax)
    {
      // iterate through list of numbers
      for (int i = oldmax + 1; i <= n; ++i)
      {
        if (isPrime(i))
        {
          v.push_back(i);
        }
      }
      oldmax = n;
    }
    // find function, fron beigning to end and stop at end
    if (find(v.begin(), v.end(), n) != v.end())
    {
      cout << "prime" << endl;
    }
    else
    {
      cout << "not prime" << endl;
    }
  }
  return 0;
  
}
