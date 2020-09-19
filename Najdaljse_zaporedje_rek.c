#include <stdio.h>
// ne e zapocnata
static int stevec = 0;
int funkcija(int arr[], int n, int dat[], int ind, int i){
    if(ind == k){
        if(max == (presmetka(dat, k)))
            stevec++;
            return;
    }
    if(i >= n)
        return;
    dat[ind] = arr[i];
    if(arr[i+1])
    funkcija(arr, n, dat, ind+1, k, max, i+1);
    funkcija(arr, n, dat, ind, k, max, i+1);
    return stevec;
}
int glavna(int arr[], int n, int k, int max){
    int dat[k];
    funkcija(arr, n, dat, 0, k, max, 0);
}
int presmetka(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int k, n;
    scanf("%d", &n);
    scanf("%d", &k);
    int max;
    scanf("%d", &max);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", glavna(arr, n, k, max));
}