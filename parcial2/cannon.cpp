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
void cannon::disparoOfen( float Yo, float Xd, float Yd, float RO,int Voo)
{
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = Yo + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((Xd - x),2)+pow((Yd- y),2)) < RO){
                    if(y<0) y = 0;
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

void cannon::disparoDef(float Yd, float Xo, float Yo, float RD, int Voo)
{
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = Yd + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((Xo - x),2)+pow((Yo - y),2)) < RD){
                    if(y<0) y = 0;

                    cout <<"impacto"<<'\n'<<"angulo: "<<angle<<" grados"<<'\n'
                    <<"velocidad: "<<V0o<<'\n'<<"posicion en x: "<<x<<'\n'<<
                    "posicion en y: "<<y<<'\n'<<"tiempo: "<<t<< " segundos"<<'\n'<<endl;

                    flag += 1;
                    V0o += 50;
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
