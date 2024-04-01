#include "Subject.h"
#include "../Observer/IObserver.h"
#include "iostream"
Subject::Subject() {}

void Subject::attach(IObserver *observer) { listObserver_.push_back(observer); }

void Subject::detach(IObserver *observer) { listObserver_.remove(observer); }

void Subject::notify() {
  std::list<IObserver *>::iterator it = listObserver_.begin();
  std::cout << "There are " << listObserver_.size() << " observers active \n";
  while (it != listObserver_.end()) {
    (*it)->update(message_);
    ++it;
  }
}

void Subject::createMessage(std::string message) {
  message_ = message;
  notify();
}

void Subject::someBussinesLogic() {
  message_ = "bussines logic change the message \n";
  notify();
}
