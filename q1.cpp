#include<bits/stdc++.h>
using namespace std;

string lcs(string s1,string s2){
    int len1=s1.length();
    int len2=s2.length();

    vector<vector<int>> dp(len1+1,vector<int> (len2+1,0));

    for(int i=1;i<=len1;++i)
    {
        for(int j=1;j<=len2;++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string ans;

    int i=len1;
    int j=len2;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            --i;
            --j;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
             --i;
        }
        else{
            --j;
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;


}
int main(){

    string s1,s2;
    cin>>s1>>s2;

    cout<<"LCS of s1 and s2 "<<lcs(s1,s2)<<endl;

    
    return 0;
}