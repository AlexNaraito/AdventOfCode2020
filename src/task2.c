/*
    Автор: AlexNaraito
    Задача 1: У владельца магазина проката тобогганов на Северном полюсе тяжелый день. "Что-то не так с нашими компьютерами; мы не можем войти!" Вы спрашиваете, можно ли взглянуть.

    Их база паролей, кажется, немного повреждена: некоторые пароли не были разрешены официальной корпоративной политикой тобоггана, которая действовала на момент их выбора.

    Чтобы попытаться отладить проблему, они создали список (ввод головоломки) паролей (согласно поврежденной базе данных) и корпоративную политику, когда этот пароль был установлен.

    Например, предположим, что у вас есть следующий список:

    1-3 а: abcde
    1-3 б: cdefg
    2-9 c: ccccccccc

    В каждой строке указывается политика паролей, а затем пароль. Политика паролей указывает наименьшее и наибольшее количество раз, когда данная буква должна появляться, чтобы пароль был действительным. Например, 1-3 a означает, что пароль должен содержать минимум 1 раз и максимум 3 раза.

    В приведенном выше примере действительны 2 пароля. Средний пароль cdefg - нет; он не содержит экземпляров b, но требует как минимум 1. Первый и третий пароли действительны: они содержат один a или девять c, оба в пределах их соответствующих политик.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pair{
    int num1;   // начало диапазона
    int num2;   // конец диапазона
    char sim;   // символ
    char str[32];  // строка
} Pair;

void error(const char* msg){
    printf("Error:%s\n",msg);
    exit(EXIT_FAILURE);
}

bool check_task1(int num1, int num2, char sim, char* msg){
    int count = 0;
    for (int i = 0; msg[i] != '\0';i++){
        if(msg[i] == sim) count++;
    }
    if(count >= num1 && count <= num2) return true;
    return false;
}

bool check_task2(int num1, int num2, char sim, char* msg){
    if(msg[num1-1] == msg[num2-1]) return false;
    if((msg[num1-1] == sim) || (msg[num2-1] == sim)) return true;
    return false;
}

//Return size; input - empty array; in progress - fill array
void fill_array(Pair* arr, const char* path){
    Pair element; int current = 0;
    char buf[64], buf_num1[10],buf_num2[10], buf_sim, buf_str[32];
    char* line;
    FILE* file = fopen(path,"r");
    if(file == NULL) error("File not found!");
    while(1){
        line = fgets(buf,64,file);
        if(line == NULL) break;
        int c_num1 = 0, c_num2 = 0, c_str = 0, flag = 0;
        for(int i = 0; line[i] != '\0'; i++){
            if(line[i] == '-') {
                flag = 1;
                i++;
            }
            if(line[i] == ' ') {
                flag = 2;
                i++;
            }
            if(line[i] == ':') {
                flag = 3;
                i+=2;
            }
            if(flag == 0) {
                buf_num1[c_num1] = line[i];
                c_num1++;
            }
            if(flag == 1){
                buf_num2[c_num2] = line[i];
                c_num2++;
            }
            if(flag == 2){
                buf_sim = line[i];
            }
            if(flag == 3){
                buf_str[c_str] = line[i];
                c_str++;
            }
        }
        element.num1 = atoi(buf_num1);
        element.num2 = atoi(buf_num2);
        for(int k = 0; k < 10; k++){
            buf_num1[k] = '\0';
            buf_num2[k] = '\0';
        }
        element.sim = buf_sim;
        for(int k = 0; k < 32; k++) element.str[k] = buf_str[k];
        for(int k = 0; k < 32; k++) buf_str[k] = '\0';
        arr[current] = element;
        current++;
    }
    fclose(file);
}

int main(){
    Pair* arr = (Pair*)malloc(sizeof(Pair) * 1000);
    fill_array(arr,"../data/task2.txt");
    int count = 0;
    for (int i = 0; i < 1000; i++){
        if(check_task1(arr[i].num1,arr[i].num2,arr[i].sim,arr[i].str)) count++;
    }
    printf("Subtask 1:%d\t",count);
    count = 0;
    for (int i = 0; i < 1000; i++){
        if(check_task2(arr[i].num1,arr[i].num2,arr[i].sim,arr[i].str)) count++;
    }
    printf("Subtask 2:%d\n",count);
    free(arr);
    return 0;
}