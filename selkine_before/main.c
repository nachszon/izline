/*
pierwszy argument: nazwa pliku
drugi argument: string wzorca
trzeci argument: liczba linii before (przed wzorcem)
cel: wyœwietlenie linii zawieraj¹cej wzorzec
oraz okreœlonej liczby linii po wzorcu
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //declarations
    int arg_count;
    FILE *pointer_to_file;
    char tab_file_name[32];
    char tab_string[100];
    int numb_before_line_f_user;
    int numb_before_line;
    int numb_line;
    char tab_pattern_f_user[100];
    int numb_before_start;
    int numb_before_end;





    //sets values
    sprintf (tab_file_name,argv[1]);
    sprintf (tab_pattern_f_user,argv[2]);
    numb_before_line_f_user=atoi(argv[3]);
    arg_count=4;
    numb_line=0;






    //Obs³uga b³êdu - nieprawid³owa liczba argumentów
    if (argc!=arg_count){

        puts ("Nieprawidlowa liczba argumentow");

        return 0;
    }

    if ((pointer_to_file=fopen(tab_file_name,"r"))==NULL){

        printf ("Nie moge otworzyc pliku %s\n", tab_file_name);

        return 0;

    }

    while ((fgets(tab_string,100,pointer_to_file))!=NULL){


        numb_line++;

    if (strstr(tab_string,tab_pattern_f_user)){

        //fputs (tab_string,stdout);
        break;
    }


    }

    numb_before_start=numb_line-numb_before_line_f_user;


    //przenosimy wartoœæ pozycji wzorca


    //wracamy na pocz¹tek pliku
    rewind(pointer_to_file);

    //przekazujemy wartoœæ licznika linii do zmiennej numb_before_start
    numb_before_end=numb_line;

    //zerujemy licznik linii
    numb_line=0;

    while ((fgets(tab_string,100,pointer_to_file))!=NULL){


        numb_line++;

        if (numb_line>=numb_before_start && numb_line<=numb_before_end){


            fputs(tab_string,stdout);
        }

    }








    return 0;
}
