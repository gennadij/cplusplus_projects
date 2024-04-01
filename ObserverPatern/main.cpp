#include "Driver/Driver.h"
#include "Observer/Observer.h"
#include "Subject/Subject.h"
#include <thread>

void Client() {
  Subject *subject = new Subject;
  Observer *observer = new Observer(*subject);
  subject->createMessage("Hallo Observer");
  subject->someBussinesLogic();

  delete subject;
  delete observer;
}

int main() {
  Client();
  Driver d1{};
  Driver d2{};
  // d1.requestData(1);
  std::jthread jt1(&Driver::requestData, &d1, 1);
  // d2.requestData(2);
  std::jthread jt2(&Driver::requestData, &d2, 2);

  jt1.join();
  jt2.join();
  return 0;
}
