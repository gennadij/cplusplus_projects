#include <iostream>
#include <vector>
#include <algorithm>
#include "../data/People.h"

using std::string;

template <typename T>
class older_than{
  public:
    older_than(int limit) : m_limit(limit){}

    bool operator() (const T& o) const {
      return o.age > m_limit;
    }
  private:
    int m_limit;
};