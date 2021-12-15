#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>

using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;

// this helper function is complete
bool is_vowel(char c) {
  const string VOWELS = "aeiou";
  return VOWELS.find(tolower(c)) != string::npos;
}

// TODO: finish writing this helper function to create and return
// the abbreviated version of the word parameter
string abbreviate(string word) {
  string result;
  bool last_was_vowel = false;

  for (size_t i = 0; i < word.size(); i++) {
    bool cur_is_vowel = is_vowel(word[i]);

    // TODO: finish coding this loop to complete the function
    if(cur_is_vowel)
    {
      if(!last_was_vowel)
      {
        result += '\'';
      }
      last_was_vowel = true;
    }
    else
    {
      result += word[i];
      last_was_vowel = false;
    }
  }

  return result;
}


int main(int argc, char **argv) {

  if (argc != 3) {
    cerr << "Usage: abbrev <infile> <outfile>" << endl;
    return 1;
  }

  // TODO: implement the primary functionality here
  ifstream ifile(argv[1]);
  ofstream ofile(argv[2]);
  if(!ifile.is_open())
  {
    cerr << "Couldn't open input file" << endl;
    return 1;
  }

  std::string line;
  while(getline(ifile, line))
  {
    stringstream ss(line);
    std::string word;
    while(ss >> word)
    {
      ofile << abbreviate(word) << ' ';
    }
    ofile << endl;
  }

  return 0;
}
