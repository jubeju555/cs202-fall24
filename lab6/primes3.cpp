// primes3
// Lab 6: Is it prime?
/*
judah benjamin 
geeks4geeks: how to use a map
how to use find in a map
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
// prime checking function 
bool isPrime(int n)
{
  int primecnt = 0;
  for (int i = 2; i * i <= n; i++)
  {
        // if number mod by iterated number is 0 it may be prime
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

// int main()
// {
//     map<int, bool> v;
//   int n;
//   int oldmax = 1;
//   while (cin >> n)
//   {
//     if (n > oldmax)
//     {
//       for (int i = oldmax + 1; i <= n; ++i)
//       {
//         if (isPrime(i))
//         {
//           v[i] = true;
//         }
//       }
//       oldmax = n;
//       cout << int (n / v.max_size()) << endl;

//     }

//     if (v.find(n) != v.end())
//     {
//       cout << "prime" << endl;
//     }
//     else
//     {
//       cout << "not prime" << endl;
//     }
//   }   


//   return 0;
// }

int main()
{
vector <int>  v;

int n;
  int oldmax = 1;
  while (cin >> n)
  {
    if (n > oldmax)
    {
      for (int i = oldmax + 1; i <= n; ++i)
      {
        if (isPrime(i))
        {
          v.push_back(i);
        }
      }
      oldmax = n;
      cout << (oldmax / v.size()) << endl;

    }
    
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

// int main()
// {
// vector <int>  v;
// int n;
//   int oldmax = 1;
//   while (cin >> n)
//   {
//     if (n > oldmax)
//     {
//       for (int i = oldmax + 1; i <= n; ++i)
//       {
//         if (isPrime(i))
//         {
//           v.push_back(i);
//         }
//       }
//       oldmax = n;
//     }
    
//     if (binary_search(v.begin(), v.end(), n))
//     {
//       cout << "prime" << endl;
//     }
//     else
//     {
//       cout << "not prime" << endl;
//     }
//   }
//   return 0;
// }