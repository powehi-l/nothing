/* ************************************************************************
> File Name:     24get.c
> Author:        Guo
> Created Time:  2023年01月16日 星期一 10时37分44秒
> Description:   
 ************************************************************************/
#define in(x) ((x) <= 10 && (x) >= 1)
#include<iostream>
#include<algorithm>

using namespace std;
void output(int arr[], int sign[], int num, int first);
int do_operation(int arr[], int sign[], int num, int i);
int main(){
    int arr[4];
    int sign[3];
    printf("please input the 4 numbers: \n");
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    if(!in(arr[0]) || !in(arr[1]) || !in(arr[2]) || !in(arr[3])){
        printf("number is not bewteen 1 and 10\n");
        return -1;
    }
    for(int q = 0; q <= 23; q++){
//       cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl; 
       for(int i = 0; i <= 3; i++){
           sign[0] = i;
           for(int j = 0; j <= 3; j++){
               sign[1] = j;
               for(int k = 0; k <= 3; k++){
                   sign[2] = k;
                   for(int l = 0; l <= 2; l++)
                        if(do_operation(arr, sign, 3, l))
                            output(arr, sign, 3, l);
               }
           }
       }
       next_permutation(arr, arr+4);
    }
    cin >> arr[0];
}

void output(int arr[], int sign[], int num, int first){
    for(int i = 0; i <= num; i++){
        if(i == first)
            cout << "(";
        if(i == num){
            if(i == first+1)
                cout << arr[i] << ")";
            else
                cout << arr[i];
        
        }
        else{
            if(i == first + 1){
                 switch(sign[i]){
                 case 0: cout << arr[i] << ")" << " " << "+"<< " ";break;
                 case 1: cout << arr[i] << ")" << " " << "*" << " ";break;
                 case 2: cout << arr[i] << ")" << " " << "-" << " ";break;
                 case 3: cout << arr[i] << ")" << " " << "/" << " ";break;
                 }

            }
            else
                switch(sign[i]){
                 case 0: cout << arr[i] << " " << "+"<< " ";break;
                 case 1: cout << arr[i] << " " << "*" << " ";break;
                 case 2: cout << arr[i] << " " << "-" << " ";break;
                 case 3: cout << arr[i] << " " << "/" << " ";break;
                }
        }
    }
    cout << endl;
}
int do_operation(int arr[], int sign[], int num, int i){
    int new_arr[num], new_sign[num-1];
    int temp;
        switch(sign[i]){
            case 0: temp = arr[i] + arr[i+1];break;
            case 1: temp = arr[i] * arr[i+1];break;
            case 2: temp = arr[i] - arr[i+1];break;
            case 3:
                    if(arr[i+1] == 0 || arr[i] % arr[i+1] != 0)
                        return 0;
                    temp = arr[i] / arr[i+1];break;
        }
        if(num == 1){
            if(temp == 24)
                return 1;
            else
                return 0;
        }
        for(int j = 0; j < i; j++){
            new_arr[j] = arr[j];
            new_sign[j] = sign[j];
        }
        new_arr[i] = temp;
        for(int j = i+1; j < num; j++){
            new_arr[j] = arr[j+1];
            new_sign[j-1] = sign[j];
        }
        for(int j = 0; j < num-1; j++)
            return do_operation(new_arr, new_sign, num-1, j);
}
