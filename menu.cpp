#include "menu.h"
#include <iostream> 
#include <vector>

using namespace std;

int menu()
{
    vector<disk> base;
    char name[20];
    cout<<"Укажете имя файла:";
    cin>>name;
    open_file(base,name);
    char vybor;
    while(1)
    {
        cout<<"____МЕНЮ____ \n";
        cout<<"1-- ПОКАЗАТЬ \n";
        cout<<"2-- ДОБАВИТЬ \n";
        cout<<"3-- УДАЛИТЬ  \n";
        cout<<"4-- НАЙТИ    \n";
        cout<<"5-- ИЗМЕНИТЬ \n";
        cout<<"0-- ВЫЙТИ    \n";
        cin>>vybor;
        if(vybor=='0') break;
        switch(vybor) 
        {
            case '1':pokazat(base);break;
            case '2':dobavit(base);break;
            case '3':udalit(base);break;
            case '4':naity(base);break;
            case '5':change(base);break;
            default :break;
        }
    }   
    close_file(base,name);
    return 1;
}
