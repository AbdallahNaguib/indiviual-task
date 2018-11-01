#include <iostream>
#include <dominos.h>

using namespace std;
ostream& operator<<(ostream& out,dominos& d){
    out<<d.toString()<<endl;
    return out;
}
int main(){
    for(int i=0 ; i<=6 ; i++){
        for(int j=i ; j<=6 ; j++){
            dominos d(i,j);
            cout<<d<<endl;
        }
    }
}
