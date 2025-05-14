#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define declare_list_type(type, listName)                                             \
    typedef struct listName##_node {                                                  \
        type data;                                                                    \
        struct listName##_node* next;                                                 \
    } listName##_node;                                                                \
                                                                                      \
    typedef struct listName {                                                         \
        listName##_node* head;                                                        \
    }                                                                                 \
    listName;                                                                         \
                                                                                      \
    void listName##_init(listName* list) {                                            \
        list->head = NULL;                                                            \
    }                                                                                 \
                                                                                      \
    void listName##_add(listName* list, type elem) {                                  \
        listName##_node* newNode = (listName##_node*)malloc(sizeof(listName##_node)); \
        newNode->data = elem;                                                         \
        newNode->next = list->head;                                                   \
        list->head = newNode;                                                         \
    }                                                                                 \
                                                                                      \
    void listName##_free_list(listName* list) {                                       \
        listName##_node* current = list->head;                                        \
        listName##_node* next;                                                        \
        while (current != NULL) {                                                     \
            next = current->next;                                                     \
            free(current);                                                            \
            current = next;                                                           \
        }                                                                             \
        list->head = NULL;                                                            \
    }


#define init_list(type, listName, list) listName##_init(list)

#define add_to_list(type, listName, list, elem) listName##_add(list, elem)

#define free_list(type, listName, list) listName##_free_list(list)

#define define_list_print(format, listName)                                           \
    void listName##_print(listName* list) {                                           \
        if(list->head == NULL){                                                       \
            printf("List is empty\n");                                                \
            return;                                                                   \
        } else {                                                                      \
            listName##_node* current = list->head;                                    \
            while (current != NULL) {                                                 \
                printf(format, current->data);                                        \
                current = current->next;                                              \
            }                                                                         \
            printf("\n");                                                             \
        }                                                                             \
    }                                                                                 \
                                                                                      

#endif
                                           

                                        
                  


        
