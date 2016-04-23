#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <vector>

using namespace std;


class Encryption
{
    public:
        Encryption();
        ~Encryption();
        int randGen(int,int);
        vector<char> faro(vector<char>,int);
        vector<char> antiFaro(vector<char>,int);
        vector<char> sixPile(vector<char>,int);
        vector<char> antiSixPile(vector<char>,int);
    protected:
    private:
        vector<int> key;
};

#endif // ENCRYPTION_H
