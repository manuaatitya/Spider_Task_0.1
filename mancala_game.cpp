/*

# Author       : Manu Aatitya R P

# Language     : C++

# Mancala Game Codeforces-Problem Statement 975b

# Spider Task 0.1


*/

#include<bits/stdc++.h>
 
using namespace std;
 
long long input_array[14];                  //Variable to store input
long long copy_array[14];                   //Variable to copy input
 
int main()
{
    for(int i=0;i<14;++i)                       //To Get Input from User 
        cin>>input_array[i];
 
    long long ans = 0;                      //Final Answer Variable
 
    for(int i=0;i<14;++i){
        for(int j=0;j<14;++j)               //To make a copy of input array
            copy_array[j] = input_array[j];
        long long temp = copy_array[i];     //Storing current array value in a 
                                            // temporary variable
                                            
        copy_array[i] = 0;                  //Setting current array value to zero
        
        for(int j=0;j<14;++j)               //Since after 14 holes the array value
                                            // gets incremented the value incremented 
                                            // is array value/14
            copy_array[j] += temp/14;
            
        temp %= 14;                         //To look for the values during single 
                                            // iteration
        int k = i+1;
        while(temp--){                      //Incrementing array values in single 
                                            // loop other than repetition
            copy_array[k++%14]++;
        }
        long long even = 0;                 //Variable to store sum of even values
        for(int j=0;j<14;++j){
            if(copy_array[j] & 1)           // To check if number is odd
                continue;
            even += copy_array[j];          // Sum of even values
        }
        ans = max(ans,even);                // Ans is the maximum of all sum of even
                                            //values
    }
 
    cout<<ans;
 
 
    return 0;
}