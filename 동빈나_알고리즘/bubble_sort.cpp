#include <stdio.h>

//  옆에 있는 값과 비교해서 더 작은값 앞으로 보내기
//젤 구림 효올셩 n^2
// 자리를 계속 바꿔서 연산 비싸다 수행시간 느리다 

int main()
{
    // 1vs10 10vs5 -> 이렇게 진행
    //한번 반복 끝날때 가장 큰값이 맨 뒤로 간다 --
    int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int i, j, temp,index ;
    for ( i = 0; i < 10; i++)
    {
        for(j=0; j< 9-i; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1] ;
                array[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i< 10; i++){
        printf("%d ", array[i]);
    }

    return 0;

}