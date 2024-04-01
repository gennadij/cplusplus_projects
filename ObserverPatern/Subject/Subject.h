#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.h"
#include <list>
#include <string>

class Subject : public ISubject {
public:
  Subject();
  void attach(IObserver *observer) override;
  void detach(IObserver *observer) override;
  void notify() override;
  void createMessage(std::string message);
  void someBussinesLogic();

private:
  std::list<IObserver *> listObserver_;
  std::string message_;
};

#endif // SUBJECT_H
