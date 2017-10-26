#ifndef SECONDPRACPROJECTDEBUG_TEST_H
#define SECONDPRACPROJECTDEBUG_TEST_H
typedef struct s_book {
    char book_title[101];
    char book_author[61];
    long book_isbn;
    struct s_book * pointer;
} book;
book * create_node(char title[], char author[], long isbn);
void insert_node(book * current_node, book * node_to_insert);
void print_nodes(book * current_node);
#endif //SECONDPRACPROJECTDEBUG_TEST_H
