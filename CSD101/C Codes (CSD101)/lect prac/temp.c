#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


#define SIZE 1000000
#define NOT_FOUND -1

typedef int ElementType;
typedef int Position;

Position binsearch_r(ElementType aCollection[], Position begin, Position end, ElementType element)
{
  if (end <= begin)
    return NOT_FOUND;

  Position mid = begin + ( (end - begin) / 2 ); // Assumes position to be 'int'

  if ( element < aCollection[mid] )
    return binsearch_r(aCollection, begin, mid, element);
  else if ( element > aCollection[mid] )
    return binsearch_r(aCollection, (mid+1), end, element);
  else
    return mid;
}

Position linsearch_r(ElementType aCollection[], Position begin, Position end, ElementType element)
{
  if (begin == end) return NOT_FOUND;
  if (element == aCollection[begin]) return begin;
  return linsearch_r(aCollection, (begin+1), end, element);
}


void populate(ElementType aCollection[], int size, int start, int end)
{
  assert(start < end);

  srand( time(NULL) ); //srand(time(NULL)); makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing.  Remember, if the seed number remains the same, the sequence of numbers will be repeated for each run of the program.
  int i;

  for(i=0; i < size; i++) {
    aCollection[i] = (rand() % (end - start)) + start; //In order to produce random integer numbers within a specified range,
  }

}

void print_array(ElementType aCollection[], int from, int to)
{
    int i;
  assert(from >= 0);
  assert(from < to);
  assert(to <= SIZE);

  printf("<");
  for (i=from; i < to; i++) {
    printf("%d; ", aCollection[i]);
  }
  printf(">\n");
}

int int_compare(const void * e1, const void * e2)
{
  int * ele1 = (int *) e1;
  int * ele2 = (int *) e2;

  if (*ele1 > *ele2)
    return 1;
  if (*ele1 < *ele2)
    return -1;
  return 0;
}


int main()
{
  ElementType myCollection[SIZE];
  ElementType key;
  Position pos;

  populate(myCollection, SIZE, 0, 1000);

  qsort(myCollection, SIZE, sizeof(int), int_compare);

  print_array(myCollection, 0, SIZE);

  while (1)
  {
    printf("Enter a key: ");
    scanf("%d", &key);

    if ( key < 0 ) break;

    clock_t start, end;
    double cpu_time;

    start = clock();
    pos = binsearch_r(myCollection, 0, SIZE, key);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    if ( pos == NOT_FOUND )
      printf("\nBinSearch took %f seconds to discover that the key is not found!\n", cpu_time);
    else
      printf("\nBinSearch found in %f seconds that the Key %d is at position %d!!!\n", cpu_time, key, pos);

    start = clock();
    pos = linsearch_r(myCollection, 0, SIZE, key);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    if ( pos == NOT_FOUND )
      printf("\nLinSearch took %f seconds to discover that the key is not found!\n", cpu_time);
    else
      printf("\nLinSearch found in %f seconds that the Key %d is at position %d!!!\n", cpu_time, key, pos);

  } // End of while loop

  return 0;
}