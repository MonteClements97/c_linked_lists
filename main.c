#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    book *head = NULL;
    head = insert_node(head, head, create_node("Chris", "Chrisy", 246729));     //some test values
    head = insert_node(head, head, create_node("Dave", "Davey", 125674));
    head = insert_node(head, head, create_node("Tom", "Tommy", 753216));
    head = insert_node(head, head, create_node("Steve", "Stevey", 983418));
    head = insert_node(head, head, create_node("Ton", "Tony", 835636));
    head = insert_node(head, head, create_node("Mont", "Monty", 176549));
    head = insert_node(head, head, create_node("Jam", "Jammy", 456345));
    head = insert_node(head, head, create_node("Con", "Conny", 178432));
    print_nodes(head);
    print_selected_node(head, "Chris");
    print_selected_node(head, "Mont");
    print_selected_node(head, "Jammy");
    return 0;
}

book *create_node(char title[], char author[], long isbn) {
    //creates a new node with the title, author and isbn passed to it
    book *new_node = malloc(sizeof(book));
    if (!new_node){      //very unlikely, but just in case, you never know
        printf("ASSIGNING MEMORY FAILED");
        exit(2);         //kill the program, not able to deal with this
    }
    strcpy(new_node->book_title, title);
    strcpy(new_node->book_author, author);
    new_node->book_isbn = isbn;
    return new_node;
}

book *insert_node(book *head, book *current_node, book *node_to_insert) {
    //sorts nodes in ascending order
    if (!head) {
        return node_to_insert; //if head is NULL nothing is in the list
    }

    if ((current_node == head) && (current_node->book_isbn > node_to_insert->book_isbn)) {
        //node that is to be inserted needs to be placed at head
        head = node_to_insert;
        node_to_insert->pointer = current_node;
        return head;
    }

    while (current_node) {
        //while we have something to look at. We should always be looking at something, so essentially a while true
        if (current_node->pointer) {
            if (current_node->pointer->book_isbn < node_to_insert->book_isbn) {
                current_node = current_node->pointer;
                continue; //do not want to hit line 57 if this is the case
            } else {
                node_to_insert->pointer = current_node->pointer;
                current_node->pointer = node_to_insert;
                return head;
            }
        }
        current_node->pointer = node_to_insert;
        return head;

    }

    return head; //just in case something breaks
}


void print_selected_node(book * head, char title[]){
    //finds a node based on it's title
    if (!(strcmp(head -> book_title, title))){
        printf("Title of the book: %s\nName of the author: %s\nISBN: %li\n",
               head->book_title, head->book_author, head->book_isbn);
        return;
    } else if (head->pointer){
        print_selected_node(head->pointer, title);
    } else {
        printf("COULD NOT FIND: %s\n", title);
    }
    return;
}


void print_nodes(book *current_node) {
    if (current_node->pointer) {
        print_nodes(current_node->pointer);
    }
    if (current_node){
        printf("Title of the book: %s\nName of the author: %s\nISBN: %li\n", current_node->book_title,
               current_node->book_author, current_node->book_isbn);
    }

    return;
}
