#include<iostream>
#include<algorithm>

using namespace std;

void Heapify(int *_array, int _offset, int _heapSize){
    	int leftNode, rightNode, largest, temp;
    	leftNode = 2 * _offset;
    	rightNode = 2 * _offset + 1;
    	
    	if (leftNode <= _heapSize && _array[leftNode] > _array[_offset])
    	{
    		largest = leftNode;
    	}
    	else
    	{
    		largest = _offset;
    	}
     
    	if (_array[rightNode] > _array[largest] && rightNode <= _heapSize)
    	{
    		largest = rightNode;
    	}
    	
    	if (largest != _offset)
    	{
    		temp = _array[_offset];
    		_array[_offset] = _array[largest];
    		_array[largest] = temp;
    		Heapify(_array, largest, _heapSize);
    	}
    }
void CreateHeap(int *_array, int _length){
    int offset, heapSize;
    heapSize = _length - 1;
     
    for (offset = (_length / 2); offset >= 0; offset--){
    		Heapify(_array, offset, heapSize);
    	}
}
    void HeapSort(int *_array, int _length)
    {
    	CreateHeap(_array, _length);
     
    	int heapSize, offset, temp;
    	heapSize = _length - 1;
    	
    	for (offset = heapSize; offset >= 0; offset--)
    	{
    		temp = _array[0];
    		_array[0] = _array[heapSize];
    		_array[heapSize] = temp;
     
    		heapSize--;
     
    		Heapify(_array, 0, heapSize);
    	}
    }



int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    int k[n];
    for(int i=0;i<n;i++){
        cin >>k[i];
    }
    HeapSort(k,n);
    

    for(int i=0;i<n;i++){
        cout <<k[i]<<" ";
    }


    return 0;
}