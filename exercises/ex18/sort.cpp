#include <iostream>
#include <cassert>
#include <vector>

void sort( std::vector< int > *values );

int main( void )
{
  std::vector< int > vec;
  size_t count;

  std::cout << "Enter the count: ";

  // PART 2 TO DO: read in the count of random numbers from the standard input.

  std::cin >> count;
  
  // PART 3 TO DO: Make the "vec" vector store "count" random values

  vec.resize(count);

  for(size_t i = 0; i < count; i++)
  {
    vec[i] = rand();
  }

  sort(&vec);

  for(size_t i = 1; i < vec.size(); i++)
  {
      assert(vec[i-1] <= vec[i]);
  }

  return 0;
}

void sort( std::vector< int > *values )
{
  // PART 5 TO DO: Define the sort function
  if(values->size() > 1)
  {
    int mid = values->size() / 2;
    std::vector<int> left(mid);
    std::vector<int> right(values->size() - mid);
    for(size_t i = 0; i < mid; i++)
    {
      left[i] = (*values)[i];
    }
    for(size_t i = mid; i < values->size(); i++)
    {
      right[i - mid] = (*values)[i];
    }

    sort(&left);
    sort(&right);

    size_t i = 0, j = 0, k = 0;
    while(i < left.size() || j < right.size())
    {
      if(left.size() <= i)
      {
        (*values)[k++] = right[j++];
      }
      else if(right.size() <= j)
      {
        (*values)[k++] = left[i++];
      }
      else if(left[i] < right[j])
      {
        (*values)[k++] = left[i++];
      }
      else
      {
        (*values)[k++] = right[j++];
      }
    }
  }
}

