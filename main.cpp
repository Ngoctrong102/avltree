#include<iostream>
#include"avltree.cpp"

using namespace std;

int main(){
    int arr[] = {1,3,4,6,8,23,5,45,57,24,56,88,123};
    avltree<int> tui;
    for (int i=0;i<13;i++){
        tui.insert(arr[i]);
    }
    tui.print("pre");
    return 0;
}
