#ifndef _CARS_H
#define _CARS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Cars {
  string name;
  string typ;
  int age;
};


vector<Cars> initCars() {
  return vector<Cars> {
    Cars{"BMW", "pkw", 10}, 
    Cars{"Audi", "pkw", 20},
    Cars{"Kamaz", "lkw", 30},
    Cars{"Lada", "pkw", 40},
    Cars{"Honda", "pkw", 50},
    Cars{"Merceres", "pkw", 60},
    Cars{"Mercedes", "lkw", 70},
    Cars{"vw", "pkw", 80},
    Cars{"Honda", "pkw", 90}
    }; 
}

#endif