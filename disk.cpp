#include "disk.h"
#include <iostream>
#include <cstring>
disk::disk()
{
    int i;
    for(i=0;i<30;i++)
    maker[i]=color[i]=0;
    diametr=shirina=vylet=cost=0.0;
    type=0;
}
disk::disk(char make[],char colo[],float diamet,
float shirin,float vyle,float cos,int typ)
{
    strcpy(maker,make);
    strcpy(color,colo);
    diametr=diamet;
    shirina=shirin;
    vylet=vyle;
    cost=cos;
    type=typ;
}
int disk::show()
{
    std::cout<<"Производитель :"<<maker<<'\n';
    std::cout<<"Тип:";
    if(type==1) std::cout<<"Кованные\n";
    else
        if(type==2) std::cout<<"Литые\n";
            else
            if(type==3) std::cout<<"штампованые\n";
            else std::cout<<"Не указано\n";
    std::cout<<"Цвет:"<<color<<'\n';
    std::cout<<"Диаметр:"<<diametr<<'\n';
    std::cout<<"Ширина:"<<shirina<<'\n';
    std::cout<<"Вылет:"<<vylet<<'\n';
    std::cout<<"Цена:"<<cost<<'\n';
    return 1;
}
int disk::change_maker(char make[])
{
    strcpy(maker,make);    
    return 1;
}
int disk::change_color(char colo[])
{
    strcpy(color,colo);
    return 1;
}
int disk::change_diametr(float diamet)
{
    diametr=diamet;
    return 1;
}
int disk::change_shirina(float shirin)
{
    shirina=shirin;
    return 1;
}
int disk::change_vylet(float vyle)
{
    vylet=vyle;
    return 1;
}
int disk::change_cost(float cos)
{
    cost=cos;
    return 1;
}
int disk::change_type(int typ)
{
    type=typ;
    return 1;
}

int disk::know_maker(char*&make)
{
    strcpy(make,maker);    
    return 1;
}
int disk::know_color(char*&colo)
{
    strcpy(colo,color);
    return 1;
}
int disk::know_diametr(float &diamet)
{
    diamet=diametr;
    return 1;
}
int disk::know_shirina(float &shirin)
{
    shirin=shirina;
    return 1;

}
int disk::know_vylet(float &vyle)
{
    vyle=vylet;
    return 1;
}
int disk::know_cost(float &cos)
{
    cos=cost;
    return 1;
}
int disk::know_type(int &typ)
{
    typ=type;
    return 1;
}

int disk::srav_maker(char  make[])
{
    if(strstr(maker,make)!=NULL) return 1;    
    else return 0;
}
int disk::srav_color(char  colo[])
{
    if(strstr(colo,color)!=NULL) return 1;
    else return 0;
}
int disk::srav_diametr(float lit,float big)
{
    return ((lit<=diametr)&&(diametr>=big));
}
int disk::srav_shirina(float lit,float big)
{
    return ((lit<=shirina)&&(shirina>=big));
}
int disk::srav_vylet(float lit,float big)
{
    return ((lit<=vylet)&&(vylet>=big));
}
int disk::srav_cost(float lit,float big)
{
   return ((lit<=cost)&&(cost>=big));
}
int disk::srav_type(int  typ)
{
    return (type==typ);
}


std::istream &operator>>(std::istream & stream,disk &ob)
{
    stream>>ob.maker;
    stream>>ob.color;
    stream>>ob.diametr;
    stream>>ob.shirina;
    stream>>ob.vylet;
    stream>>ob.cost;
    stream>>ob.type;
    return stream; 
}
std::ostream &operator<<(std::ostream & stream,disk ob)
{
    stream<<ob.maker<<"\n"; 
    stream<<ob.color<<"\n";
    stream<<ob.diametr<<"\n"; 
    stream<<ob.shirina<<"\n"; 
    stream<<ob.vylet<<"\n"; 
    stream<<ob.cost<<"\n"; 
    stream<<ob.type<<"\n"; 
    stream<<ob.type;
    return stream;
}