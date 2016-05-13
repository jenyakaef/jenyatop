all:disk.h disk.cpp main.cpp menu.h menu.cpp  menu_fun.cpp file.cpp
	g++ disk.cpp main.cpp menu.cpp file.cpp menu_fun.cpp -o kod