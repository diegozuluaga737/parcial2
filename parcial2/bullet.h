#ifndef BULLET_H
#define BULLET_H


class bullet
{
public:
    bullet();
    ~bullet();

    float d=800; //distancia entre cañones
    float Xb;
    float Yb;
    float RO = 0.05*d;
    float RD = 0.025*d;

};

#endif // BULLET_H
