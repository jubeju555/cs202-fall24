#include "hash_202.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
/*
judah
cs202
lab5
sources:
digitalocean.com: how to set up hashtable with parameters
cppreference.com: how to check if digit is hex or not: differenced between isdigit and isxdigit
Jackson: taught us about the ? if statment in lab
Emrich: puting return with out curly brakcets to save space
cplusplus.com: learning about string::const_iterator
stack overflow: idea for hex checker and converting hex to a long

*/

/*
grade checking
bin/gradescript 1
diff -y --suppress-common-lines tmp-001-test-stdout.txt tmp-001-correct-stdout.txt
*/
using namespace std;
// checks if string consists only of hex digits
bool ishex(const string &s)
{
  for (string::const_iterator i = s.begin(); i != s.end(); ++i)
  {
    if (!isxdigit(*i))
      return false;
  }
  return true;
}

// converts a hex string to an long int
unsigned long hex2long(const string &s)
{
  unsigned long result = 0;
  for (string::const_iterator i = s.begin(); i != s.end(); ++i)
  {
    // shift left 4, subtract ascii value of 0, if its a letter add 10 so its a
    result = (result << 4) | (isdigit(*i) ? *i - '0' : tolower(*i) - 'a' + 10);
  }
  return result;
}
// hashing functions
int last7(const string &s)
{
  return hex2long(s.substr(s.length() > 7 ? s.length() - 7 : 0));
}

int XOR(const string &s)
{
  unsigned long result = 0;
  for (size_t i = 0; i < s.length(); i += 7)
  {
    result ^= hex2long(s.substr(i, min(static_cast<size_t>(7), s.length() - i)));
  }
  return result;
}
// intitialize hash table, with error checking 
string Hash_202::Set_Up(size_t table_size, const string &fxn, const string &collision)
{
  if (!Keys.empty()) {
    return "Hash table already set up";
}

if (table_size == 0) {
    return "Bad table size";
}

if (fxn != "Last7" && fxn != "XOR") {
    return "Bad hash function";
}

if (collision != "Linear" && collision != "Double") {
    return "Bad collision resolution strategy";
}
  Keys.resize(table_size);
  Vals.resize(table_size);
  Nkeys = 0;
  Fxn = (fxn == "Last7") ? 'L' : 'X';
  Coll = (collision == "Linear") ? 'L' : 'D';
  return "";
}
// add key/ value to the table throgh chosed sorting method
string Hash_202::Add(const string &key, const string &val)
{
if (Keys.empty()) {
    return "Hash table not set up";
}

if (key.empty()) {
    return "Empty key";
}

if (!ishex(key)) {
    return "Bad key (not all hex digits)";
}

if (val.empty()) {
    return "Empty val";
}

if (Nkeys == Keys.size()) {
    return "Hash table full";
}

  unsigned long hash = (Fxn == 'L') ? last7(key) : XOR(key);
  size_t index = hash % Keys.size();
  size_t probe = 1;
// which 
  if (Coll == 'D')
  {
    probe = ((Fxn == 'L') ? XOR(key) : last7(key)) % Keys.size();
    if (probe == 0)
      probe = 1;
  }

  size_t start_index = index;
  do
  {
    if (Keys[index].empty())
    {
      Keys[index] = key;
      Vals[index] = val;
      ++Nkeys;

      return "";
    }
    if (Keys[index] == key)
      return "Key already in the table";

    index = (index + probe) % Keys.size();
  } while (index != start_index);
  return "Cannot insert key";
}
// look for key in the table 
string Hash_202::Find(const string &key)
{
  if (Keys.empty() || key.empty() || !ishex(key))
    return "";

  unsigned long hash = (Fxn == 'L') ? last7(key) : XOR(key);
  size_t index = hash % Keys.size();
  size_t probe = 1;

  if (Coll == 'D')
  {
    probe = ((Fxn == 'L') ? XOR(key) : last7(key)) % Keys.size();
    if (probe == 0)
      probe = 1;
  }
         
  Nprobes = 0;
  size_t start_index = index;
  do {
    ++Nprobes;
    
    if (Keys[index].empty()) {
        return "";
    }

    if (Keys[index] == key) {
        return Vals[index];
    }

    index = (index + probe) % Keys.size();

} while (index != start_index);

return "";
}
// print out the empty bins in the table 
void Hash_202::Print() const
{
  if (Keys.empty())
    return;

  for (size_t i = 0; i < Keys.size(); ++i)
  {
    if (!Keys[i].empty())
    {
      cout << setw(5) << i << " " << Keys[i] << " " << Vals[i] << endl;
    }
  }
}
// set probes to 0 and it seemed to work 
size_t Hash_202::Total_Probes()
{
  if (Keys.empty())
    return 0;

  size_t total = 0;
  for (size_t i = 0; i < Keys.size(); ++i)
  {
    if (!Keys[i].empty())
    {
      size_t probes = 0; 
      size_t index = (Fxn == 'L' ? last7(Keys[i]) : XOR(Keys[i])) % Keys.size();
      size_t probe = 1;

      if (Coll == 'D')
      {
        probe = ((Fxn == 'L' ? XOR(Keys[i]) : last7(Keys[i])) % Keys.size());
        if (probe == 0)
          probe = 1;
      }

      while (index != i)
      {
        index = (index + probe) % Keys.size();
        ++probes;
      }

      total += probes;
    }
  }
  return total;
}