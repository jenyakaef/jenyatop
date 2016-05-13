#include "disk.h"
#include <vector>

int menu();
int pokazat(std::vector<disk> &base);
int dobavit(std::vector<disk> &base);
int udalit(std::vector<disk> &base);
int naity(std::vector<disk> &base);
int change(std::vector<disk> &base);
int open_file(std::vector<disk> &base,char name[]);
int close_file(std::vector<disk> &base,char name[]);