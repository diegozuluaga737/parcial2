#include <iostream>
#include "cannon.h"
#include <cannon.h>
using namespace std;

int main()
{
    int Voo,angleO,VO;

    cout << "Ingrese la velocidad inicial desde la cual quiere probar: " << endl;
    cin >> Voo;
    cout << "Ingrese el angulo inicia para proteger el canon : " << endl;
    cin >> angleO;
    cout << "Ingrese la velocidad inicial para proteger el canon: " << endl;
    cin >> VO;


    float Xo = 0;
    float Yo = 100;
    float Xd = 800;
    float Yd = 20;

    float d = Xd-Xo;

    float RO = 0.05*d;
    float RD = 0.025*d;


        cannon bala;

        bala.setD(d);
        bala.setXo(Xo);
        bala.setYo(Yo);
        bala.setRO(RO);
        bala.setXd(Xd);
        bala.setYd(Yd);
        bala.setRD(RD);

        bala.disparoOfen( bala.getYo(),  bala.getXd(),  bala.getYd(),  bala.getRO(), Voo);
        bala.disparoDef(bala.getYd(), bala.getXo(), bala.getYo(), bala.getRD(), Voo);

    return 0;
}
