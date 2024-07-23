#include "Elf.h"

Elf::Elf(Posn posn, Floor* floor) : Enemy('E', posn, 140, 30, 10, floor) {}

Elf::~Elf() {}
