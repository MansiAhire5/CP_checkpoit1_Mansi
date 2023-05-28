#include<iostream>
int main(){
    int n; std::cin>>n;
    long long int arr[n];
    for(int j=0; j<n;j++){
        std::cin>>arr[j];}
    long long int sum[n];
    for(int j=0; j<n;j++){
    sum[j] = arr[j]*arr[j]+ 2*arr[j]+2;
        std::cout<<sum[j]<<std::endl;}
    return 0;}
