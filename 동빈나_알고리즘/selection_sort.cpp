#include <iostream>
#include <stdio.h>
using namespace std;

//선택정렬
//n^2 이라서 성능은 .. 별루 
int main()
{
    int i, j, min, index, temp;

    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    for (i = 0; i < 10; i++)
    {
        min = 9999;
        for (j = i; j < 10; j++)
        {
            if (min > array[j])
            { //최소값
                min = array[j];
                index = j;
            }
        }

        //작은값 맨 앞으로
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }

    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
}