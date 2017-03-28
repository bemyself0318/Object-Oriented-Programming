#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class BigInt
{
    public:
    
    BigInt();
    BigInt(char *inputstr);
    BigInt(int number);
   //BigInt(BigInt data );
    void print(); 
    //int getBits();
    friend const BigInt operator + (BigInt& augend ,BigInt& addend);
    
    friend
    
    private:
    int *container=new int[1000];
    int bits;
};

int main()
{
    BigInt a("314159265358979323846264338327950288419716939937510");
    a.print();
    BigInt b(123456);
    b.print();
    return 0;
}

BigInt::BigInt()
{
    bits=1;
    for(int i=0;i<1000;i++)
        container[i]=-1;
    container[0]=0;
    
}

BigInt::BigInt(char *inputstr)
{
    bits=0;
    for(int i=0;i<1000;i++) container[i]=-1;
    while(1){
        if(inputstr[bits]=='\0')
            break;
        container[bits]=inputstr[bits]-'0';
        bits++;
    }
}

BigInt::BigInt(int number)
{
    for(int i=0;i<1000;i++) container[i]=-1;
    bits=0;
    int temp[1000]={0};
    while(number>0){
        temp[bits]=(number%10);
        number/=10;
        bits++;
    }
    for(int i=0;i<bits;i++){
        container[i]=temp[bits-1-i];
    }
    
}

void BigInt::print()
{
    for(int i=0;i<bits;i++)
        printf("%d",container[i]);
    cout<<endl;
}

/*int BigInt::getBits()
{
    return bits;
}*/

const BigInt operator + (BigInt& augend ,BigInt& addend)
{
    
    int maxBits=0;
    if(augend.bits>=addend.bits){
        maxBits=augend.bits;
        int shift=augend.bits-addend.bits;
        for(int i=addend.bits;i>=0;i--){
            addend[i+shift]=addend[i];
        }
        for(int i=0;i<shift;i++){
            addend[i]=0;
        }
    }
    else{
        maxBits=addend.bits;
        int shift=addend.bits-augend.bits;
        for(int i=augend.bits;i>=0;i--){
            augend[i+shift]=augend[i];
        }
        for(int i=0;i<shift;i++){
            augend[i]=0;
        }
    }
    int sum=0,carry=0;
    BigInt temp;
    while(maxBits>=0){
        sum=carry+augend[bitsAugend]+addend[bitsAddend];
        if(sum>=10){
            carry=1;
            sum-=10;
        }
        else carry=0;
        bitsAddend--;
        bitsAugend--;
        temp[maxBits]=sum;
        maxBits--;
            
    }
}