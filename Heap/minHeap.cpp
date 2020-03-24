/*
        HACKERRANK QUESTION : QHEAP1
*/
#include<bits/stdc++.h>
using namespace std;

class heap{
    int *arr;
    int size;
    int heap_ind;
    public:
      heap(int s){
        size = s;
        arr = new int[s];
        heap_ind = 0;
      }
      int getParentIndex(int i){
        return ((i-1)/2);
      }
      int getLeftChildIndex(int i){
        return (i*2+1);
      }
      int getRightChildIndex(int i){
        return (i*2+2);
      }
      void swap(int i1,int i2){
        int temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
      }   
      bool hasLeftChild(int ind){
        if(getLeftChildIndex(ind) < heap_ind){
          return true;
        }
        return false;
      }
      bool hasRightChild(int ind){
        if(getRightChildIndex(ind) < heap_ind){
          return true;
        }
        return false;
      }
      bool hasParent(int ind){
        if(getParentIndex(ind) >= 0){
          return true;
        }
        return false;
      }
      void HeapifyUp(int ind);
      void HeapifyDown();
      bool insert(int data);
      int getMinEle();
      bool removeTop();
      bool deleteElement(int data);
      bool deleteElementAtIndex(int index);
      void printHeap();
};

int heap::getMinEle(){
  if(heap_ind == 0){
    return -1;
  }
  return arr[0];
}

bool heap::removeTop(){
  if(heap_ind == 0){
    return  false;
  }
  arr[0] = arr[heap_ind-1];
  //cout <<  "remove :" << arr[0] << "\n";
  heap_ind--;
  HeapifyDown();
  return true;
}

bool heap::insert(int data){
   if(heap_ind > size){ 
      return false;
   }
   arr[heap_ind] = data;
   HeapifyUp(heap_ind);
   heap_ind++;
    return true;
}

void heap::HeapifyUp(int ind){
  int index = ind ;
  while(hasParent(index) && arr[getParentIndex(index)] > arr[index]){
    swap(getParentIndex(index),index);
    index = getParentIndex(index);
  }
}

void heap::HeapifyDown(){
  int index = 0;
  
  while(hasLeftChild(index) ){
    int small = getLeftChildIndex(index);
    if(hasRightChild(index) && arr[small] > arr[getRightChildIndex(index)]){
        small = getRightChildIndex(index);  
    }
    if(arr[index] > arr[small]){
      swap(small,index); 
    }else{
      break;
    }
    index = small;
   // cout << "small : " << index << "\n";
   // printHeap();
  }
    
}

bool heap::deleteElementAtIndex(int index){
  if(index < heap_ind){
    arr[index] = INT_MIN;
    HeapifyUp(index);
    return removeTop();
  }
  return false;
}

bool heap::deleteElement(int data){
    for(int i = 0; i < heap_ind ; i++){
      if(arr[i] == data){
        if(i == 0){
            return removeTop();
        }else{
            return deleteElementAtIndex(i);
        }
      }
    }
    return false;
}

void heap::printHeap(){
    cout << "heap :" ;
    for(int i = 0 ;i < heap_ind ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int q;
    cin >> q;
    heap h(q);
    int q1,q2;
    while(q--){
        cin >> q1;
        if(q1 == 3){
            cout  <<  h.getMinEle() << "\n";
        }else{
            cin >> q2;
            if(q1 == 1){
                h.insert(q2);
            }else{
                 h.deleteElement(q2) ;
            }
        }
        //h.printHeap();
    }
}
