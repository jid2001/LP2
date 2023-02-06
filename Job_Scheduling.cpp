#include<bits/stdc++.h>

using namespace std;


struct Job{
    char id;
    int deadline;
    int profit;
};

bool cmp(Job & j1,Job & j2 ){
    return j1.profit > j2.profit;
}

void scheduling(int n, vector<Job> vjb){
    vector<char> seq(n+1,'-');
    int mx_profit =0;
    sort(vjb.begin(),vjb.end(),cmp);

    for(auto it : vjb){
        if(seq[it.deadline] == '-'){
            seq[it.deadline] = it.id;
            mx_profit += it.profit;
        }
        else{
            for(int i = it.deadline; i>0; i--){
                if(seq[i] == '-'){
                    seq[i] = it.id;
                     mx_profit += it.profit;

                    break;
                }
            }
        }

    }
    cout << " Job Sequence : ";
    for(int i =1; i<= n; i++){
        if(seq[i] != '-'){
            cout << seq[i] <<" ";
        }
    }
    cout <<endl;
    cout << "Max Profit is : " << mx_profit<<endl;
    

}
int main(){

   int n;
   cout << " Enter no of Jobs : ";
   cin >>n;
vector<Job> vjb(n);
for(int i =0; i<n; i++){
    cout << "Enter job id, Deadline, Profit  : ";
    cin>> vjb[i].id>>vjb[i].deadline  >> vjb[i].profit;
    cout <<endl;
}
// sort(vjb.begin(),vjb.end(),cmp);
// for(int i =0 ; i<n; i++){
//     cout << vjb[i].id << " "<< vjb[i].deadline << " "<< vjb[i].profit<<endl;
// }

scheduling(n,vjb);
    return 0;

}