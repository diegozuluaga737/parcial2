#ifndef CANNON_H
#define CANNON_H




class cannon
{
private:

    float Do = 800;
    float Xof = 0;
    float Yof = 100;


    float d = 800;
    float Xd = 800;
    float Yd = 20;


public:
    cannon();
    ~cannon();

    void disparoDef();
    void disparoOfen();
    void protegerDef();
    void protegerDefyOfen();
    void defenderBullet();
};

#endif // CANNON_H
