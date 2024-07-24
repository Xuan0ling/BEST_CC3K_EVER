#ifndef INPUT_H
#define INPUT_H
#include <iostream>

class Posn {
public:
    int y;
    int x;
    Posn(int y = 0, int x = 0);

    Posn operator+(const Posn &other);
    Posn operator+=(const Posn &other);
    Posn operator-(const Posn &other);
    Posn operator-=(const Posn &other);
    bool operator==(const Posn &other) const;
    bool operator!=(const Posn &other) const;
    
    ~Posn();
};

std::ostream &operator<<(std::ostream &out, const Posn &posn);



#endif
