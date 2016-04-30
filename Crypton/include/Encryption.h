#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Encryption
{
    public:
        Encryption();
        ~Encryption();
        vector<int> getKey();
        void setKey(int,int);
        int randGen(int,int);
        int conversion(std::string number);
        vector<char> faro(vector<char>,int);
        vector<char> antiFaro(vector<char>,int);
        vector<char> sixPile(vector<char>,int);
        vector<char> antiSixPile(vector<char>,int);
        void printKey();
        void moveToDeck (queue<char>&, stack<char>&);
        void constructKey(int entry);
    protected:
    private:
        vector<int> key;
};

#endif // ENCRYPTION_H
