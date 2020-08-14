#include <bits/stdc++.h>
using namespace std;

#define MAX 500

int multiply(int result[],int result_size,int x){
    //result = result * x
    int carry = 0;
    for(int i = 0 ; i < result_size; i++){
        int mul = result[i]*x + carry ;
        result[i] = mul%10;
        carry = mul/10;
    }
    while(carry){
        result[result_size++] = carry%10;
        carry = carry/10;
    }
    return result_size;

}

void extraLongFactorials(int n) {
    int result[MAX];
    result[0] = 1 ;
    int result_size = 1 ;
    for(int i = 2 ; i <= n ; i++){
        result_size = multiply(result,result_size,i);
    }
    for(int i = result_size-1; i>=0; i--)
    {
        cout << result[i];
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
