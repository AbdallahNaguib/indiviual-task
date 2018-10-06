#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    st:
    ifstream in("in.txt");

    string wanted;
    cin>>wanted;
    string str;
    int rank=0;
    while(getline(in,str)){
        rank++;
        bool ok=true;
        int spaceInd=-1;
        //I want to know the index of the first space
        for(int i=0 ; i<str.size() ; i++){
            if(str[i] == ' '){
                spaceInd=i;
                break;
            }
        }
        for(int i=0 ; i<wanted.size() ; i++){
            if(str[i+spaceInd+1] != wanted[i]){
                ok=false;
                break;
            }
        }
        if(ok && str[wanted.size()+spaceInd+1] == ' '){//we want to make sure that the boy's name ends after the wanted string
            cout<<wanted<< " is ranked "<<rank<<" in popularity among boys."<<endl;
            break;
        }
        //I want to know the index of the first space after the boy's name
        for(int i=spaceInd+1 ; i<str.size() ; i++){
            if(str[i] == ' '){
                spaceInd=i;
                break;
            }
        }
        ok=true;
        for(int i=0 ; i<wanted.size() ; i++){
            if(str[i+spaceInd+1] != wanted[i]){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<wanted<< " is ranked "<<rank<<" in popularity among girls."<<endl;
            break;
        }
    }
    goto st;
    return 0;
}
