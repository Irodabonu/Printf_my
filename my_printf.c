#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include<unistd.h>

int my_orange(char* str){
    int u = 0, len = 0;
    while(str[u]){
        write(1, &str[u], 1);
        len++;
        u++;
    }
    return len;
}


int ejective(int future, char s){
    int goal = 0;


    if(future == 0){
        putchar('0');
        return ++goal;
    }


    if(future < 0){
        if(s == 'd'){
            putchar('-');
            goal++;
        }
        future *= -1;
    }


    char subject[100];
    char qd;
    int l = 0;
    while(future){
        qd = future % 10 + 48;
        subject[l++] = qd;
        future /= 10;
    }


    for(int n = l - 1; n >= 0; --n){
        putchar(subject[n]);
    }


    return goal + l;
}


int present(int future){
    int goal = 0;


    if(future == 0){
        putchar('0');
        return ++goal;
    }


    if(future < 0){
        future *= -1;
    }


    char subject[100];
    char qd;
    int l = 0;
    while(future){
        qd = future % 8 + 48;
        subject[l++] = qd;
        future /= 8;
    }


    for(int n = l - 1; n >= 0; --n){
        putchar(subject[n]);
    }


    return goal + l;
}


int print_hex(long future){
    int goal = 0;


    if(future == 0){
        putchar('0');
        return 0;
    }


    if(future < 0){
        future *= -1;
    }


    char subject[100];
    char qd;
    int l = 0;
    char *hi = "0123456789ABCDEF";
    while(future){
        qd = hi[future % 16];
        subject[l++] = qd;
        future /= 16;
    }


    for(int n = l - 1; n >= 0; --n){
        putchar(subject[n]);
    }
    return goal + l;
}


int my_printf(char *subject, ...){
    va_list football;
    va_start(football, subject);


    int goal = 0;
    for(int l = 0; l < (int)strlen(subject); ++l){


        if(subject[l] == '%'){
            subject++;


            switch(subject[l]){
                case 'c': {
                    char qd = (char)va_arg(football, int);
                    putchar(qd);
                    ++goal;
                    break;
                }
                case 's': {
                    char *subject = va_arg(football, char*);
                    if(subject == NULL){
                        my_orange("(null)");//shu erda yozing
                        goal += 6;
                    }else{
                        my_orange(subject);
                        goal += strlen(subject);
                    }
                    break;
                }
                case 'd':
                {
                    int a = va_arg(football, int);
                    goal += ejective(a, subject[l]);
                    break;
                }
                case 'u':
                {
                    int a = va_arg(football, int);
                    goal += ejective(a, subject[l]);
                    break;
                }
                case 'o': {
                    int a = va_arg(football, int);
                    goal += present(a);
                    break;
                }
                case 'x': {
                    int a = va_arg(football, int);
                    goal += print_hex(a);
                    break;
                }
                case 'p': {
                    unsigned long a = (unsigned long)va_arg(football, void*);
                    putchar('0');
                    putchar('x');
                    goal += 2;


                    goal += print_hex(a);
                }
            }
        } else {
            putchar(subject[l]);
            ++goal;
        }


    }


    return goal;
}


int main () {
    printf("    %d\n", my_printf("Hello world!\n"));
    printf("    %d\n", my_printf("%c!\n", 'H'));
    printf("    %d\n", my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'));
    printf("    %d\n", my_printf("Hello %s!\n", "QWASAR.IO"));
    printf("    %d\n", my_printf("Hello %s %s!\n", "Mr", "Gaetan"));
    printf("    %d\n", my_printf("NULL STRING %s!\n", (char*)NULL));
    printf("    %d\n", my_printf("%d!\n", 1337));
    printf("    %d\n", my_printf("%d - %d - %d!\n", 2048, 0, -1337));
    printf("    %d\n", my_printf("%o!\n", 100));
    printf("    %d\n", my_printf("%u!\n", 1337));
    printf("    %d\n", my_printf("%x!\n", 14));
    char* any_variable = "hello";
    printf("    %d\n", my_printf("%p!\n", any_variable));
}
