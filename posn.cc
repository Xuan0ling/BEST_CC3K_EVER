#include "posn.h"


Posn::Posn(int y, int x) : y{y}, x{x} {}

Posn Posn::operator+(const Posn &other) {
    return Posn{y + other.y, x + other.x};
}

Posn Posn::operator+=(const Posn &other) {
    y += other.y;
    x += other.x;
    return *this;
}

Posn::~Posn() {}


std::ostream &operator<<(std::ostream &out, const Posn &posn) {
    out << "(" << posn.y << ", " << posn.x << ")";
    return out;
}
