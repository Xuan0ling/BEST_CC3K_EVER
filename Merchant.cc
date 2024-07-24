#include "Merchant.h"


Merchant::Merchant(Floor* floor, Posn posn) : Enemy(floor, 'M', posn, 30, 70, 5) {}

Merchant::~Merchant() {}

