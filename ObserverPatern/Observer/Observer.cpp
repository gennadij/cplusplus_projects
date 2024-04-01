#include "Observer.h"
#include <iostream>

Observer::Observer(ISubject &subject) : subject_(subject) {
  subject_.attach(this);
}

Observer::~Observer() {}

void Observer::update(const std::string &messageFromObserver) {
  messageFromSubject_ = messageFromObserver;
  std::cout << "Observer a new message is available --> " << messageFromSubject_
            << "\n";
}

void Observer::remove() { subject_.detach(this); }
