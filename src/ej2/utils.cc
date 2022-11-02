#include "utils.h"

bool Edge::greaterThan(
  const struct Edge& e,
  const struct Edge& f
) {
  return e.weight > f.weight;
}

void logMsg(const char msg[], ...) {
#ifdef DEBUG
  va_list args;
  va_start(args, msg);
  vprintf(msg, args);
  va_end(args);
#endif //DEBUG
}
