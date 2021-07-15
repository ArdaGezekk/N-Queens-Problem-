 #include <stdio.h>
 #include <time.h>
 #define QUEENS 8          /* number of queens and board size */
 #define int unsigned

 int number = 0;
 int board [QUEENS];       /* each element represents a queue*/

 int boardTamam              /* check the validity of the board */
     (register int queue)
 {
   register int r;

   for (r = 0; r < queue; r++) /* Check all previous queues */
     if (board[queue] == board[r] ||
         board[queue] == board[r] << queue-r ||
         board[queue] == board[r] >> queue-r)
       return 0;
   return 1;
 }

 void writesol (void)        /* show the solution; Increase the NUMBER  */
 {
   register int t, r;

   printf("\n\n SOLUTIONS %u\n\n", ++number);
   for (r = 0; r < QUEENS; r++) { /* queue */
     for (t = 1<<QUEENS-1; t > 0; t >>= 1)
       printf(" %c", board[r] == t ? 'Q' :  '.');
     printf("\n");
   }
 }

 void place (int queue)   /* place to next queue */
 {
   if (queue == QUEENS)     /* all queues are full and checked */
     writesol();
   else
     for (board[queue]=1; board[queue]<1<<QUEENS;  board[queue]<<=1)
       if (boardTamam(queue))
         place(queue+1);  /* try the next queue */
 }

 signed main (void)
 {
   clock_t t;
    t = clock();
   place(0);
   t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("\n\nThere is 92 diffirent solution for Queen Promlem \n\n");
  printf("Queen Promlem's took %f seconds to execute \n", time_taken);
  printf("\n The solution algorithm of this problem is LINEAR. \n\n\n");
  printf("\n\t Complexity  of the program : O(n) \n\n\n");
   return 0;
 }
