#ifndef IDRIVER_H
#define IDRIVER_H

class IDriver {
public:
  virtual ~IDriver() {}
  virtual void requestData(int) = 0;
};
#endif // IDRIVER_H
