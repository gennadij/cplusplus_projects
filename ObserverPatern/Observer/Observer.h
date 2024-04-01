#ifndef OBSERVER_H
#define OBSERVER_H

#include "../Subject/ISubject.h"
#include "IObserver.h"

class Observer : public IObserver {
public:
  Observer(ISubject &subject);
  ~Observer();
  void update(const std::string &) override;
  void remove();

private:
  std::string messageFromSubject_;
  ISubject &subject_;
  // static int number_;
};

#endif // OBSERVER_H
