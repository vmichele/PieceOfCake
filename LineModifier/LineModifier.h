#ifndef LINEMODIFIER_H
#define LINEMODIFIER_H

#include "Polygon.h"

#include <string>

class LineModifier {
public:
  LineModifier(void);
  virtual ~LineModifier(void);

  virtual std::string getName(void) const = 0;
};

#endif // LINEMODIFIER_H
