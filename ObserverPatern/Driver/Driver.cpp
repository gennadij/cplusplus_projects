#include "Driver.h"

#include <chrono>
// #include <functional>
#include <iostream>
#include <thread>

// very good thread
// https://stackoverflow.com/questions/21057676/need-to-call-a-function-at-periodic-time-intervals-in-c

Driver::Driver() {}

void Driver::requestData(int driverId) {
  // std::jthread jt{std::bind_front(&Driver::receivedData, this, driverId)};
  receivedData(driverId);
}

void Driver::receivedData(int driverId) {
  bool flag = true;
  int counter = 10;
  while (flag) {
    logic(driverId);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (counter <= 0) {
      flag = false;
    }
    counter--;
  }
}

void Driver::logic(int driverId) {
  std::cout << "The Driver <" << driverId << "> does her work!!" << std::endl;
}
