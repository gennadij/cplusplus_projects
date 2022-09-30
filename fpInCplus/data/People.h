#ifndef _PEOPLE_H
#define _PEOPLE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

//struct People;

struct People {
  string name;
  string gender;
  int age;
};

struct NotPeople {
  string name;
  string gender;
};

vector<People> initReople() {
  return vector<People> {
    People{"Marta", "female", 10}, 
    People{"Peter", "male", 20},
    People{"Sandra", "female", 30},
    People{"Lucy", "female", 40},
    People{"Mark", "male", 50},
    People{"Anton", "male", 60},
    People{"Luda", "female", 70},
    People{"Artiom", "male", 80},
    People{"Aljona", "female", 90}
    }; 
}

#endif