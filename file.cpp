#include <cstring>
#include <iostream>
#include <fstream>
#include "menu.h"

int open_file(std::vector<disk> &base,char name[])
{
    std::ifstream fin(name);
    if(!fin) return 0;
    while(1)
        {
            if(fin.eof()==1) break;
            base.push_back(disk());
            fin>>base[base.size()-1];
        };
    fin.close();
    base.pop_back();
    return 1;
}

int close_file(std::vector<disk> &base,char name[])
{
    int i;
    std::ofstream fout(name);
    if(base.size()>0)
                {
                fout<<base[0];
                for(i=1;i<base.size();i++)
                fout<<"\n"<<base[i];
                }    
    fout.close();
}