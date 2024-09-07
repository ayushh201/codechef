#include <bits/stdc++.h>
using namespace std;

void add(int &subset,int x){
    subset=(subset^(1<<(x-1)));
}
void remov(int &subset,int x){
    subset=(subset^(1<<(x-1)));
}
void display(int subset){
    for(int bit_no=0;bit_no<=10;bit_no++){
        if(subset&(1<<bit_no)){
            cout<<bit_no+1<<" ";
        }
    } 
}
int main()
{
    int set=15;
    remov(set,2);
    add(set,5);
    add(set,7);
    display(set);
    return 0;
}
