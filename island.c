#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


typedef struct island {
    int value;
    struct island *next;
} island;

island *make_first(int v)
{
    island *first = malloc(sizeof(island));

    first->value = v;
    first->next = NULL;

    return first;
};
void show(const island *beg){
    beg ? printf("value: %d\n", beg->value), show(beg->next) : 0;
}

void add(island *beg, int v){
    if(beg->next)
        add(beg->next, v);
    else{
        island *new = malloc(sizeof(island));
        beg->next = new;
        new->value = v;
        new->next = NULL;
    }
}





int del(island *beg, int n){
    if(beg->next){
        if(beg->next->next)
            del(beg->next, n+1);
        else{
            free(beg->next);
            beg->next = NULL;
            return n+1;
        }
    }
    else
        free(beg);
        return 0;
}


void del_all(island *beg){
    beg->next ? del_all(beg->next), free(beg): free(beg);
}


int search(island *beg, int v, int i){
    return beg->value != v ? beg->next ? search(beg->next, v, i+1) : 0 : i+1;
};

int main(){

    char command;
    char *menu;

    int lst, f, l;
    int t, n;
    int y = 1;
    island *x;


    menu = "-----------------------------------------------------\n"
           "1)To create the first element of the singly linked list.",
           "2)Add the element to the end of a singly linked list.",
           "3)Delete the element from the end of a singly linked list.",
           "4)To view a singly linked list.",
           "5)Delete a singly linked list.",
           "6)Search of the element in the singly linked list.",
           "7)Exit."
           "-----------------------------------------------------\n";

    while (y){
        printf("%s", menu);
        scanf(" %c", &command);
        printf("\n");

        if (command == '1'){
            printf(">>> enter the first element of list: ");
            t = scanf("%d", &n);
            if(t != 1){
                printf("------| error |------\n");
                printf("incorrect data have been entered\n");
                return 1;
            }
            x = make_first(n);
            lst = l = 1;
            y=1;
            printf("%s", menu);
            scanf(" %c", &command);
        }

        if (command == '2'){
            printf(">>> enter the value of an adding element: ");
            t = scanf("%d", &n);
            if(t != 1){
                printf("------| error |------\n");
                printf("incorrect data have been entered\n");
                return 1;
            }
            add(x, n);
            y=1;
            printf("---------------------\n");
            printf("%s", menu);
            scanf(" %c", &command);
        }



        if (command == '3'){
            l = del(x, 0);
            y=1;
            if(!l){
                printf(">>> the list has been deleted\n");

            }
            printf("---------------------\n");
            printf("%s", menu);
            scanf(" %c", &command);
        }

        if (command == '4'){
            show(x);
            y=1;
            printf("---------------------\n");
            printf("%s", menu);
            scanf(" %c", &command);
        }


        if (command == '5'){
            del_all(x);
            y=1;
            printf(">>> the list has been deleted\n");

            printf("---------------------\n");
            printf("%s", menu);
            scanf(" %c", &command);
        }


        if (command == '6'){
             printf(">>> enter the value you want to find: ");
                t = scanf("%d", &n);
                if(t != 1){
                    printf("------| error |------\n");
                    printf("incorrect data have been entered\n");
                    return 1;
                }
                f = search(x, n, 0);
                if(f)
                    printf(">>> the index of %d is %d\n", n, f);
                else
                    printf(">>> no such value in the list\n");
                printf("---------------------\n");
                y=1;
            printf("%s", menu);
            scanf(" %c", &command);
        }


        if (command == '7'){
            y=0;
        }
        printf("\n");
    }

printf("Bay.\n");
return 0;

}
