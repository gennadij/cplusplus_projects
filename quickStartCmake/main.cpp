#include <iostream>
#include <algorithm>
#include <vector>
#include "chapter1/count_new_lines.cpp"

struct People {
    std::string gender;
    int age;
    std::string name; 
};

std::vector<People> testCopyIf(){
    People p1;
    People p2;
    People p3;

    p1.age = 18;
    p1.gender = "female";
    p1.name = "p1";

    p2.age = 20;
    p2.gender = "male";
    p2.name = "p2";

    p3.age = 22;
    p3.gender = "female";
    p3.name = "p3";

    std::vector<People> people;
    std::vector<People> people_copy;
    people.push_back(p1);
    people.push_back(p2);
    people.push_back(p3);

    auto  isFemale = [](const People& people) {
        return people.gender == "female";
    };

    std::copy_if(
        people.begin(), 
        people.end(), 
        std::back_inserter(people_copy), 
        isFemale
    );

    return people_copy;
}

int main(int, char**) {

    std::vector<People> p = testCopyIf();
    auto printPeople = [](const People& p){ std::cout << p.name << "\n"; };
    std::for_each(p.begin(), p.end(), printPeople);
    
}

