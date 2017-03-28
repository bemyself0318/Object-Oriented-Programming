#include <iostream>
#include <cstdbool>
using namespace std;
//namespace BigIntLance
//{
class BigInt
{
public:

    BigInt();
    BigInt(char *str);
    BigInt(int number);
    BigInt(BigInt& number); // copy constructor
    BigInt(const BigInt &Bigobject);
    //~BigInt(); //destructor
    friend const BigInt operator + (const BigInt& A ,const BigInt& B); //done
    friend const BigInt operator - (const BigInt&  A ,const BigInt& B); // done
    friend const BigInt operator - (const BigInt& number); // done
    friend const BigInt operator * (const BigInt& A, const BigInt& B); //done
    friend const BigInt operator / (const BigInt& A, const BigInt& B);//done
    friend const bool operator ==(const BigInt& A , const BigInt&B);//done
    friend const bool operator <(const BigInt& A , const BigInt&B);//done
    friend const bool operator >(const BigInt& A , const BigInt& B);//done
    //friend const BigInt GCD(BigInt A,BigInt B);
    friend const BigInt Fractorail (const BigInt number);
    friend const BigInt operator %(const BigInt& A , const BigInt& B);//done
    friend ostream& operator <<(ostream& outputStream,const BigInt &num);//done
    BigInt& operator =(const BigInt& rightSide);//done
    int getBits()const;//done
private:
    int bits;
    int *container;
    //int  sign; // negtive=-1,positive=-2

};
//}