#include <stdio.h>
#include <stdbool.h>
bool jePopolnoStevilo(int n){
    bool je = false;
    int sum = 0;
    for(int i=1; i<n; i++){
        if(n%i==0){
            sum = sum + i;
        }
    }
    if(sum==n) je = true;
    return je;
}
int main(){
    for(int i=1; i<=1000; i++){
        if(jePopolnoStevilo(i)){
            printf("%d\n", i);
        }
    }
}