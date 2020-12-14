#include <iostream>
#include "cannon.h"
using namespace std;

int main()
{
    int angleO,VO,op,Vi,x;
    bool a=true;

    float Xo = 0;
    float Yo = 100;     // poner variables ingresadas por el usuario
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

while(a==true){
    cout<<"1. para generar los disparos ofensivos,"<<'\n'<<
          "2. para los disparos defensivos,"<<'\n'<<
          "3. para el disparo ofensivo y la proteccion del defensivo"<<'\n'<<
          "4. para el disparo ofensivo y la proteccion del defensivo y ofensivo"<<'\n'<<
          "0. para salir"<<endl;

    cin>>op;

    switch (op) {
    case 0: a=false;

        break;

    case 1: cout << "Ingrese la velocidad inicia a probar: " << endl;
        cin >> Vi;
        bala.disparoOfen( bala.getYo(),  bala.getXd(),  bala.getYd(),  bala.getRO(),Vi);

        break;

    case 2:cout << "Ingrese la velocidad inicia a probar: " << endl;
        cin >> Vi;
        bala.disparoDef(bala.getYd(), bala.getXo(), bala.getYo(), bala.getRD(),Vi);

        break;

    case 3: cout << "Ingrese el angulo inicial para proyectil ofensivo: " << endl;
        cin >> angleO;
        cout << "Ingrese la velocidad inicial para proyectil ofensivo: " << endl;
        cin >> VO;

         x=bala.verificar_impactoDef(bala.getYo(),bala.getXd(),  bala.getYd(),  bala.getRO(), angleO, VO);

        if (x==true) bala.protegerDef( bala.getYo(), bala.getYd(),bala.getRD(), bala.getXd(),angleO,VO );

        else {
            cout<<"el proyectil no impactara, intentelo de nuevo "<<endl;
        }
        break;

    case 4: cout << "Ingrese el angulo inicial para proyectil ofensivo: " << endl;
        cin >> angleO;
        cout << "Ingrese la velocidad inicial para proyectil ofensivo: " << endl;
        cin >> VO;

         x=bala.verificar_impactoDef(bala.getYo(),bala.getXd(),  bala.getYd(),  bala.getRO(), angleO, VO);

        if (x==true) bala.protegerDef( bala.getYo(), bala.getYd(),bala.getRD(), bala.getXd(),angleO,VO );

        else {
            cout<<"el proyectil no impactara, intentelo de nuevo "<<endl;
        }
        break;

   }
}
       
    return 0;
}
