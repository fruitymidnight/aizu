#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define LOG(...) fprintf(stderr, __VA_ARGS__)
#else
#define LOG(...) 
#endif // DEBUG

struct convert_list
{
    char from;
    char to;
    struct convert_list *next;
};
typedef struct convert_list CONVERT_LIST;


CONVERT_LIST* insert_list(CONVERT_LIST *list, char from, char to);
char search_list(CONVERT_LIST *head, char target);
void delete_list(CONVERT_LIST *list);

int main(void)
{
    
    while (1) {
        int num, convert_num;
        char from, to, target;
        int i;
        CONVERT_LIST *list_head;
        
        scanf("%d\n", &num);
        LOG("num = %d\n", num);

        if (num == 0) {
            break;
        }
        
        /* Make convert table */
        for (i = 0; i < num; i++) {
            scanf("%c %c\n", &from, &to);
            LOG("from = %c, to = %c\n", from, to);
            list_head = insert_list(list_head, from, to);
        }

        /* Convert */
        scanf("%d\n", &convert_num);
        LOG("convert_num = %d\n", convert_num);
        for (i = 0; i < convert_num; i++) {
            scanf("%c\n", &target);
            LOG("target = %c\n", target);

            printf("%c", search_list(list_head, target));
        }
        printf("\n");

        delete_list(list_head);
        list_head = NULL;
        
    }
    
    return 0;
}

CONVERT_LIST* insert_list(CONVERT_LIST *list, char from, char to) 
{
    CONVERT_LIST *head, *tail, *new_node;
    head = tail = list;

    if (tail != NULL) {
        for ( ; tail->next != NULL ; tail = tail->next) {
            /* NOP */
        }
    }
        
    new_node = (CONVERT_LIST*)malloc(sizeof(CONVERT_LIST));
    if (new_node == NULL) {
        /* malloc failed */
        return NULL;
    }

    memset(new_node, '\0', sizeof(CONVERT_LIST));
    new_node->from = from;
    new_node->to = to;
    new_node->next = NULL;

    if (tail != NULL) {
        tail->next = new_node;
    }
    else {
        head = new_node;
    }

    return head;

}

char search_list(CONVERT_LIST *head, char target) 
{
    CONVERT_LIST *tmp;
    tmp = head;
    if (head == NULL) {
        return target;
    }

    for ( ; tmp != NULL ; tmp = tmp->next) {
        if (tmp->from == target) {
            return tmp->to;
        }
    }

    return target;
    
}

void delete_list(CONVERT_LIST *list)
{
    CONVERT_LIST *tmp;
    tmp = list;
    if (list == NULL) {
        return ;
    }

    for ( ; list != NULL ; list = tmp) {
        tmp = list->next;
        free(list);
    }

    return ;


}


