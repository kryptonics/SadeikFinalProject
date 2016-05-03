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

int randomGen(int minimum,int maximum);
vector<string> makeCipher(vector<char> e2,string cipher);
void printResults(vector<string> done, string fileName);
vector<string> converter(vector<char> s2,vector<string> gibberishator,string cipher);
vector<char> backConverter(vector<char> crypted,vector<string> gibberish,string cipher);

int main(){
        string source{"`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./`!1@0#2$9%3^8&4*7(5)6_X+K~W[A]Z\M{T}|;=:<>?,./"};
        vector<char> entropy;

        for(int i=0;i<source.size();i++){
            entropy.push_back(source[i]);
        }

        bool cont=true;
        while(cont==true){
            int choice;
            cout<<"======Welcome to Crypton======"<<endl;
            cout<<"please select an option"<<endl;
            cout<<"1. Encrypt a text file with new key"<<endl;
            cout<<"2. Encrypt a text file with specified key"<<endl;
            cout<<"3. Decrypt a text file"<<endl;
            cout<<"4. Quit"<<endl;
            cin>>choice;
            if(choice==1){
                cout<<"Please enter the file name of the text file you want to encrypt."<<endl;
                cin.ignore();
                string fileName;
                getline(cin,fileName);
                ifstream inFile;
                inFile.open(fileName);
                if (inFile.good()){
                    vector<char> text;

                    while(!inFile.eof()){
                        text.push_back(inFile.get());
                    }
                    text.pop_back();
                    if(text.size()%2==0){
                        text.push_back('~');
                    }
                    Encryption Crypton;
                    srand(time(0));
                    int orderM=randomGen(1,2);
                    while(orderM==0){
                    orderM=randomGen(1,2);
                    }
                    Crypton.constructKey(orderM);
                    int orderE=randomGen(1,2);
                    while(orderE==0){
                    orderE=randomGen(1,2);
                    }
                    Crypton.constructKey(orderE);

                    int irfM=randomGen(1,9);
                    while(irfM==0){
                    irfM=randomGen(1,9);
                    }
                    Crypton.constructKey(irfM);
                    int irfE=randomGen(1,9);
                    while(irfE==0){
                    irfE=randomGen(1,9);
                    }
                    Crypton.constructKey(irfE);

                    int ir6M=randomGen(2,6);
                    Crypton.constructKey(ir6M);
                    int ir6E=randomGen(2,6);
                    while(ir6E!=6 and ir6E!=7){
                        ir6E=randomGen(2,6);
                    }
                    Crypton.constructKey(ir6E);
                    vector<char> s1;
                    vector<char> s2;
                    if(orderM==1){
                        s1=Crypton.faro(text,irfM);
                        s2=Crypton.sixPile(s1,ir6M);
                    }else if(orderM==2){
                        s1=Crypton.sixPile(text,ir6M);
                        s2=Crypton.faro(s1,irfM);
                    }
                    vector<char> e1;
                    vector<char> e2;
                    if(orderE==1){
                        e1=Crypton.sixPile(entropy,ir6E);
                        e2=Crypton.faro(e1,irfE);
                    }else if(orderE==2){
                        e1=Crypton.faro(entropy,irfE);
                        e2=Crypton.sixPile(e1,ir6E);
                    }
                    string cipher={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+;:,./<>?[]|{} "};
                    vector<string> gibberishator=makeCipher(e2,cipher);
                    vector<string> done=converter(s2,gibberishator,cipher);
                    cout<<"Your encryption key is: ";
                    Crypton.printKey();
                    printResults(done, fileName);

                }
                else
                    cout << "File failed to open" << endl;
            }else if(choice==2){
                cout<<"Please enter the file name of the text file you want to encrypt."<<endl;
                cin.ignore();
                string fileName2;
                getline(cin,fileName2);
                ifstream inFile2;
                inFile2.open(fileName2);
                if (inFile2.good()){
                    vector<char> text2;

                    while(!inFile2.eof()){
                        text2.push_back(inFile2.get());
                    }
                    text2.pop_back();
                    if(text2.size()%2==0){
                        text2.push_back('x');
                    }
                    cout<<"Please enter the 6 digit key you wish to use to encrypt this text."<<endl;
                    Encryption Krypton;
                    string number;
                    getline(cin,number);
                    cout<<"number: "<<number<<endl;
                    int keyArr[6];
                    for(int i=0;i<6;i++){
                        int convert=number[i]-48;
                        //cout<<convert<<endl;
                        keyArr[i]=convert;
                    }

                    vector<char> ss1;
                    vector<char> ss2;
                    if(keyArr[0]==1){
                        ss1=Krypton.faro(text2,keyArr[2]);
                        ss2=Krypton.sixPile(ss1,keyArr[4]);
                    }else if(keyArr[0]==2){
                        ss1=Krypton.sixPile(text2,keyArr[4]);
                        ss2=Krypton.faro(ss1,keyArr[2]);
                    }
                    vector<char> ee1;
                    vector<char> ee2;
                    if(keyArr[1]==1){
                        ee1=Krypton.sixPile(entropy,keyArr[5]);
                        ee2=Krypton.faro(ee1,keyArr[3]);
                    }else if(keyArr[1]==2){
                        ee1=Krypton.faro(entropy,keyArr[3]);
                        ee2=Krypton.sixPile(ee1,keyArr[5]);
                    }

                    string cipher2={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+;:,./<>?[]|{} "};
                    vector<string> gibberishatorx=makeCipher(ee2,cipher2);
                    vector<string> done2=converter(ss2,gibberishatorx,cipher2);
                    printResults(done2, fileName2);
                    cout << "Done with this" << endl;
                }else{
                    cout<<"File failed to open."<<endl;
                }

            }else if(choice==3){
                cout<<"Please enter the file name of the text file you want to decrypt."<<endl;
                cin.ignore();
                string fileName3;
                getline(cin,fileName3);
                ifstream inFile3;
                inFile3.open(fileName3);
                if (inFile3.good()){
                    vector<char> text3;

                    while(!inFile3.eof()){
                        text3.push_back(inFile3.get());
                    }
                    text3.pop_back();
                    Encryption kryptonite;
                    cout<<"Enter encryption key: ";
                    string keyChain;
                    getline(cin,keyChain);
                    int arrKey[6];
                    for(int i=0;i<6;i++){
                        int c=keyChain[i]-48;
                        arrKey[i]=c;
                    }
                    vector<char> de1;
                    vector<char> de2;
                    if(arrKey[1]==1){
                        de1=kryptonite.sixPile(entropy,arrKey[5]);
                        de2=kryptonite.faro(de1,arrKey[3]);
                    }else if(arrKey[1]==2){
                        de1=kryptonite.faro(entropy,arrKey[3]);
                        de2=kryptonite.sixPile(de1,arrKey[5]);
                    }
                    cout<<endl;
                    string cipher3={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+;:,./<>?[]|{} "};
                    vector<string> gibber=makeCipher(de2,cipher3);
                    vector<char> trans=backConverter(text3,gibber,cipher3);

                    vector<char> ds1;
                    vector<char> ds2;
                    if(arrKey[0]==1){
                        ds1=kryptonite.antiSixPile(trans,arrKey[4]);
                        ds2=kryptonite.antiFaro(ds1,arrKey[2]);
                    }else if(arrKey[0]==2){
                        ds1=kryptonite.antiFaro(trans,arrKey[2]);
                        ds2=kryptonite.antiSixPile(ds1,arrKey[4]);
                    }
                    cout<<"Decrypted output:"<<endl;
                    for(int i=0;i<ds2.size();i++){
                        cout<<ds2[i];
                    }
                    cout<<endl;
            }else{
            cout<<"File failed to open."<<endl;
            }
            }else if(choice==4){
                cout<<"Goodbye!"<<endl;
                cont=false;
                break;
            }else{
                cout<<"please enter the number associated with on or the menu option"<<endl;
            }
        }

    return 0;
    }

vector<string> makeCipher(vector<char> e2,string cipher){
    vector<string> gib;
    int entropyCount=1;
    for(int i=0;i<92;i++){
        string codon={e2[entropyCount],e2[entropyCount+1],e2[entropyCount+2]};
        if(!gib.empty()){
                bool unique=true;
            for(int j=0;j<gib.size();j++){
                if (codon==gib[j]){
                    unique=false;
                }
            }
            if(unique==true){
                gib.push_back(codon);
            }
        }else{
            gib.push_back(codon);
        }
        entropyCount=entropyCount+3;
    }
    return gib;
}

int randomGen(int minimum,int maximum){
    return rand() % (minimum+maximum);
}

vector<string> converter(vector<char> s2,vector<string> gibberishator,string cipher){
    vector<string> done;
    for(int i=0;i<s2.size();i++){
        for(int j=0;j<cipher.size();j++){
            if(s2[i]==cipher[j]){
                done.push_back(gibberishator[j]);
            }
        }
    }
    return done;
}

vector<char> backConverter(vector<char> crypted,vector<string> gibberish,string cipher){
    vector<string> groupings;
    for(int i=0;i<crypted.size();i=i+3){
        string codon={crypted[i],crypted[i+1],crypted[i+2]};
        groupings.push_back(codon);
    }
    vector<char> translated;
    for(int x=0;x<groupings.size();x++){
        for(int y=0;y<gibberish.size();y++){
            if(groupings[x]==gibberish[y]){
                translated.push_back(cipher[y]);
            }
        }
    }
    return translated;
}


void printResults(vector<string> done, string fileName){
    cout<<"Here is the encrypted version of your text."<<endl;
    for(int i=0;i<done.size();i++){
        cout<<done[i];
    }
    cout<<endl;
    cout<< "Writing this message to a new text file.." << endl;
    ofstream outFile;
    int periodIndex = fileName.find('.');
    string encFileName = fileName.substr(0, periodIndex) + "-enc.txt";
    outFile.open(encFileName);
    if(outFile.good()){
        for(int i=0;i<done.size();i++){
            outFile<<done[i];
        }
        cout << "Finished writing the encrypted message to the file \"" << encFileName << "\"" << endl;
        outFile.close();
    }
    else
    {
        cout << "Output file failed to open.." << endl;
    }
}
