#include <stdio.h>
#include <stdbool.h>
bool jePrashtevilo(int n){
    bool je = false;
    int stevec = 0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            stevec++;
        }
    }
    if(stevec==2) je = true;
    return je;
}
int main(){
    bool jeSodo = false;
    for(int i=1; i<=1000; i++){
        if(i%2==0) jeSodo = true;
        if(jePrashtevilo(i)){
        for(int j=i; j<1000; j++){
            if(jeSodo && jePrashtevilo(j)){
                printf("(%d, %d)\n", i, j);
            }
            else{
                if(j%2==0 && jePrashtevilo(j)){
                    printf("(%d, %d)\n", i, j);
                }
            }
        }
        }
    }
}