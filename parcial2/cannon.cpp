#include "cannon.h"

float cannon::getD() const
{
    return d;
}

void cannon::setD(float value)
{
    d = value;
}

float cannon::getXo() const
{
    return Xo;
}

void cannon::setXo(float value)
{
    Xo = value;
}

float cannon::getYo() const
{
    return Yo;
}

void cannon::setYo(float value)
{
    Yo = value;
}

float cannon::getRO() const
{
    return RO;
}

void cannon::setRO(float value)
{
    RO = value;
}

float cannon::getXd() const
{
    return Xd;
}

void cannon::setXd(float value)
{
    Xd = value;
}

float cannon::getYd() const
{
    return Yd;
}

void cannon::setYd(float value)
{
    Yd = value;
}

float cannon::getRD() const
{
    return RD;
}

void cannon::setRD(float value)
{
    RD = value;
}

cannon::cannon()
{

}



void cannon::disparoOfen(int Vi)
{
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int t = 0;
    int angle = 0;
    for(int V0o = Vi; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Xo+Vxo*t;
                y = Yo + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((Xd - x),2)+pow((Yd- y),2)) < RO){
                    if(y<0) y = 0;

                    cout <<"impacto"<<'\n'<<"angulo: "<<angle<<" grados"<<'\n'
                    <<"velocidad: "<<V0o<<'\n'<<"posicion en x: "<<x<<'\n'<<
                    "posicion en y: "<<y<<'\n'<<"tiempo: "<<t<< " segundos"<<'\n'<<endl;

                    flag += 1;
                    V0o += 25;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }

}

void cannon::disparoDef(int Vi)
{
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int t = 0;
    int angle = 0;
    for(int V0o = Vi; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((180-angle)*pi/180);
            Vy0 = V0o*sin((180-angle)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x =Xd + Vxo*t;
                y = Yd + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((Xo - x),2)+pow((Yo - y),2)) < RD){
                    if(y<0) y = 0;

                    cout <<"impacto"<<'\n'<<"angulo: "<<angle<<" grados"<<'\n'
                    <<"velocidad: "<<V0o<<'\n'<<"posicion en x: "<<x<<'\n'<<
                    "posicion en y: "<<y<<'\n'<<"tiempo: "<<t<< " segundos"<<'\n'<<endl;

                    flag += 1;
                    V0o += 25;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }

}

void cannon::protegerDef(int angleO,int VO){

    int flag = 0;
    bool flag2 = 0;
    float x,y,x2,y2;
    float aux,auy;
    float Vxo,Vy0, Vxoo,Vyoo;
    int t = 0;
    int angle = 0;
    Vxoo = VO*cos((angleO)*pi/180);
    Vyoo = VO*sin((angleO)*pi/180);
    for(int V0o = 1; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((180-angle)*pi/180);
            Vy0 = V0o*sin((180-angle)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Xo+ Vxoo*(t+2);
                y2 =Yo + Vyoo*(t+2) -(0.5*G*(t+2)*(t+2));
                x = Xd+Vxo*t;
                y = Yd + Vy0*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = Xd+Vxo*t2;
                    auy = Yd + Vy0*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((Xo - aux),2)+pow((Yo - auy),2)) < RD){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((Xd - x2),2)+pow((Yd - y2),2)) < RO){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < RD){
                    if(y<0) y = 0;


                    cout <<"impacto"<<'\n'<<"angulo: "<<angle<<" grados"<<'\n'
                    <<"velocidad: "<<V0o<<'\n'<<"posicion en x: "<<x<<'\n'<<
                    "posicion en y: "<<y<<'\n'<<"tiempo: "<<t<< " segundos"<<'\n'<<endl;

                    flag += 1;
                    V0o += 25;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }

}

void cannon::protegerDefandOfen( int angleO, int VO)
{
    int flag = 0;
    bool flag2 = 0;
    float x,y,x2,y2;
    float aux,auy;
    float Vxo,Vy0, Vxoo,Vyoo;
    int t = 0;
    int angle = 0;
    Vxoo = VO*cos((angleO)*pi/180);
    Vyoo = VO*sin((angleO)*pi/180);
    for(int V0o = 1; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((180-angle)*pi/180);
            Vy0 = V0o*sin((180-angle)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 =Xo + Vxoo*(t+2);
                y2 =Yo + Vyoo*(t+2) -(0.5*G*(t+2)*(t+2));
                x = Xd+Vxo*t;
                y = Yd + Vy0*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = Xd+Vxo*t2;
                    auy = Yd + Vy0*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((Xo - aux),2)+pow((Yo - auy),2)) < RD){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((Xd - x2),2)+pow((Yd - y2),2)) < RO){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < RD){
                    if(y<0) y = 0;

                    if (verificar_impactoOfen(angleO, VO)==false) {


                    cout <<"impacto"<<'\n'<<"angulo: "<<angle<<" grados"<<'\n'
                    <<"velocidad: "<<V0o<<'\n'<<"posicion en x: "<<x<<'\n'<<
                    "posicion en y: "<<y<<'\n'<<"tiempo: "<<t<< " segundos"<<'\n'<<endl;

                    flag += 1;
                    V0o += 25;
                    break;
                    }
                    else{
                        break;
                    }
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
}



bool cannon::verificar_impactoDef( int angleO,int VO)
{

    int flag = 0;
    float x=0.0,y=0.0;
    float Vxo,Vy0;
    int t = 0;
    Vxo = VO*cos(angleO*pi/180);
    Vy0 = VO*sin(angleO*pi/180);

    for(t = 0; ; t++){
        x = Xo +Vxo*t;
        y = Yo + Vy0*t -(0.5*G*t*t);
        if(sqrt(pow((Xd - x),2)+pow((Yd- y),2)) < RO){
            if(y<0) y = 0;
            flag += 1;
            break;
        }
        if(y < 0){
            break;
        }
        if(flag==1) break;

    }
    if (flag==1) {return true;}
     else{return false;}
}

bool cannon::verificar_impactoOfen(int angleO,int VO)
{
    int flag = 0;
    float x=0.0,y=0.0;
    float Vxo,Vy0;
    int t = 0;
    Vxo = VO*cos((180-angleO)*pi/180);
    Vy0 = VO*sin((180-angleO)*pi/180);

    for(t = 0; ; t++){
        x =Xd+Vxo*t;
        y = Yd + Vy0*t -(0.5*G*t*t);
        if(sqrt(pow((Xo - x),2)+pow((Yo- y),2)) < RD){
            if(y<0) y = 0;
            flag += 1;
            break;
        }
        if(y < 0){
            break;
        }
        if(flag==1) break;

    }
    if (flag==1) {return true;}
     else{return false;}

}





