#ifndef INPUT_H
#define INPUT_H

class Posn {
    int y;
    int x;
public:
    Posn(int y, int x);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    ~Posn();
};




#endif
