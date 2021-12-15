#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;

int main() {

  double sum_fp = 0.0;  // sum of floating point tokens
  int sum_i = 0;        // sum of integer tokens
  int ntok = 0;         // count of non-numeric tokens
  int ntok_c = 0;       // number of characters in non-numeric tokens

  string token;
  
  // TODO: implement statements to get input, determine and count the token types

  while(cin >> token)
  {
    std::stringstream ss1(token);
    std::stringstream ss2(token);

    int i;
    double d;
    string s;
    bool hasInt = false;;

    if(ss1 >> i)
    {
      if(!(ss1 >> s))
      {
        sum_i += i;
        hasInt = true;
      }
    }
    if(!hasInt)
    {
      if(ss2 >> d)
      {
        sum_fp += d;
      }
      else
      {
        ntok++;
        ntok_c += (int)token.size();
      }
    }
  }

  cout << "Floating point sum: " << sum_fp << endl;
  cout << "Integer sum: " << sum_i << endl;
  cout << "Number of non-numeric tokens: " << ntok << endl;
  cout << "Number of characters in non-numeric tokens: " << ntok_c << endl;

  return 0;
}
