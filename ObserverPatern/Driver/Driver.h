#ifndef DRIVER_H
#define DRIVER_H

#include "IDriver.h"

class Driver : public IDriver {
public:
  Driver();

  void requestData(int) override;

private:
  void logic(int);
  void receivedData(int);
};

#endif // DRIVER_H
