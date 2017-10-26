#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    book * head = malloc(sizeof(book));
    head -> pointer = NULL;
    insert_node(head, create_node("Chris", "Chrisy", 246729));
    insert_node(head, create_node("Dave", "Davey", 125674));
    insert_node(head, create_node("Tom", "Tommy", 753216));
    insert_node(head, create_node("Steve", "Stevey", 983418));
    insert_node(head, create_node("Ton", "Tony", 835636));
    insert_node(head, create_node("Mark", "Marky", 176549));
    print_nodes(head);
    return 0;
}

book * create_node(char title[], char author[], long isbn){
    book * new_node = malloc(sizeof(book));
    strcpy(new_node -> book_title, title);
    strcpy(new_node -> book_author, author);
    new_node -> book_isbn = isbn;
    return new_node;
}

void insert_node(book * current_node, book * node_to_insert){
    if (!(current_node -> pointer)){
        current_node -> pointer = node_to_insert;
        node_to_insert -> pointer = NULL;
        return;
    }
    if(node_to_insert -> book_isbn < current_node -> book_isbn){
        insert_node(current_node -> pointer, node_to_insert);
        return;
    } else {
        node_to_insert -> pointer = current_node -> pointer;
        current_node -> pointer = node_to_insert;
        return;
    }
}

void print_nodes(book * current_node){
    if(current_node -> pointer){
        print_nodes(current_node -> pointer);
    }
    if (current_node -> book_isbn) {
        printf("Title of the book: %s\nName of the author: %s\nISBN: %li\n", current_node->book_title,
               current_node->book_author, current_node->book_isbn);
    }
    return;
}
