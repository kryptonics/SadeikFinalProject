#include "Encryption.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <random>
#include <ctime>

using namespace std;

int randomGen(int minimum,int maximum){
    return rand() % (minimum+maximum);
}

int main(){
    ifstream inFile;
    inFile.open("test.txt");
    if (inFile.good()){
            vector<char> text;
            //string read;

        while(!inFile.eof()){
            text.push_back(inFile.get());
            //read=inFile.get();
        }
        text.pop_back();
        if(text.size()%2==0){
            text.push_back('x');
        }
        for(int i = 0; i < text.size(); i++)
            cout<<text[i];
        cout<<endl;
        cout<<"Size "<<text.size()<<endl;
        /*
        for(int i=0;i<text.size();i++){
            cout<<text[i];
        }
        */
        //cout<<endl;
        //cout<<"text length: "<<text.size()<<endl;
        //cout<<endl;
        srand(time(0));
        int order=rand() % (1+3);
        //cout<<order<<endl;
        Encryption Crypton;

        /*
        int irf=randomGen(1,9);
        while(irf==0){
            irf=randomGen(1,9);
        }
        cout<<"irf: "<<irf<<endl;
        cout<<endl;

        vector<char> s1=Crypton.faro(text,irf);
        cout<<"s1 output"<<endl;
        for(int i=0;i<s1.size();i++){
            cout<<s1[i];
        }
        cout<<endl;
        cout<<"s1 length: "<<s1.size()<<endl;
        cout<<endl;

        vector<char> d1=Crypton.antiFaro(s1,irf);
        for(int i=0;i<d1.size();i++){
            cout<<d1[i];
        }
        cout<<endl;
        cout<<"d1 length: "<<d1.size()<<endl;
        cout<<endl;
        */


        int ir6=randomGen(2,6);
        cout<<"ir6: "<<ir6<<endl;
        cout<<endl;
        vector<char> s2=Crypton.sixPile(text,ir6);
        cout<<"s2 output"<<endl;
        for(int i=0;i<s2.size();i++){
            cout<<s2[i];
        }
        cout<<endl;
        cout<<"s2 length: "<<s2.size()<<endl;
        cout<<endl;

        vector<char> d2=Crypton.antiSixPile(s2,ir6);
        cout<<"d2 output"<<endl;
        for(int i=0;i<d2.size();i++){
            cout<<d2[i];
        }
        cout<<endl;
        cout<<"d2 length: "<<d2.size()<<endl;
    }else{
        cout<<"file failed to open, encryption operation aborted"<<endl;
    }
    return 0;
}


//This is a test of the encryption algorithm. Hopefully this will read in, split into chars, and then be successfully scrambled and subsiquently unscrambled.
