#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::sort;
using std::vector;

struct Bucket
{
  char letter;
  unsigned count;
};

bool compare_buckets(const Bucket &left, const Bucket &right)
{
  if(left.count > right.count)
  {
    return true;
  }
  if(right.count > left.count)
  {
    return false;
  }
  return left.letter < right.letter;
}

int main(int argc, char **argv) {
  // TODO: implement

  if (argc != 2) {
    cerr << "Usage: letter_freq <text file>" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);

  if(!ifile.is_open())
  {
    cerr << "failed to open file" << endl;
    return 1;
  }

  vector<Bucket> hist;
  for(int i = 0; i < 26; i++)
  {
    Bucket b;
    b.letter = 'a' + i;
    b.count = 0;
    hist.push_back(b);
  }

  char c;
  while(ifile.get(c))
  {
    if(isalpha(c))
    {
      c = tolower(c);
      hist[c - 'a'].count++;
    }
  }

  sort(hist.begin(), hist.end(), compare_buckets);

  for(vector<Bucket>::const_iterator it = hist.begin(); it < hist.end(); it++)
  {
    if((*it).count != 0)
    {
      cout << (*it).letter << ": " << (*it).count << endl;
    }
  }

  return 0;
}
