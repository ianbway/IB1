#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "queue.h"
#include "stack.h"
#include "integer.h"
#include "real.h"

static void
showItems (sll * items)
{
  printf ("The items are ");
  displaySLL (stdout, items);
  printf (".\n");
}

static void
showDLLItems (dll * items)
{
  printf ("The items are ");
  displayDLL (stdout, items);
  printf (".\n");
}

static void
showQueueItems (queue *items)
{
  printf ("The queue items are ");
  displayQueue(stdout, items);
  printf(".\n");
}

static void
showStackItems (stack *items)
{
  printf ("The stack items are ");
  displayStack(stdout, items);
  printf(".\n");
}

int
main (int argc, char **argv)
{
  printf("%s argc %d \n", argv[0], argc);

  // sll test
  sll *items = newSLL (displayInteger);
  sll *items2 = newSLL (displayInteger);
  showItems (items);
  insertSLL (items, 0, newInteger (3));	//insert at front
  insertSLL (items, sizeSLL (items), newInteger (2));	//insert at back
  insertSLL (items, 1, newInteger (1));	//insert at middle
  showItems (items);
  printf ("The value ");
  displayInteger (stdout, removeSLL (items, 0));	//remove from front
  printf (" was removed.\n");
  showItems (items);
  int x = getInteger ((integer *) getSLL (items, 0));	//get the first item
  printf ("The first item is %d.\n", x);
  printf ("Create items2 with 2 nodes\n");
  insertSLL (items2, 0, newInteger (4));		//insert at front
  insertSLL (items2, 0, newInteger (5));		//insert at front
  showItems (items2);
  printf ("Now union items and items2\n ");
  unionSLL (items, items2);
  showItems (items);
  showItems (items2);

  printf("Now inserting into items2\n");
        for (int i=0; i < 20; i++)  {
        insertSLL(items2, 0, newInteger(i));
        }
  showItems(items2);
  printf("Now removing from items2\n");

        for(int i = sizeSLL(items2) - 1; i >= 0; i--)  {
        printf("items2 size: %d removing index: %d\n",sizeSLL(items2),i);
        removeSLL(items2, i);
        }

  // dll test
  printf ("Testing DLL.\n");
  dll *items3 = newDLL (displayInteger);
  showDLLItems (items3);
  insertDLL (items3, 0, newInteger (4)); //insert at front
  insertDLL (items3, sizeDLL (items3), newInteger (5)); //insert at back
  insertDLL (items3, 1, newInteger(6)); //insert at middle
  showDLLItems (items3);
  printf ("The value ");
  displayInteger (stdout, removeDLL (items3, 0)); // remove from font
  printf(" was removed.\n");
  showDLLItems (items3);

  printf("Now union items3 and items4\n");
  dll *items4 = newDLL (displayInteger);
  unionDLL(items3,items4);
  showDLLItems(items3);
  showDLLItems(items4);
  insertDLL(items4, 0, newInteger(7)); // insert at front
  unionDLL(items3,items4);
  showDLLItems(items3);
  showDLLItems(items4);
        for (int i=0; i < 20; i++)  {
        insertDLL(items3, 0, newInteger(i));  //insert at front
        }
  showDLLItems(items3);
        int itemSize = sizeDLL(items3);
  printf("Now items3 size: %d\n",itemSize);

        for (int i = itemSize - 1; i >= 0; i--){
        printf("items3 size: %d removing index: %d\n",sizeDLL(items3),i);
        removeDLL(items3,i);
        }
  
  printf("Now create queue\n");
  queue *items5 = newQueue(displayInteger);
        showQueueItems(items5);
  printf("items5 size %d\n",sizeQueue(items5));
        for (int i = 8; i < 20; i++)  {
                enqueue(items5,newInteger(i));
        }
        showQueueItems(items5);
  printf("items5 size after creating nodes: %d\n",sizeQueue(items5));
        printf("peekQueue ");
        displayInteger(stdout,peekQueue(items5));
        printf("\n");
        showQueueItems(items5);

        printf("dequeing ");
        for(int i = sizeQueue(items5) - 1; i >= 0; i--)  {
        displayInteger(stdout,dequeue(items5));
                printf("  ");
        }
        printf("\n");

        showQueueItems(items5);
  printf("items5 size after dequeueing %d\n",sizeQueue(items5));
  
  // test stack
   printf("Now create stack\n");
   stack *items6 = newStack(displayInteger);
        showStackItems(items6);
  printf("items6 size %d\n",sizeStack(items6));
        for (int i = 8; i < 20; i++)  {
                push(items6,newInteger(i));
        }
        showStackItems(items6);
  printf("items6 size after creating nodes: %d\n",sizeStack(items6));
        printf("peekStack ");
        displayInteger(stdout,peekStack(items6));
        printf("\n");
        showStackItems(items6);

        printf("popping ");
        for(int i = sizeStack(items6) - 1; i >= 0; i--)  {
        displayInteger(stdout,pop(items6));
                printf("  ");
        }
        printf("\n");

        showStackItems(items6);
  printf("items6 size after popping %d\n",sizeStack(items6));

  /* tests failed after submit
  printf("TEST 14\n");
  dll *a = newDLL(displayInteger);
  insertDLL(a,0,newInteger(44));
  showDLLItems(a);
  insertDLL(a,0,newInteger(17));
  showDLLItems(a);
  insertDLL(a,2,newInteger(99));
  showDLLItems(a);
  insertDLL(a,3,newInteger(27));
  showDLLItems(a);
  insertDLL(a,3,newInteger(83));
  showDLLItems(a);
  insertDLL(a,5,newInteger(69));
  showDLLItems(a); 

  printf("TEST 15\n");
  dll *b = newDLL(displayInteger);
  insertDLL(b,0,newInteger(57));
  showDLLItems(b);
  insertDLL(b,1,newInteger(79));
  showDLLItems(b);
  insertDLL(b,2,newInteger(11));
  showDLLItems(b);
  insertDLL(b,1,newInteger(1));
  showDLLItems(b);
  insertDLL(b,2,newInteger(76));
  showDLLItems(b);
  insertDLL(b,3,newInteger(8));
  showDLLItems(b);
  removeDLL(b,3);
  showDLLItems(b); 
  insertDLL(b,3,newInteger(61));
  showDLLItems(b);
  insertDLL(b,3,newInteger(83));
  showDLLItems(b);
  insertDLL(b,7,newInteger(50));
  showDLLItems(b);
  */

  printf("Test14\n");
  dll *a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(44));
  showDLLItems(a);
  insertDLL(a,0,newInteger(17));
  showDLLItems(a);
  insertDLL(a,2,newInteger(99));
  showDLLItems(a);
  insertDLL(a,3,newInteger(27));
  showDLLItems(a);
  insertDLL(a,3,newInteger(83));
  showDLLItems(a);
  insertDLL(a,5,newInteger(69));
  showDLLItems(a);

  /*
  printf("Test15\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(57));
  showDLLItems(a);
  insertDLL(a,1,newInteger(79));
  showDLLItems(a);
  insertDLL(a,2,newInteger(11));
  showDLLItems(a);
  insertDLL(a,1,newInteger(1));
  showDLLItems(a);
  insertDLL(a,2,newInteger(76));
  showDLLItems(a);
  insertDLL(a,3,newInteger(8));
  showDLLItems(a);
  removeDLL(a,3);
  showDLLItems(a);
  insertDLL(a,3,newInteger(61));
  showDLLItems(a);
  insertDLL(a,3,newInteger(83));
  showDLLItems(a);
  insertDLL(a,7,newInteger(50));
  showDLLItems(a);
  
    
    
  printf("Test16\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(70));
  showDLLItems(a);
  insertDLL(a,0,newInteger(76));
  showDLLItems(a);
  removeDLL(a,0);
  showDLLItems(a);
  insertDLL(a,0,newInteger(97));
  showDLLItems(a);
  insertDLL(a,2,newInteger(22));
  showDLLItems(a);
  insertDLL(a,2,newInteger(63));
  showDLLItems(a);
  removeDLL(a,1);
  showDLLItems(a);
  insertDLL(a,3,newInteger(44));
  showDLLItems(a);
  */

  
  /*printf("Test17\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(76));
  showDLLItems(a);
  insertDLL(a,1,newInteger(87));
  showDLLItems(a);
  insertDLL(a,2,newInteger(45));
  showDLLItems(a);
  insertDLL(a,0,newInteger(77));
  showDLLItems(a);
  insertDLL(a,4,newInteger(26));
  showDLLItems(a);
  removeDLL(a,1);
  showDLLItems(a);
  insertDLL(a,3,newInteger(3));
  showDLLItems(a);
  insertDLL(a,5,newInteger(56));
  showDLLItems(a);
  */

  /*
  printf("Test18\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(58));
  showDLLItems(a);
  removeDLL(a,0);
  insertDLL(a,0,newInteger(62));
  showDLLItems(a);
  insertDLL(a,0,newInteger(81));
  showDLLItems(a);
  insertDLL(a,0,newInteger(47));
  showDLLItems(a);
  insertDLL(a,1,newInteger(9));
  showDLLItems(a);
  insertDLL(a,4,newInteger(79));
  showDLLItems(a);
  removeDLL(a,1);
  showDLLItems(a);
  insertDLL(a,4,newInteger(51));
  showDLLItems(a);
  insertDLL(a,1,newInteger(60));
  showDLLItems(a);
  insertDLL(a,5,newInteger(4));
  showDLLItems(a);
  insertDLL(a,6,newInteger(15));
  showDLLItems(a);
  insertDLL(a,7,newInteger(63));
  showDLLItems(a);
  insertDLL(a,8,newInteger(4));
  showDLLItems(a);
  insertDLL(a,2,newInteger(54));
  showDLLItems(a);
  removeDLL(a,8);
  showDLLItems(a);
  insertDLL(a,3,newInteger(29));
  showDLLItems(a);
  removeDLL(a,2);
  showDLLItems(a);
  removeDLL(a,2);
  showDLLItems(a);
  insertDLL(a,5,newInteger(33));
  showDLLItems(a);
  removeDLL(a,8);
  showDLLItems(a);
  */

  /*
  printf("Test19\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  insertDLL(a,0,newInteger(19));
  showDLLItems(a);
  insertDLL(a,1,newInteger(60));
  showDLLItems(a);
  removeDLL(a,0);
  showDLLItems(a);
  removeDLL(a,0);
  showDLLItems(a);
  insertDLL(a,0,newInteger(69));
  showDLLItems(a);
  insertDLL(a,1,newInteger(52));
  showDLLItems(a);
  insertDLL(a,0,newInteger(94));
  showDLLItems(a);
  insertDLL(a,3,newInteger(39));
  showDLLItems(a);
  insertDLL(a,3,newInteger(94));
  showDLLItems(a);
  insertDLL(a,2,newInteger(90));
  showDLLItems(a);
  insertDLL(a,6,newInteger(79));
  showDLLItems(a);


  printf("Test20\n");
  a = newDLL(displayInteger);
  showDLLItems(a);
  dll *b = newDLL(displayInteger);
  showDLLItems(b);
  */
  
  printf("Test21\n");
  a = newDLL(displayReal);
  showDLLItems(a);
  insertDLL(a,0,newReal(34.400000));
  showDLLItems(a);
  insertDLL(a,1,newReal(2.400000));
  showDLLItems(a);
  removeDLL(a,1);
  showDLLItems(a);
  insertDLL(a,1,newReal(17.400000));
  showDLLItems(a);
  insertDLL(a,0,newReal(11.700000));
  showDLLItems(a);
  insertDLL(a,1,newReal(83.300000));
  showDLLItems(a);
  insertDLL(a,2,newReal(58.200000));
  showDLLItems(a);
  insertDLL(a,3,newReal(33.400000));
  showDLLItems(a);
  removeDLL(a,0);
  showDLLItems(a);
  insertDLL(a,3,newReal(1.300000));
  showDLLItems(a);
  removeDLL(a,3);
  showDLLItems(a);
  removeDLL(a,1);
  showDLLItems(a);
  insertDLL(a,0,newReal(26.800000));
  showDLLItems(a);
  insertDLL(a,5,newReal(0.600000));
  showDLLItems(a);  

return 0;
}
