#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

/* Ian Braudaway */

/* Create a singly-linked list */
sll *
newSLL(void (*d)(FILE *, void *))    //d is the display function
{
    sll *items = malloc(sizeof(sll));
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

/* Store a generic value in the singly-linked list */
void
insertSLL(sll *items, int index, void *value) {
    if (index > items->size || index < 0) {
        fprintf(stderr, "invalid index: %d used", index);
        exit(-1);
    }

    sllnode *newNode = malloc(sizeof(sllnode));
    newNode->value = value;
    newNode->next = 0;

    // empty list so insert at the head
    if (items->size == 0) {
        items->head = newNode;
        items->tail = newNode;
        items->size++;
        return;
    }

    if (index == items->size) {
        items->tail->next = newNode;
        items->tail = newNode;
        items->size++;
        return;
    }

    int currentIndex = 0;
    sllnode *currentNode = items->head;
    sllnode *prevNode = 0;
    while (currentNode != 0) {
        //Insert here
        if (currentIndex == index) {
            newNode->next = currentNode;
            if (prevNode)
                prevNode->next = newNode;
            if (currentIndex == 0) {
                items->head = newNode;
            }
            if (currentIndex == items->size) {
                items->tail = newNode;
            }

            break;
        }
        ++currentIndex;
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    items->size++;

    return;
}

/* Remove an item from the singly-linked list and return the value */
void *
removeSLL(sll *items, int index) {
    if (index > (items->size - 1) || index < 0) {
        fprintf(stderr, "invalid index: %d used", index);
        exit(-1);
    }

    sllnode *removedNode = 0;
    sllnode *currentNode = 0;
    int currentIndex = 0;
    sllnode *previousNode = 0;

    currentNode = items->head;
    while (currentNode) {
        //found desired node to remove
        if (index == currentIndex) {
            //update previous node to point to next
            if (previousNode) {
                previousNode->next = currentNode->next;
            }
            //deleted first item, update head
            if (currentIndex == 0) {
                items->head = currentNode->next;
            }
            //deleted last item, update tail
            if (currentIndex == items->size - 1) {
                items->tail = previousNode;
            }

            --items->size;
            removedNode = currentNode;
            break;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;
        ++currentIndex;
    }

    return removedNode->value;

}

/* Merge two lists into one */
void
unionSLL(sll *recipient, sll *donor) {
    if (donor->size == 0 && recipient->size == 0) {
        return;
    }

    sllnode *currentNode = 0;
    currentNode = donor->head;
    while (currentNode != 0) {
        // insert donor value until no more items are in donor
        insertSLL(recipient, recipient->size, removeSLL(donor, 0));
        currentNode = currentNode->next;
    }
    return;
}

/* Retrieve the value of the sll item and the input index */
void *
getSLL(sll *items, int index) {
    if (index < 0 || index >= (items->size)) {
        fprintf(stderr, "invalid index: %d used\n", index);
        exit(-1);
    }

    int lastIndex = items->size - 1;
    sllnode *item = 0;
    if (index == 0)  //first item
    {
        item = items->head;
    } else if (index == lastIndex)  //tail
    {
        item = items->tail;
    } else //loop through to get item
    {
        sllnode *current = items->head;
        int currentIndex = 0;
        while (current) {
            if (currentIndex == index) {
                item = current;
                break;
            }
            ++currentIndex;
            current = current->next;
        }
    }
    return item->value;
}

int
sizeSLL(sll *items) {
    // return current size
    return items->size;
}

/* print out values in list format */
void
displaySLL(FILE *f, sll *items) {
    // print opening bracket
    fprintf(f, "[");
    sllnode *currentNode = items->head;

    while (currentNode) {
        items->display(f, currentNode->value);
        if (items->size > 1 && currentNode != items->tail) {
            fprintf(f, ",");
        }
        currentNode = currentNode->next;
    }

    // print closing bracket
    fprintf(f, "]");
}
