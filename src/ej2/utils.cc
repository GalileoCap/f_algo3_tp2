#include "utils.h"

bool Edge::greaterThan(
  const struct Edge& e,
  const struct Edge& f
) {
  return e.weight > f.weight;
}
