#include<bits/stdc++.h>
using namespace std;

int knapsack(int capacity,int weight[],int values[],int n){
     
    vector<vector<int>> ans(n+1,vector<int>(capacity+1));

    for(int i=0;i<=n;++i){
        for(int j=0;j<=capacity;++j){
            if(i==0 || j==0){
                ans[i][j]=0;
            }
            else if(weight[i-1]<=j){
               ans[i][j]=max(values[i-1]+ans[i-1][j-weight[i-1]],ans[i-1][j]);
            }
            else{
                ans[i][j]=ans[i-1][j];
            }
        }
    }
    return ans[n][capacity];
}

int main(){
    
    int n=3;
    int weight[3]={1,2,3};
    int values[3]={10,15,40};
   
    int capacity=6;

    cout<<knapsack(capacity,weight,values,n)<<endl;
    return 0;
}