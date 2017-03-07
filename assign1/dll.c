#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

/* Ian Braudaway */

/* Create a doubly-linked list */
dll *
newDLL(void (*d)(FILE *, void *)) {
    dll *items = malloc(sizeof(dll));
    if (items == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    items->display = d;
    return items;
}

/* Store a generic value in the doubly-linked list */
void
insertDLL(dll *items, int index, void *value) {

    if (index > items->size || index < 0) {
        fprintf(stderr, "invalid index: %d used\n", index);
        exit(-1);
    }

    dllnode *newNode = malloc(sizeof(dllnode));
    newNode->value = value;
    newNode->next = 0;
    newNode->previous = 0;

    // empty list so insert at the head
    if (items->size == 0) {
        items->head = newNode;
        items->tail = newNode;
        items->size++;
        return;
    }

    if (index == items->size) {
        items->tail->next = newNode;
        newNode->previous = items->tail;
        items->tail = newNode;
        items->size++;
        return;
    }

    int currentIndex = 0;
    dllnode *currentNode = items->head;

    int goingForward = (items->size / 2) >= index;
    if (!goingForward) {
        currentIndex = items->size - 1;
        currentNode = items->tail;
    }
    while (currentNode) {
        if (currentIndex == index) {
            newNode->next = currentNode;
            newNode->previous = currentNode->previous;
            // currentNode->previous may be null
            if (currentNode->previous) {
                currentNode->previous->next = newNode;
            }
            currentNode->previous = newNode;

            if (currentIndex == 0) {
                items->head = newNode;
            }

            if (currentIndex == items->size) {
                items->tail = newNode;
            }

            ++items->size;
            break;
        }

        if (goingForward) {
            ++currentIndex;
            currentNode = currentNode->next;
        } else {
            --currentIndex;
            currentNode = currentNode->previous;
        }
    }

    return;
}

/* Remove an item from the doubly-linked list and return the value */
void *
removeDLL(dll *items, int index) {
    if (index > (items->size - 1) || index < 0) {
        fprintf(stderr, "invalid index: %d used for size %d\n", index, items->size);
        exit(-1);
    }

    dllnode *removedNode = 0;
    dllnode *currentNode = items->head;
    int currentIndex = 0;

    int goingForward = index <= (items->size / 2);
    if (!goingForward) {
        currentIndex = items->size - 1;
        currentNode = items->tail;
    }

    while (currentNode) {
        //found desired node to remove
        if (index == currentIndex) {

            //update previous/next nodes to remove reference to current node
            if (currentNode->previous)
                currentNode->previous->next = currentNode->next;

            //point next node to previous
            if (currentNode->next)
                currentNode->next->previous = currentNode->previous;

            //deleted first item, update head
            if (currentIndex == 0) {
                items->head = currentNode->next;
            }
            //deleted last item, update tail
            if (currentIndex == items->size-1) {
                items->tail = currentNode->previous;
            }

            --items->size;
            removedNode = currentNode;
            break;
        }

        if (goingForward) {
            currentNode = currentNode->next;
            ++currentIndex;
        } else {
            currentNode = currentNode->previous;
            --currentIndex;
        }
    }

    return removedNode->value;

}

/* Merge two lists into one */
void
unionDLL(dll *recipient, dll *donor) {
    if (donor->size == 0 && recipient->size == 0) {
        return;
    }

    dllnode *currentNode = 0;
    currentNode = donor->head;
    while (currentNode != 0) {
        // insert donor value until no more items are in donor
        insertDLL(recipient, recipient->size, removeDLL(donor, 0));
        currentNode = currentNode->next;
    }
    return;
}

/* Retrieve the value of the dll item and the input index */
void *
getDLL(dll *items, int index) {
    // validate the index, return error if invalid
    if (index < 0 || index > (items->size)) {
        fprintf(stderr, "invalid index: %d used\n", index);
        exit(-1);
    }

    int lastIndex = items->size - 1;
    dllnode *foundNode = 0;
    dllnode *currentNode = items->head;
    int currentIndex = 0;

    if (index == 0) {
        foundNode = items->head;

    } else if (index == lastIndex) {
        foundNode = items->tail;
    } else {
        int goingForward = (items->size / 2) > index;
        if (!goingForward) {
            currentIndex = items->size - 1;
            currentNode = items->tail;
        }

        while (currentNode) {
            if (currentIndex == index) {
                foundNode = currentNode;
                break;
            }

            if (goingForward) {
                ++currentIndex;
                currentNode = currentNode->next;
            } else {
                --currentIndex;
                currentNode = currentNode->previous;
            }
        }
    }

    return foundNode->value;
}

int
sizeDLL(dll *items) {
    // return current size
    return items->size;
}

/* print out values in list format */
void
displayDLL(FILE *f, dll *items) {
    fprintf(f, "[");
    dllnode *currentNode = items->head;

    while (currentNode) {
        items->display(f, currentNode->value);
        if (items->size > 1 && currentNode != items->tail) {
            fprintf(f, ",");
        }
        currentNode = currentNode->next;
    }
    fprintf(f, "]");

    return;
}
