#include <iostream>

using namespace std;

void Max_Heapify(int *data, int root, int len){
    //              5(root)
    // 10(largest)               3

    //              10(root)
    // 5(largest)               3
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int largest = root;

    if(left < len && data[left] > data[largest]){
        largest = left;
    }

    if(right < len && data[right] > data[largest]){
        largest = right;
    }

    if(largest != root){
        // Swap data[root] and data[largest]
        int tmp = data[root];
        data[root] = data[largest];
        data[largest] = tmp;
        Max_Heapify(data, largest, len);
    }
}

void Min_Heapify(int *data, int root, int len){
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int smallest = root;

    if(left < len && data[left] < data[smallest]){
        smallest = left;
    }

    if(right < len && data[right] < data[smallest]){
        smallest = right;
    }

    if(smallest != root){
        // Swap data[root] and data[smallest]
        int tmp = data[root];
        data[root] = data[smallest];
        data[smallest] = tmp;
        Min_Heapify(data, smallest, len);
    }
}

void Build_Max_Heap(int *data, int len){
    for(int i=len/2-1;i>=0;i--){
        Max_Heapify(data, i, len);
    }
}

void Build_Min_Heap(int *data, int len){
    for(int i=len/2-1;i>=0;i--){
        Min_Heapify(data, i, len);
    }
}

void Print_Array(int *data, int len){
    cout << "Array: ";
    for(int i=0;i<len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void Heap_Sort(int *data, int len){
    // Step 1: Make max heap
    Build_Max_Heap(data, len);

    for(int i=len-1;i>0;i--){
        // Step 2: Swap data[i] and data[0]
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        // Step 3: Max heapify again
        Max_Heapify(data, 0, i);
    }
}

int main()
{
    int data[] = {15,18,6,25,8,11,34,20,2,38};
    cout << "Before Heapify...." << endl;
    Print_Array(data, 10);
    cout << "After Max-Heapify...." << endl;
    Build_Max_Heap(data, 10);
    Print_Array(data, 10);
    cout << "After Min-Heapify...." << endl;
    Build_Min_Heap(data, 10);
    Print_Array(data, 10);

    cout << "After Heap Sort...." << endl;
    Heap_Sort(data, 10);
    Print_Array(data, 10);

    return 0;
}
