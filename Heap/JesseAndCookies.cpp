#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    
    // enter values
    priority_queue <int,vector<int>,greater<int>> q;
    for (int i=0;i<n;i++) { 
        int x;
        cin >> x;
        q.push(x);
    }
    
    // process
    int count=0;
    while(true){
        int x;
        if ((x=q.top())<k) {
            q.pop(); // remove 1st
            if (q.empty()) { // nothing left, can't proceed
                cout << -1;
                break;
            }
            int y=2*q.top(); 
            q.pop(); // remove 2nd
            q.push(x+y); // create new
            count++; // completed 1 op
        }
        else {
            cout << count; // print ans
            break;
        }
    }
        
    return 0;
}
