/*
    Автор: AlexNaraito
    TODO:Разбить всё на функции расписать в отдельных функциях решение 1 и 2 задачи.
    Задача 1: Прежде чем вы уйдете, эльфам-бухгалтерам просто нужно, чтобы вы исправили свой отчет о расходах (ввод головоломки) очевидно, что-то не совсем складывается.
    В частности, им нужно, чтобы вы нашли две записи, которые в сумме дают 2020, а затем умножьте эти два числа вместе.
    Например, предположим, что ваш отчет о расходах содержит следующее:
        1721
        979
        366
        299
        675
        1456
    В этом списке две записи, которые в сумме составляют 2020, - это 1721 и 299. Их умножение дает 1721 * 299 = 514579, поэтому правильный ответ - 514579.

    Задача 2:Эльфы-бухгалтеры благодарны за вашу помощь; один из них даже предлагает вам монету с морской звездой, оставшуюся от прошлого отпуска. Они предлагают вам второй, если вы найдете в своем отчете о расходах три числа, которые соответствуют тем же критериям.

    Снова используя приведенный выше пример, три записи, которые в сумме составляют 2020, - это 979, 366 и 675. Их умножение дает ответ 241861950.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void error(const char* msg){
    printf("Error:%s\n",msg);
    exit(EXIT_FAILURE);
}

void get_arr(int* arr){
    FILE* file = fopen("../data/task1.txt","r");
    char* line;
    char str[6];
    if (file == NULL) error("FILE not find.");
    for(int i = 0; i < 200; i++){
        line = fgets(str,6,file);
        if(line == NULL) break;
        arr[i] = atoi(str);
    }
}

int get_result_1(int* arr){
    int result = 0;
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            if(arr[i] + arr[j] == 2020) 
                result = arr[i] * arr[j];
    return result;
}

int get_result_2(int* arr){
    int result = 0;
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            for(int k = 0; k < 200; k++)
                if(arr[i] + arr[j] + arr[k] == 2020)
                    result = arr[i] * arr[j] * arr[k];
    return result;
}

int main(){
    int* arr = (int*)malloc(sizeof(int) * 200); 
    get_arr(arr);
    printf("Result:%d\tResult2:%d\n",get_result_1(arr),get_result_2(arr));
    return 0;
}