#include <stdlib.h>
#include <stdio.h>
#include "babax.h"
int main(int argc, char **argv)
{
  struct disk *qwe;
  int n=10; // Переменная выбора пункта меню
  int k=0; // Количество элементов в базе
  qwe = NULL;


  // Проверка того, что в командной строке был задан файл:
  if (argc!=2)
  {
    printf ("Ошибка! Задайте файл в коммандной строке\n");
    return 0;
  }
  printf ("\n\nРаботаем с файлом %s\n", argv[1]);
  
  while (n!=0)
  {
    printf ("\n\nМеню:\n 1. Загрузить данные из файла\n 2. Добавить товар в базу\n 3. Редактирование\n 4. Удалить элемент из базы\n 5. Поиск\n 6. Сортировка\n 7. Вывод базы на экран\n 0. Выход\n\n\nВыберите нужный пункт меню: ");
    scanf ("%d", &n);
    switch (n)
    {
      case 1:
        qwe = Zagruzka (argv, qwe, &k);
      break;
      case 2:
        Dobavlenie (argv);
      break;
      case 3:
        Redaktirovanie (argv, qwe, k);
      break;
      case 4:
        Udalenie (argv, qwe, k);
      break;
      case 5:
        Poisk (qwe, k);
      break;
      case 6:
        sortirovka (argv, qwe, k);
      break;
      case 7:
        if (qwe!=NULL) Vivod (qwe, k);
        else printf ("База не считана из файла!\n");
      break;
      case 0:
        printf ("Окончание работы программы\n\n");
      break;
      default:
        printf ("Такого пункта в меню нет\n");
    };
  }
  // Освобождаем память:
  if (qwe!=NULL) free(qwe);
  return 0;
}
