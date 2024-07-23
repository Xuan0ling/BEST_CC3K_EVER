#include "Merchant.h"

Merchant::Merchant(Posn posn, Floor* floor) : Enemy('M', posn, 30, 70, 5, floor) {}

Merchant::~Merchant() {}

