#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp;
    double median=0.0;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    cin >> n;
    for(int i = 0 ;i < n ; i++){
        cin >> temp;
        if(temp <= median){
            maxHeap.push(temp);
        }else{
            minHeap.push(temp);
        }
        int size1 = maxHeap.size();
        int size2 = minHeap.size();
        if(size2 > size1+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if(size1 > size2+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        size1 = maxHeap.size();
        size2 = minHeap.size();
        if(size1 == size2){
            median = (double)(maxHeap.top()+minHeap.top())/2.0;
        }
        else if(size1 > size2){
            median = (double)maxHeap.top();
        }else{
            median = (double)minHeap.top();
        }
        cout << median << "\n";
    }

}
