 #include <bits/stdc++.h>

using namespace std;

/*
 * Complete the minimumAverage function below.
 */
struct Compare { bool operator()(vector<int> const & a, vector<int> const & b) { return a[1] > b[1]; } };

long long minimumAverage(vector<vector<int>> customers) {
    long long n = customers.size();
    //sort customers in arrival time
    sort(customers.begin(),customers.end());
    
    priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
    pq.push(customers[0]);
     long long t = customers[0][0];
     long long awt = 0;
    int i = 1;
    while(!pq.empty()){
        vector<int> currCus = pq.top();
        pq.pop();
        t += currCus[1];
        while(i < n &&  customers[i][0] <= t){
            pq.push(customers[i]);
            ++i;       
        }
        awt += (t - currCus[0]);
        
        if(pq.empty() && i < n){
            pq.push(customers[i]);
            ++i;
        }
        
    }
    lldiv_t result1 = div(awt, n);
    return (result1.quot);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> customers(n);
    for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++) {
        customers[customers_row_itr].resize(2);

        for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++) {
            cin >> customers[customers_row_itr][customers_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}


