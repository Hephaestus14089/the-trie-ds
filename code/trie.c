#include <stdio.h>
#include <stdlib.h>

const int ALPHABET_SIZE = 26; // size of every container of child nodes

typedef struct Node {
    struct Node** children; // pointer to the collection of child nodes
    int isEndOfWord; // whether the node is the last node of a word/key
} Node;

Node* getNewNode() {

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) { // check whether allocation was successfull
        printf("err: Unable to allocate memory!");
        return NULL;
    }

    newNode->children = (Node**)malloc(sizeof(Node*) * ALPHABET_SIZE);

    int i = 0;
    for (; i < ALPHABET_SIZE; i++) {
        *(newNode->children + i) = NULL; // initialising each block as null
    }

    newNode->isEndOfWord = 0; // initialising as false

    return newNode;
}

int main() {

    Node* node = getNewNode();

    int i = 0;
    for (; i < ALPHABET_SIZE; i++) {
        if (*(node->children + i) == NULL)
            printf("%d. null\n", i);
    }

    printf("\nisEndOfWord: %d\n", node->isEndOfWord);
    return 0;
}
