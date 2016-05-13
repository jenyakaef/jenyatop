#include <iostream>
#include <cstring>
//#include <vector>
#include "menu.h"

int pokazat(std::vector<disk> &base)
{
    int i;
    for(i=0;i<base.size();i++)
    {
        std::cout<<"Диск №"<<i<<'\n';
        base[i].show();
    }
    return 1;
};
int dobavit(std::vector<disk> &base)
{
    char maker[30],color[30];
    float diametr=0,shirina=0,vylet=0,cost =0;
    int type,i;
    for(i=0;i<30;i++)
    maker[i]=color[i]=0;
    while(1)
    {
        if(strlen(maker)<5)
            {
            std::cout<<"Производитель:";
            std::cin>>maker;
            continue;
            }
        if(strlen(color)<5)
            {
            std::cout<<"Цвет:";
            std::cin>>color;
            continue;
            }
        if(diametr<=0)
            {
            std::cout<<"Диаметр:";
            std::cin>>diametr;
            continue;
            }
        if(shirina<=0)
            {
            std::cout<<"Ширина";
            std::cin>>shirina;
            continue;
            }
        if(vylet<=0)
            {
            std::cout<<"Вылет:";
            std::cin>>vylet;
            continue;
            }
        if(cost<=0)
            {
            std::cout<<"Цена:";
            std::cin>>cost;
            continue;
            }
        if((type<1)||(type>3))
            {
            std::cout<<"Укажите тип:\n1-кованные\n2-литые\n3-штампованые\n";
            std::cin>>type;
            continue;
            }
        break;
    }
    base.push_back(disk(maker,color,diametr,shirina,vylet,cost,type));
    return 1;
};
int udalit(std::vector<disk> &base)
{
    std::cout<<"Введите индекс удаляемого элемента\n";
    int i;
    std::cin>>i;
    if(i<0) return 0;
    if(i>=base.size()) return 0;
    base.erase(base.begin()+i);
    return 1;
};
int naity(std::vector<disk> &base)
{
    char maker[30],color[30];
    float diametr_lit=0,diametr_big=0,shirina_lit=0,
            shirina_big=0,vylet_lit=0,
            vylet_big=0,cost_lit =0,cost_big=0;
    int type,i;
    char flag_atrib[7];
    for(i=0;i<7;i++)  flag_atrib[i]=0;
     for(i=0;i<30;i++)
    maker[i]=color[i]=0;

    std::cout<<"Укажите атрибуты по которым будет происходить поиск (Y(yes) или N(not))"<<std::endl;
    for(i=0;i<7;i++)
    {
        if(i==0)std::cout<<"Производитель"<<std::endl;
        if(i==1)std::cout<<"Цвет"<<std::endl;
        if(i==2)std::cout<<"Диаметр"<<std::endl;
        if(i==3)std::cout<<"Ширина"<<std::endl;
        if(i==4)std::cout<<"Вылет"<<std::endl;
        if(i==5)std::cout<<"Цена"<<std::endl;
        if(i==6)std::cout<<"Тип"<<std::endl;
        std::cin>>flag_atrib[i];
        if(flag_atrib[i]=='y'||flag_atrib[i]=='Y') continue;
        else if(flag_atrib[i]=='n'||flag_atrib[i]=='N') continue;
                else
                {
                flag_atrib[i]=0;
                i--;
                }
    }
    std::cout<<flag_atrib<<std::endl;

    for(i=0;i<7;i++)
        {
        if(flag_atrib[i]=='y'||flag_atrib[i]=='Y') flag_atrib[i]=1;
                else flag_atrib[i]=0;
        }
        
    std::cout<<flag_atrib<<std::endl;
    std::cout<<"Введите данные"<<std::endl;   
    while(1)
    {
        if(flag_atrib[0])
            if(strlen(maker)<5)
            {
            std::cout<<"Производитель:";
            std::cin>>maker;
            continue;
            }
        
        if(flag_atrib[1])
        if(strlen(color)<5)
            {
            std::cout<<"Цвет:";
            std::cin>>color;
            continue;
            }
        
        if(flag_atrib[2])
        if(diametr_lit<=0||diametr_big<diametr_big)
            {
            std::cout<<"Диаметр(нижний):";
            std::cin>>diametr_lit;
            std::cout<<"Диаметр(верхиний):";
            std::cin>>diametr_big;
            continue;
            }
        
        if(flag_atrib[3])
        if(shirina_lit<=0||shirina_big<shirina_lit)
            {
            std::cout<<"Ширина(нижняя)";
            std::cin>>shirina_lit;
            std::cout<<"Ширина(верхняя)";
            std::cin>>shirina_big;
            continue;
            }
        
        if(flag_atrib[4])
        if(vylet_lit<=0||vylet_big<vylet_big)
            {
            std::cout<<"Вылет(нижний):";
            std::cin>>vylet_lit;
            std::cout<<"Вылет(верхний):";
            std::cin>>vylet_big;
            continue;
            }
        
        if(flag_atrib[5])
        if(cost_lit<=0||cost_big<cost_lit)
            {
            std::cout<<"Цена(нижняя):";
            std::cin>>cost_lit;
            std::cout<<"Цена(верхняя):";
            std::cin>>cost_big;
            continue;
            }
        
        if(flag_atrib[6])
        if((type<1)||(type>3))
            {
            std::cout<<"Укажите тип:\n1-кованные\n2-литые\n3-штампованые\n";
            std::cin>>type;
            continue;
            }
        break;
    }
    for(i=0;i<base.size();i++)
    {
        if(!(flag_atrib[0])||(base[i].srav_maker(maker)))
        if(!(flag_atrib[1])||(base[i].srav_color(color)))
        if(!(flag_atrib[2])||(base[i].srav_diametr(diametr_lit,diametr_big)))
        if(!(flag_atrib[3])||(base[i].srav_shirina(shirina_lit,shirina_big)))
        if(!(flag_atrib[4])||(base[i].srav_vylet(vylet_lit,vylet_big)))
        if(!(flag_atrib[5])||(base[i].srav_cost(cost_lit,cost_big)))
        if(!(flag_atrib[6])||(base[i].srav_type(type)))
        {
        std::cout<<"Диск №"<<i<<'\n';
        base[i].show();
        }
    }
    return 1;
};

int change(std::vector<disk> &base)
{
    int index;
    std::cout<<"Укажите номер изменяемого элемента";
    std::cin>>index;
    if(index<0||index>=base.size())
        {
        std::cout<<"Элемент не найден";
        return 0;
        }
        
        std::cout<<"Изменить .."<<std::endl;
        std::cout<<"1--Производитель"<<std::endl;
        std::cout<<"2--Цвет"<<std::endl;
        std::cout<<"3--Диаметр"<<std::endl;
        std::cout<<"4--Ширина"<<std::endl;
        std::cout<<"5--Вылет"<<std::endl;
        std::cout<<"6--Цена"<<std::endl;
        std::cout<<"7--Тип"<<std::endl;
    char vybor;
    std::cin>>vybor;

    char stroka[30];
    float chislo=0;
    int type,i;
    for(i=0;i<30;i++)
    stroka[i]=0;
    while(1)
    {
        if(vybor=='1'||vybor=='2')
        if(strlen(stroka)<5)
            {
            if(vybor=='1')std::cout<<"Производитель:";
            if(vybor=='2')std::cout<<"Цвет:";
            std::cin>>stroka;
            continue;
            }
        if(vybor>'2'&&vybor<7)
        if(chislo<=0)
            {
            if(vybor=='3')std::cout<<"Диаметр:";
            if(vybor=='4')std::cout<<"Ширина";
            if(vybor=='5')std::cout<<"Вылет:";
            if(vybor=='6')std::cout<<"Цена:";
            std::cin>>chislo;
            continue;
            }
        if(vybor=='7')
        if((type<1)||(type>3))
            {
            std::cout<<"Укажите тип:\n1-кованные\n2-литые\n3-штампованые\n";
            std::cin>>type;
            continue;
            }
        break;
    }
    if(vybor=='1') base[index].change_maker(stroka);
    if(vybor=='2') base[index].change_color(stroka);
    if(vybor=='3') base[index].change_diametr(chislo);
    if(vybor=='4') base[index].change_shirina(chislo);
    if(vybor=='5') base[index].change_vylet(chislo);
    if(vybor=='6') base[index].change_cost(chislo);
    if(vybor=='7') base[index].change_type(type);
    return 1; 
}