#include "elf.h"

Elf::Elf(Floor* floor, Posn posn) : Enemy(floor, 'E', posn, 140, 30, 10) {}

Elf::~Elf() {}
