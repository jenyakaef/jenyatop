#include <iostream>
class disk
{
    char maker[30];
    char color[30];
    float diametr;
    float shirina;    
    float vylet;
    float cost;
    int type;
    public:
    disk();
    disk(char make[],char colo[],float diamet,
    float shirin,float vyle,float cos,int typ);
    int show();
//++++++++++++++++++++++++++++++++++++++++++
    int change_maker(char make[]);
    int change_color(char colo[]);
    int change_diametr(float diamet);
    int change_shirina(float shirina);
    int change_vylet(float vyle);
    int change_cost(float cos);
    int change_type(int typ);
//?????????????????????????????????????????
    int know_maker(char*&make);
    int know_color(char*&colo);
    int know_diametr(float &diamet);
    int know_shirina(float &shirin);
    int know_vylet(float &vyle);
    int know_cost(float &cos);
    int know_type(int &typ);
//============================================
    int srav_maker(char make[]);
    int srav_color(char colo[]);
    int srav_diametr(float lit,float big);
    int srav_shirina(float lit,float big);
    int srav_vylet(float lit,float big);
    int srav_cost(float lit,float big);
    int srav_type(int typ);

      friend std::ostream& operator<<(std::ostream &stream,disk ob);
      friend std::istream& operator>>(std::istream &stream,disk&ob);
};