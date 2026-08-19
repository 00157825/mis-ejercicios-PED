#include <iostream>
#include<math.h>

using namespace std;

template<typename t1,typename t2>

auto max_number(t1 a, t2 b) -> decltype((a>b) ? a:b){
    return (a > b) ? a : b;
    }

int main(){

    cout<< max_number(3,7)<<endl;
    cout<<max_number(2.5,12)<<endl;
    cout<<max_number(2,1.2)<<endl;

    return 0;
}