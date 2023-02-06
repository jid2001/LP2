#include<bits/stdc++.h>

using namespace std;

void selection_sort(int n, vector<int> & arr){

    for(int i = 0; i<n-1; i++){
        int mn_ind = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << " Sorted Array : ";
    for(auto x : arr){
        cout << x << " ";
    }
    cout <<endl;
}

int main(){
    int n;
    cout << "Enter the  no of Element : ";
    cin>>n;

    vector<int> arr(n,0);
    for(int i =0; i<n; i++){
        cout <<" Enter element "<<i+1 << " :";
        cin>>arr[i];
    }


    selection_sort(n,arr);
    return 0;
}