
#include <stdio.h>


int findSplit(int a[], int aSize) {
    int x=0, y=0;
    for (int i=0; i < aSize; i++) {
        x+=a[i];
    }
    for (int j = 0; j < aSize; j++)
    {
        y+=a[j];
        if (y==x-y)
        {
            return j;
        }
    }
    return -1;
}
    
int main() {
    int numbers[] = {12, 2,5, 3,8,2,6};
    int index = findSplit(numbers, 7);
    
    if (index == -1)
         printf("not possible");
    else 
        printf("Split at index %2i", index);

    return 0;
}
