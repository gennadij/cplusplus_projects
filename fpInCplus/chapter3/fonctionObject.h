#include <iostream>
#include <vector>
#include <algorithm>
#include "../data/People.h"

using std::string;

class older_than{
  public:
    older_than(int limit) : m_limit(limit){}

    bool operator() (const People& p) const {
      return p.age > m_limit;
    }
  private:
    int m_limit;
};