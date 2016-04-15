#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "babax.h"

struct disk
{
  char name[40]; // Имя производителя
  char tip[30]; // Размер диска
  float price; // Цена диска
  int number; // Номер товара на в базе
  char razmer[11]; // Pазмер диска
};


struct disk * Zagruzka (char **argv, struct disk *qwe, int *res)
{
  FILE *f;
  char s[111];
  int i;
  int m; // Количество элементов в базе
  m=0; 

  f = fopen (argv[1], "r");
  if(f == NULL)
  {
    printf("Ошибка открытия файла: %s",argv[1]);
    return NULL;
  }
  // Сначала подсчитаем количество элементов в базе:
  while (fgets (s, 111, f))
  {
    m++;
  }
  fclose (f);
  // Считывание базы:
  printf ("Считывание базы из файла:\n\n");
  f = fopen (argv[1], "r");
  if (m!=0)
  {
    qwe = (struct disk*)malloc(sizeof(struct disk)*m);
    for (i=0; i<m; i++)
    {
      fscanf (f, "%s%s%f%d%s", qwe[i].name, qwe[i].tip, &qwe[i].price, &qwe[i].number, qwe[i].razmer);
    }
  }
  else printf ("Элементов в базе нет!\n");
  fclose (f);
  *res = m;
  if (qwe!=NULL) printf ("База успешно считана из файла!\n");
  else printf ("База не считана из файла!\n");
  return qwe;
}

void Vivod (struct disk *qwe, int k)
{
  int i;
  printf ("Вывод текущей базы:\n\n");
  if (qwe!=NULL)
    for (i=0; i<k; i++)
      printf ("%d. %s   %s   %6.2f   %d   %s\n", i+1, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
  else printf ("Сначала нужно считать базу из файла!\n");
}

int Dobavlenie (char **argv)
{
  FILE *f;
  struct disk new;

  f = fopen (argv[1], "a");
  if(f == NULL)
  {
    printf("Ошибка открытия файла: %s",argv[1]);
    return 1;
  }
  printf ("Добавление элемента:\n\nВведите название производителя: ");
  scanf ("%s", new.name);
  printf ("Введите серию диска: ");
  scanf ("%s", new.tip);
  printf ("Введите цену товара: ");
  scanf ("%f", &new.price);
  printf ("Введите номер товара в базе: ");
  scanf ("%d", &new.number);
  printf ("Введите размер диска: ");
  scanf ("%s", new.razmer);
  printf ("\nДобавленный товар:\n%s   %s   %5.2f   %d   %s\n\n", new.name, new.tip, new.price, new.number, new.razmer);
  fprintf (f, "%s  ", new.name);
  fprintf (f, "%s  ", new.tip);
  fprintf (f, "%5.2f  ", new.price);
  fprintf (f, "%d  ", new.number);
  fprintf (f, "%s  ", new.razmer);
  fprintf (f, "\n");
  fclose (f);
}

int Zapis (char **argv, struct disk *qwe, int k)
{
  int i;
  FILE *f;
  f = fopen (argv[1], "w");
  if(f == NULL)
  {
    printf("Ошибка открытия файла: %s",argv[1]);
    return 1;
  }
  if (qwe!=NULL)
  {
    for (i=0; i<k; i++)
    {
      fprintf (f, "%s  ", qwe[i].name);
      fprintf (f, "%s  ", qwe[i].tip);
      fprintf (f, "%5.2f  ", qwe[i].price);
      fprintf (f, "%d  ", qwe[i].number);
      fprintf (f, "%s  ", qwe[i].razmer);
      fprintf (f, "\n");
    }
  }
  else printf ("База не задана!\n");
  fclose (f);
  return 0;
}

void Udalenie (char **argv, struct disk *qwe, int k)
{
  int del, i;
  printf ("Удаление элемента базы:\n\nВведите номер элемента базы, который Вы хотите удалить: ");
  scanf ("%d", &del);
  if (qwe!=NULL)
  {
    for (i=(del-1); i<(k-1); i++)
    {
       qwe[i]=qwe[i+1];
	
    } 
    k--;
    printf ("Элемент №%d успешно удален из базы!\n", del);
    Zapis (argv, qwe, k);

  }
  else printf ("Сначала нужно считать базу!\n");
}

void Redaktirovanie (char **argv, struct disk *qwe, int k)
{
  int red, m=10;
  printf ("Редактирование элемента базы:\n\nВведите номер элемента базы, который Вы хотите редактировать: ");
  scanf ("%d", &red);
  red--;
  if (qwe!=NULL)
  {
    printf ("Вы хотите редактировать следующий элемент:\n%d. %s %s %6.2f %d %s", (red+1), qwe[red].name, qwe[red].tip, qwe[red].price, qwe[red].number, qwe[red].razmer);
    printf ("\n\nЧто Вы хотите изменить:\n\n1. Название производителя\n2. Серия диска\n3. Цена\n4. Номер в базе\n5. Размер диска\n0. Ничего\n\n");
    while (m!=0)
    {
      printf ("Выберите пункт, который Вы хотите редактировать: ");
      scanf ("%d", &m);
      switch (m)
      {
        case 1:
          printf ("Введите новое название производителя: ");
          scanf ("%s", qwe[red].name);
        break;
        case 2:
          printf ("Введите новую серию диска: ");
          scanf ("%s", qwe[red].tip);
        break;
        case 3:
          printf ("Введите новую цену: ");
          scanf ("%f", &qwe[red].price);
        break;
        case 4:
          printf ("Введите новый номер в базе: ");
          scanf ("%d", &qwe[red].number);
        break;
        case 5:
          printf ("Введите новый размер диска: ");
          scanf ("%s", qwe[red].razmer);
        break;
        case 0:
          printf ("\nКонец редактирования\n");
        break;
        default:
          printf ("Такого пункта нет\n");
      };
    }
    printf ("Элемент №%d успешно редактирован!\n", (red+1));
    Zapis (argv, qwe, k);
  }
  else printf ("Сначала нужно считать базу!\n");
}

void Poisk (struct disk *qwe, int k)
{
  int m=10; // Переменная выбора меню
  char s[40]; // Вспомогательная строка
  int p=0; // Считалка
  float f; // Вспомогательное дробное число
  int d; // Вспомогательное целое число
  int i;
  if (qwe!=NULL)
  {
    printf ("Поиск:\n\nВ каком каталоге вы хотите искать?\n\n1. Название производителя\n2. Серию диска\n3. Цена\n4. Номер в базе\n5. Размер диска\n0. Выход\n\n");
    printf ("Выберите нужный каталог: ");
    scanf ("%d", &m);
    switch (m)
    {
      case 1:
        printf ("Введите название производителя, которое Вы хотите найти: ");
        scanf ("%s", s);
        for (i=0; i<k; i++)
        {
          if (strcmp (qwe[i].name, s) == 0)
          {
            p++;
            printf ("\n%d. %s %s %6.2f %d %s\n", p, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
          }
        }
        if (p==0) printf ("Элемент не найден\n");
      break;
      case 2:
        printf ("Введите серию диска, которого Вы хотите найти: ");
        scanf ("%s", s);
        for (i=0; i<k; i++)
        {
          if (strcmp (qwe[i].tip, s) == 0)
          {
            p++;
            printf ("\n%d. %s %s %6.2f %d %s\n", p, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
          }
        }
        if (p==0) printf ("Элемент не найден\n");
      break;
      case 3:
        printf ("Введите цену товара, которую Вы хотите найти: ");
        scanf ("%f", &f);
        for (i=0; i<k; i++)
        {
          if (qwe[i].price == f)
          {
            p++;
            printf ("\n%d. %s %s %6.2f %d %s\n", p, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
          }
        }
        if (p==0) printf ("Элемент не найден\n");
      break;
      case 4:
        printf ("Введите номер в базе, который Вы хотите найти: ");
        scanf ("%d", &d);
        for (i=0; i<k; i++)
        {
          if (qwe[i].number == d)
          {
            p++;
            printf ("\n%d. %s %s %6.2f %d %s\n", p, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
          }
        }
        if (p==0) printf ("Элемент не найден\n");
      break;
      case 5:
        printf ("Введите размер, который Вы хотите найти:  ");
        
            scanf ("%s", s);
            for (i=0; i<k; i++)
            {
              if (strcmp (qwe[i].razmer, s) == 0)
              {
                p++;
                printf ("\n%d. %s %s %6.2f %d %s\n", p, qwe[i].name, qwe[i].tip, qwe[i].price, qwe[i].number, qwe[i].razmer);
              }
            }
            if (p==0) printf ("Элемент не найден\n");
          break;
      case 0:
        printf ("Выход из поиска\n");
      break;
      default:
        printf ("Такого пункта в меню нет\n");
    };
  }
  else printf ("База не считана!\n");
}

void sortirovka (char **argv, struct disk *qwe, int k)
{
  int m, v; // Переменные выбора меню
  struct disk prost; // Вспомогательная структура для перемены мест элементов базы
  int i, j; 
  if (qwe!=NULL)
  {
    printf ("Сортировка базы:\n\nПо какому полю Вы хотите сортировать базу?\n1. Название производителя\n2. Серия диска\n3. Цена\n4. Номер в базе\n5. Размер\n0. Выход\n\nВыберите нужное поле: ");
    scanf ("%d", &m);
    switch (m)
    {
      case 1:
        printf ("Нажмите 1, чтобы осортировать в алфавитном порядке\nНажмите 2, чтобы осортировать в обратном алфавитном порядке\n");
        scanf ("%d", &v);
        if (v == 1)
        {
          for (i=0; i<k-1; i++)
            for (j=i+1; j<k; j++)
            {
              if (strcmp((qwe[i].name), (qwe[j].name))>0)
              {
                prost = qwe[i];
                qwe[i] = qwe[j];
                qwe[j] = prost;
              }
            }
            printf ("База успешно отсортирована в алфавитном порядке по названию производителя!\n");
          }
          else
          {
            if (v == 2)
            {
              for (i=0; i<k-1; i++)
                for (j=i+1; j<k; j++)
                {
                  if (strcmp((qwe[i].name), (qwe[j].name))<0)
                  {
                    prost = qwe[i];
                    qwe[i] = qwe[j];
                    qwe[j] = prost;
                  }
                }
              printf ("База успешно отсортирована в обратном алфавитном порядке по названию производителя!\n");
            }
            else printf ("Неверный выбор\n");
          }
          Zapis (argv, qwe, k);       
      break;
      case 2:
        printf ("Нажмите 1, чтобы осортировать в алфавитном порядке\nНажмите 2, чтобы отсортировать в обратном алфавитном порядке\n");
        scanf ("%d", &v);
        if (v == 1)
        {
          for (i=0; i<k-1; i++)
            for (j=i+1; j<k; j++)
            {
              if (strcmp((qwe[i].tip), (qwe[j].tip))>0)
              {
                prost = qwe[i];
                qwe[i] = qwe[j];
                qwe[j] = prost;
              }
            }
            printf ("База успешно отсортирована в алфавитном порядке по серии!\n");
          }
          else
          {
            if (v == 2)
            {
              for (i=0; i<k-1; i++)
                for (j=i+1; j<k; j++)
                {
                  if (strcmp((qwe[i].tip), (qwe[j].tip))<0)
                  {
                    prost = qwe[i];
                    qwe[i] = qwe[j];
                    qwe[j] = prost;
                  }
                }
              printf ("База успешно отсортирована в обратном алфавитном порядке по размеру!\n");
            }
            else printf ("Неверный выбор\n");
          }
          Zapis (argv, qwe, k);    
      break;
      case 3:
        printf ("Нажмите 1, чтобы осортировать по возрастанию\nНажмите 2, чтобы осортировать по убыванию\n");
        scanf ("%d", &v);
        if (v == 1)
        {
          for (i=0; i<k-1; i++)
            for (j=i+1; j<k; j++)
            {
              if ((qwe[i].price)>(qwe[j].price))
              {
                prost = qwe[i];
                qwe[i] = qwe[j];
                qwe[j] = prost;
              }
            }
            printf ("База успешно отсортирована по возрастанию цены товара!\n");
          }
          else
          {
            if (v == 2)
            {
              for (i=0; i<k-1; i++)
                for (j=i+1; j<k; j++)
                {
                  if ((qwe[i].price)<(qwe[j].price))
                  {
                    prost = qwe[i];
                    qwe[i] = qwe[j];
                    qwe[j] = prost;
                  }
                }
              printf ("База успешно отсортирована по убыванию цены товара!\n");
            }
            else printf ("Неверный выбор\n");
          }
          Zapis (argv, qwe, k);
      break;
      case 4:
        printf ("Нажмите 1, чтобы осортировать по возрастанию\nНажмите 2, чтобы осортировать по убыванию\n");
        scanf ("%d", &v);
        if (v == 1)
        {
          for (i=0; i<k-1; i++)
            for (j=i+1; j<k; j++)
            {
              if ((qwe[i].number)>(qwe[j].number))
              {
                prost = qwe[i];
                qwe[i] = qwe[j];
                qwe[j] = prost;
              }
            }
            printf ("База успешно отсортирована по возрастанию номера в базе!\n");
          }
          else
          {
            if (v == 2)
            {
              for (i=0; i<k-1; i++)
                for (j=i+1; j<k; j++)
                {
                  if ((qwe[i].number)<(qwe[j].number))
                  {
                    prost = qwe[i];
                    qwe[i] = qwe[j];
                    qwe[j] = prost;
                  }
                }
              printf ("База успешно отсортирована по убыванию номера в базе!\n");
            }
            else printf ("Неверный выбор\n");
          }
          Zapis (argv, qwe, k);
      break;
      case 5:
        printf ("Нажмите 1, чтобы осортировать в порядке возрастания\nНажмите 2, чтобы осортировать в порядке убывания\n");
        scanf ("%d", &v);
        if (v == 1)
        {
          for (i=0; i<k-1; i++)
            for (j=i+1; j<k; j++)
            {
              if (strcmp((qwe[i].razmer), (qwe[j].razmer))>0)
              {
                prost = qwe[i];
                qwe[i] = qwe[j];
                qwe[j] = prost;
              }
            }
            printf ("База успешно отсортирована в порядке возрастания по размеру!\n");
          }
          else
          {
            if (v == 2)
            {
              for (i=0; i<k-1; i++)
                for (j=i+1; j<k; j++)
                {
                  if (strcmp((qwe[i].razmer), (qwe[j].razmer))<0)
                  {
                    prost = qwe[i];
                    qwe[i] = qwe[j];
                    qwe[j] = prost;
                  }
                }
              printf ("База успешно отсортирована в порядке убывания по размеру!\n");
            }
            else printf ("Неверный выбор\n");
          }
          Zapis (argv, qwe, k);  
      break;
      case 0:
        printf ("Выход из сортировки\n");
      break;
      default:
        printf ("Такого пункта в меню нет\n");
    };
  }
}
