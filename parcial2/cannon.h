#ifndef CANNON_H
#define CANNON_H
#define G 9.81
#define pi 3.1416

#include <math.h>
#include <iostream>
using namespace std;

class cannon
{

private:

    float d;

    float Xo;
    float Yo;
    float RO = 0.05*d;

    float Xd;
    float Yd;
    float RD = 0.025*d;


public:
    cannon();
    void disparoOfen( float , float , float , float,int );
    void disparoDef( float, float, float, float,int );
    void protegerDef(float,float,float,float ,int ,int );

    bool verificar_impacto(float, float, float, float,int,int);

    float getD() const;
    void setD(float value);

    float getXo() const;
    void setXo(float value);
    float getYo() const;
    void setYo(float value);
    float getRO() const;
    void setRO(float value);

    float getXd() const;
    void setXd(float value);
    float getYd() const;
    void setYd(float value);
    float getRD() const;
    void setRD(float value);
};

#endif // CANNON_H

