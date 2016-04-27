#include "Encryption.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <array>
using namespace std;

Encryption::Encryption()
{
    //ctor
}

Encryption::~Encryption()
{
    //dtor
}

int Encryption::randGen(int minimum,int maximum){
    return rand() % (maximum+minimum);
}

vector<int> Encryption::getKey(){
    return key;
}

int Encryption::conversion(string number){
    int num=stoi(number);
    return num;
}

void Encryption::setKey(int keyElem,int index){
    key[index]=keyElem;
}

vector<char> Encryption::faro(vector<char> message,int reps){
    vector<char> scrambled=message;
    int sizer=scrambled.size();
    int repCount=0;
    while(repCount!=reps){
        char mixer[sizer];
        int counter=0;
        int marker;

        for(int i=0;i<(int)scrambled.size()/2;i++){
            mixer[counter]=scrambled[i];
            marker=i;
            counter=counter+2;
        }
        if(scrambled.size() % 2!=0){
            mixer[counter] = scrambled[marker+1];
        }

        int opCounter=1;
        for(int i=marker+2;i<scrambled.size();i++){
            mixer[opCounter]=scrambled[i];
            opCounter=opCounter+2;
        }

        vector<char> loader={};

        for(int i=0;i<scrambled.size();i++){
            loader.push_back(mixer[i]);
        }
        scrambled=loader;
        repCount++;
    }
    return scrambled;
}

vector<char> Encryption::antiFaro(vector<char> scrambled,int reps){
    int repCount=0;
    vector<char> deScramble=scrambled;

    while(repCount!=reps){
        char holder[deScramble.size()];
        int counter=0;
        int marker;
        for(int i=0;i<deScramble.size();i=i+2){
            holder[counter]=deScramble[i];
            counter++;
            marker=i;
        }if(deScramble.size() % 2!=0){
            holder[counter+1]=deScramble[marker+2];
        }else{
        counter=counter+2;
        }
        for(int i=1;i<deScramble.size();i=i+2){
            holder[counter]=deScramble[i];
            counter++;
        }
        vector<char> loader;
        for(int i=0;i<deScramble.size();i++){
            loader.push_back(holder[i]);
        }
        deScramble=loader;
        repCount++;
        }
        return deScramble;
}

vector<char> Encryption::sixPile(vector<char> input,int reps){
    int repCount=0;
    vector<char> pool=input;
    int sizer=input.size();
    while(repCount!=reps){
        int pileCount=1;
        vector<char> p1;
        vector<char> p2;
        vector<char> p3;
        vector<char> p4;
        vector<char> p5;
        vector<char> p6;
        stack<char> deck;
        for(int i=pool.size()-1;i>=0;i--){
            deck.push(pool[i]);
        }
        while(!deck.empty()){
            if(pileCount==1){
                p1.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==2){
                p2.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==3){
                p3.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==4){
                p4.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==5){
                p5.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==6){
                p6.push_back(deck.top());
                deck.pop();
                pileCount=1;
            }
        }
        vector<char> shuffled;
        for(int i=0;i<p1.size();i++){
            shuffled.push_back(p1[i]);
        }
        for(int i=0;i<p5.size();i++){
            shuffled.push_back(p5[i]);
        }
        for(int i=0;i<p3.size();i++){
            shuffled.push_back(p3[i]);
        }
        for(int i=0;i<p6.size();i++){
            shuffled.push_back(p6[i]);
        }
        for(int i=0;i<p2.size();i++){
            shuffled.push_back(p2[i]);
        }
        for(int i=0;i<p4.size();i++){
            shuffled.push_back(p4[i]);
        }
        pool=shuffled;
        repCount++;
    }
    return pool;
}

vector<char> Encryption::antiSixPile(vector<char> input,int reps){
    int repCount=0;
    vector<char> pool=input;
    int sizer=pool.size();
    while(repCount!=reps){
        int determinant=(sizer%6);
        int a1=0;
        int a2=0;
        int a3=0;
        int a4=0;
        int a5=0;
        int a6=0;
        queue<char> p1;
        queue<char> p2;
        queue<char> p3;
        queue<char> p4;
        queue<char> p5;
        queue<char> p6;
        vector<char> deShuffle;
        if(determinant==1){
            a1=1;
        }else if(determinant==2){
            a1=1;
            a2=1;
        }else if(determinant==3){
            a1=1;
            a2=1;
            a3=1;
        }else if(determinant==4){
            a1=1;
            a2=1;
            a3=1;
            a4=1;
        }else if(determinant==5){
            a1=1;
            a2=1;
            a3=1;
            a4=1;
            a5=1;
        }
        for(int i=((sizer/6)+a1)-1;i>=0;i--){
            p1.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5))-1;i>=((sizer/6)+a1)-1;i--){
            p5.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5))-1;i--){
            p3.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3))-1;i--){
            p6.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6))-1;i--){
            p2.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2)+((sizer/6)+a4))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2))-1;i--){
            p4.push(pool[i]);
        }
        int unDeal=determinant;
        int counter=0;
        stack<char> deckBox;
        while(deckBox.size()<pool.size()){
            if(unDeal==6){
                deckBox.push(p6.front());
                counter++;
                p6.pop();
                unDeal--;
            }else if(unDeal==5){
                deckBox.push(p5.front());
                counter++;
                p5.pop();
                unDeal--;
            }else if(unDeal==4){
                deckBox.push(p4.front());
                counter++;
                p4.pop();
                unDeal--;
            }else if(unDeal==3){
                deckBox.push(p3.front());
                counter++;
                p3.pop();
                unDeal--;
            }else if(unDeal==2){
                deckBox.push(p2.front());
                counter++;
                p2.pop();
                unDeal--;
            }else if(unDeal==1){
                deckBox.push(p1.front());
                counter++;
                p1.pop();
                unDeal=6;
            }
        }
        for(int i=0;i<sizer;i++){
        char loader=(deckBox.top());
        deShuffle.push_back(loader);
        deckBox.pop();
        }
        pool=deShuffle;
        repCount++;
    }
    return pool;
}

void Encryption::constructKey(int entry){
    key.push_back(entry);
}
void Encryption::printKey(){
    for(int i=0;i<key.size();i++){
        cout<<key[i];
    }
    cout<<endl;
}


