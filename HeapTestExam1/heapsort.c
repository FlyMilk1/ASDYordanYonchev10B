//COMPLEXITY:
//O(n log n)
//Theta(n log n)
//Omega(n log n)
//Heap-ифицира масива като сменя i с левия или десния елемент, така че
//да спазва heap структурата
//После за всеки елемент в обратен ред извиква siftUp - сменя 1-вия и последен
//елемент и после влиза в цикъл, в който сменя родителя на най-големия десен или
//ляв елемент, ако не по-голям от тях, докато не се окаже, че е най-голям. Тогава
//той прекъсва цикъла и този елемент е на правилното си място
//След приключването на siftUp за всеки елемент, масивът е вече сортиран.
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int* arr, int count){
    for(int i=0; i<count; i++){
        printf("%d ", arr[i]);
    }
}
void heapify(int* arr, int count){
     for (int i = count / 2 - 1; i >= 0; i--) {
        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < count && arr[left] > arr[largest]){
                largest = left;
            }            
            if (right < count && arr[right] > arr[largest]){
                largest = right;
            }
                
            if (largest == i){
                break;
            }
                
            swap(&arr[i], &arr[largest]);
            i = largest;
        }
    }
}
void siftUp(int* arr, unsigned int pos) {
    unsigned int i = 0; 
    
    swap(&arr[0], &arr[pos]);

    while (1) {
        unsigned int left = 2 * i + 1;
        unsigned int right = 2 * i + 2;
        unsigned int largest = i;

        
        if (left < pos && arr[left] > arr[largest]){
            largest = left;
        }
        if (right < pos && arr[right] > arr[largest]){
            largest = right;
        }
        if (largest == i)
        break;

        
        swap(&arr[i], &arr[largest]);

        
        i = largest;
    }
}
void heapsort(int* arr, unsigned int count){
    heapify(arr, count);
    for(int i=count-1; i>=0; i--){
        siftUp(arr, i);
    }
}
int main(){
    int arr[] = {5, 24, 7, 2, 30, 17, 22 ,25};
    int count = 8;
    heapsort(arr, count);
    printArr(arr, count);
    return 0;
}