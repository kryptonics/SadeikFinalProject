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
        int a[6] = {0,0,0,0,0,0};
        queue<char> p[6] = {queue<char>(),queue<char>(),queue<char>(),queue<char>(),queue<char>(),queue<char>()};
        vector<char> deShuffle;
        for(int i=0; i<determinant && i<6; i++)
          a[i] = 1;
        for(int i=((sizer/6)+a[0])-1;i>=0;i--){
            p[0].push(pool[i]);
        }
        for(int i=(((sizer/6)+a[0])+((sizer/6)+a[4]))-1;i>=((sizer/6)+a[0])-1;i--){
            p[4].push(pool[i]);
        }
        for(int i=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2]))-1;i>=(((sizer/6)+a[0])+((sizer/6)+a[4]))-1;i--){
            p[2].push(pool[i]);
        }
        for(int i=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2])+((sizer/6)+a[5]))-1;i>=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2]))-1;i--){
            p[5].push(pool[i]);
        }
        for(int i=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2])+((sizer/6)+a[5])+((sizer/6)+a[1]))-1;i>=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2])+((sizer/6)+a[5]))-1;i--){
            p[1].push(pool[i]);
        }
        for(int i=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2])+((sizer/6)+a[5])+((sizer/6)+a[1])+((sizer/6)+a[3]))-1;i>=(((sizer/6)+a[0])+((sizer/6)+a[4])+((sizer/6)+a[2])+((sizer/6)+a[5])+((sizer/6)+a[1]))-1;i--){
            p[3].push(pool[i]);
        }
        int unDeal=determinant-1;
        stack<char> deckBox;
        while(deckBox.size()<pool.size()){
            moveToDeck(p[unDeal], deckBox);
            unDeal--;
            if(unDeal <= 0)
              unDeal = 5;
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

void Encryption::moveToDeck (queue<char> &qu, stack<char> &deckBox) {
  deckBox.push(qu.front());
  qu.pop();
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
