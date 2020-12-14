#include <iostream>
#include "cannon.h"
using namespace std;

int main()
{
    int angleO,VO,op,Vi,x;
    bool a=true;
    float Xo,Yo,Xd,Yd;

    cout << "Ingrese posicion en x cannon ofensivo: " << endl;
    cin >> Xo;
    cout << "Ingrese posicion en y cannon ofensivo:: " << endl;
    cin >> Yo;
    cout << "Ingrese posicion en x cannon defensivo: " << endl;
    cin >> Xd;
    cout << "Ingrese posicion en x cannon defensivo: " << endl;
    cin >> Yd;


    //balores de prueba

   /* float Xo = 0;
    float Yo = 100;
    float Xd = 800;
    float Yd = 20;

    disparo ofensivo 31 grados, 85 velocidad

*/

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
         // "5. para el proteccion del disparo ofensivo"<<'\n'<<
          "0. para salir"<<endl;

    cin>>op;

    switch (op) {
    case 0: a=false;

        break;

    case 1: cout << "Ingrese la velocidad inicia a probar: " << endl;
        cin >> Vi;
        bala.disparoOfen( Vi);

        break;

    case 2:cout << "Ingrese la velocidad inicia a probar: " << endl;
        cin >> Vi;
        bala.disparoDef(Vi);

        break;

    case 3: cout << "Ingrese el angulo inicial para proyectil ofensivo: " << endl;
        cin >> angleO;
        cout << "Ingrese la velocidad inicial para proyectil ofensivo: " << endl;
        cin >> VO;

         x=bala.verificar_impactoDef(angleO, VO);

        if (x==true) bala.protegerDef( angleO,VO );

        else {
            cout<<"el proyectil no impactara, intentelo de nuevo "<<endl;
        }
        break;

    case 4: cout << "Ingrese el angulo inicial para proyectil ofensivo: " << endl;
        cin >> angleO;
        cout << "Ingrese la velocidad inicial para proyectil ofensivo: " << endl;
        cin >> VO;

         x=bala.verificar_impactoDef(angleO, VO);

        if (x==true) bala.protegerDef(angleO,VO );

        else {
            cout<<"el proyectil no impactara, intentelo de nuevo "<<endl;
        }
        break;

    /*case 5:cout << "Ingrese el angulo inicial para proyectil ofensivo: " << endl;
        cin >> angleO;
        cout << "Ingrese la velocidad inicial para proyectil ofensivo: " << endl;
        cin >> VO;
        x=bala.verificar_impactoDef( angleO, VO);

       if (x==true) bala.defenderBullet( angleO, VO);

       else {
           cout<<"el proyectil no impactara, intentelo de nuevo "<<endl;
       }
        break;*/

   }
}
       
    return 0;
}
