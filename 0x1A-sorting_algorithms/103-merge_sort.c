#include "sort.h"

/**
 * print_stuff - prints some stuff
 * @piLeftArray - left array
 * @piRightArray - right array
 * @piLeftEnd - end of left array
 * @piRightEnd - end of right array
 */
void print_stuff(int *piLeftArray, int *piRightArray, int *piLeftEnd, int *piRightEnd)
{
        printf("Merging...\n[left]: %d", *piLeftArray);
        piLeftArray++;
        while (piLeftArray <= piLeftEnd)
        {
                printf(", %d", *piLeftArray);
                piLeftArray++;
        }
        printf("\n[right]: %d", *piRightArray);
        piRightArray++;
        while (piRightArray <= piRightEnd)
        {
                printf(", %d", *piRightArray);
                piRightArray++;
        }
}

/**
 * transfers end result from buffer to array
 * @piBuffer: buffer
 * @piArray: original array
 * @piArrayEnd: pointer to end of piArray
 */
void buffer_to_array(int *piBuffer, int *piArray, int *piArrayEnd)
{
        printf("\n[Done]: %d", *piBuffer);

        while (piArray < piArrayEnd)
        {
                *piArray = *piBuffer;
                piArray++;
                piBuffer++;
                printf(", %d", *piBuffer);
        }
        *piArray = *piBuffer;
        printf("\n");
}

/**
 * merge - does the recursion an sorting
 * @piLeftArray: array to be sorted
 * @iSize: size of piLeftArray
 */
void merge(int *piLeftArray, size_t iSize)
{
        int *piLeftEnd = piLeftArray + (iSize / 2 - 1);
        int *piRightEnd = piLeftArray + (iSize - 1);
        int *piRightArray = piLeftEnd + 1;
        int *piLeftIter = piLeftArray;
        int *piRightIter = piRightArray;
        int *piBuffer;
        int *piBufIter;

        if (iSize < 2)
        {
                return;
        }

        merge(piLeftArray, iSize / 2);
        merge(piRightArray, (iSize + 1) / 2);

        print_stuff(piLeftArray, piRightArray, piLeftEnd, piRightEnd);

        piBuffer = malloc(sizeof(int) * iSize);
        if (piBuffer == NULL)
        {
                return;
        }

        piBufIter = piBuffer;

        while (piLeftIter != NULL || piRightIter != NULL)
        {
                if (piLeftIter != NULL &&
                    (piRightIter == NULL || *piLeftIter < *piRightIter))
                {
                        *piBufIter = *piLeftIter;
                        piBufIter++;
                        if (piLeftIter == piLeftEnd)
                        {
                                piLeftIter = NULL;
                                continue;
                        }
                        piLeftIter++;
                }
                else
                {
                        *piBufIter = *piRightIter;
                        piBufIter++;
                        if (piRightIter == piRightEnd)
                        {
                                piRightIter = NULL;
                                continue;
                        }
                        piRightIter++;
                }
        }

        buffer_to_array(piBuffer, piLeftArray, piRightEnd);

        free(piBuffer);
}

/**
 * merge_sort - sorts by recursivly splitting lists into small lists and merging those
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
        {
                return;
        }

        merge(array, size);
}
