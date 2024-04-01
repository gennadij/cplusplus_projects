#ifndef ISUBJECT_H
#define ISUBJECT_H

class IObserver;

class ISubject {
public:
  virtual ~ISubject(){};
  virtual void attach(IObserver *observer) = 0;
  virtual void detach(IObserver *observer) = 0;
  virtual void notify() = 0;
};

#endif // ISUBJECT_H
