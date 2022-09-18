#include <iostream>
#include <vector>
#include <algorithm>

using std:string;

struct People {
  std::string name;
  std::string gender;
};


class older_than{
  public:
    older_than(int limit) : m_limit(limit){}

    bool operator() ()const {
      return true;
    }
  private:
    int m_limit;
};