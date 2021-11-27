#include "../include/Vertex.h"

ostream& operator<<(ostream& out, const Vertex& v) {
  out << v.key();
  return out;
}