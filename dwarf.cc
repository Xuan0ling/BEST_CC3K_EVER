#include "dwarf.h"

Dwarf::Dwarf(Floor* floor, Posn posn) 
: Enemy(floor, 'W', posn, 100, 20, 30) {}

Dwarf::~Dwarf() {}

