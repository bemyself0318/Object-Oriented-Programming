#include <cstdio>
#include <iostream>
#include "BigInt.h"

ostream& operator << (ostream &outputStream,const BigInt &num)
{
    if(num.container[0] == -1)
    {
        outputStream << '-';
    }
    int skip = 0;
    for(int i = 1 ; i < num.bits ; i++)
    {
        if(num.container[i] == 0 && skip == 0)
        {
            continue;
        }
        else
        {
            skip = 1;
            outputStream << num.container[i];
        }
    }
    if(skip == 0)
    {
        outputStream << 0;
    }
    return outputStream;
}

BigInt::BigInt()
{
    bits = 2;
    container = new int[bits];
    container[0] = -2;
    container[1] = 0;
}

BigInt::BigInt(char *str)
{
    int digit = 0;
    while(str[digit]!='\0') digit++;
    //cout<<digit << endl;
    if(str[0] == '-')
    {
        container=new int[digit];
        container[0] = -1;
        for(int i = 1 ; i < digit ; i++)
        {
            container[i] = str[i] - 48;
        }
        bits = digit;
    }
    else
    {
        container = new int[digit + 1];
        bits = digit + 1;
        container[0] = -2;
        for(int i = 0 ; i < digit ; i++)
        {
            container[i+1] = str[i] - 48;
        }
    }
}


BigInt::BigInt(int number)
{
    int cnt=0,temp=number;
    if(temp<0) temp*=-1;
    while(temp>0)
    {
        temp/=10;
        cnt++;
    }
    bits=cnt+1;
    int t[bits],i=1;
    t[0]=-2;
    if(number<0)
    {
        t[0]=-1;
        number*=-1;
    }
    while(number>0)
    {
        t[i]=number%10;
        number/=10;
        i++;
    }
    container=new int[bits];
    container[0]=t[0];
    for(int i=1; i<bits; i++)
    {
        container[i]=t[bits-i];
    }
}

BigInt::BigInt(BigInt& number)
{
    bits=number.bits;
    container=new int[bits];
    for(int i=0; i<bits; i++)
    {
        container[i]=number.container[i];
    }
}

const BigInt operator + (const BigInt& A, const BigInt& B)
{
    BigInt ans , small , big , Swap;
    if(A.bits > B.bits)
    {
        big = A;
        small = B;
        Swap = A;
    }
    else if((A.container[0] == -2 && B.container[0] == -1) && (A.bits == B.bits))
    {
        big = A;
        small = B;
        Swap = A;
    }
    else
    {
        big = B;
        small = A;
        Swap = B;
    }
    ans.bits = big.bits + 1;
    ans.container = new int[ans.bits];
    for(int i = 0 ; i < ans.bits ; i++)
    {
        ans.container[i] = 0;
    }
    if(A.container[0] == B.container[0])
    {
        int carry = 0;
        int minbits = small.bits - 1;
        int maxbits = big.bits - 1;
        ans.container[0] = A.container[0];
        for(int i = maxbits ; i > 0 ; i--)
        {
            if(minbits > 0)
            {
                if(big.container[i] + small.container[minbits] + carry > 9)
                {
                    ans.container[i+1] = big.container[i] + small.container[minbits] + carry - 10;
                    carry = 1;
                }
                else
                {
                    ans.container[i+1] = big.container[i] + small.container[minbits] + carry;
                    carry = 0;
                }
                minbits--;
            }
            else
            {
                if(big.container[i] + carry > 9)
                {
                    ans.container[i+1] = big.container[i] + carry - 10;
                    carry = 1;
                }
                else
                {
                    ans.container[i+1] = big.container[i] + carry;
                    carry = 0;
                }
            }
        }
        ans.container[1] = carry;
    }
    else
    {
        int carry = 0 , change = 0;
        int maxbits = big.bits - 1;
        int minbits = small.bits - 1;
        if(big.bits == small.bits)
        {
            for(int i = 1 ; i < big.bits ; i++)
            {
                if(big.container[i] > small.container[i])
                {
                    break;
                }
                else if(big.container[i] < small.container[i])
                {
                    Swap = big;
                    big = small;
                    small = Swap;
                    break;
                }
                else if(big.container[i] == small.container[i])
                {
                    continue;
                }
            }
        }
        for(int i = maxbits ; i > 0 ; i--)
        {
            if(minbits > 0)
            {
                if(big.container[i] - small.container[minbits] - carry < 0)
                {
                    ans.container[i+1] = big.container[i] - small.container[minbits] - carry + 10;
                    carry = 1;
                }
                else
                {
                    ans.container[i+1] = big.container[i] - small.container[minbits] - carry;
                    carry = 0;
                }
                minbits--;
            }
            else
            {
                if(big.container[i] - carry < 0)
                {
                    ans.container[i+1] = big.container[i] - carry + 10;
                    carry = 1;
                }
                else
                {
                    ans.container[i+1] = big.container[i] - carry;
                    carry = 0;
                }
            }
        }
        ans.container[0] = big.container[0];
    }

    BigInt real_ans;
    int skip = 0 , r_b = 0 , st = 0;
    for(int i = 1 ; i < ans.bits ; i++)
    {
        if(ans.container[i] == 0 && st == 0)
        {
            skip++;

            continue;
        }
        else
        {
            st = 1;
            r_b++;
        }
    }
    if(r_b == 0)
    {
        real_ans.bits = 2;
        real_ans.container = new int[real_ans.bits];
        real_ans.container[0] = -2;
        real_ans.container[1] = 0;
    }
    else
    {
        real_ans.bits = r_b+1;
        real_ans.container = new int[real_ans.bits];
        for(int i = 1 ; i < real_ans.bits ; i++)
        {
            real_ans.container[i] = ans.container[i+skip];
        }
        real_ans.container[0] = ans.container[0];
    }
    return real_ans;
}

const BigInt operator - (const BigInt&  A ,const BigInt& B)
{
    BigInt ans , temp1 , temp2;
    temp1 = A;
    temp2 = B;
    if(temp2.container[0] == -2)
    {
        temp2.container[0] = -1;
        ans = temp1 + temp2;
    }
    else if(temp2.container[0] == -1)
    {
        temp2.container[0] = -2;
        ans = temp1 + temp2;
    }
    return ans;
}

const BigInt operator * (const BigInt& A, const BigInt& B)
{
    int maxbits=A.bits+B.bits-1;
    BigInt C;
    C.bits=maxbits;
    C.container=new int[C.bits];
    for(int i=0; i<maxbits; i++)
    {
        C.container[i]=0;
    }
    for(int i = A.bits-1 ; i > 0 ; i--)
    {
        for(int j = B.bits-1 ; j > 0 ; j--)
        {
            C.container[i+j] = A.container[i] * B.container[j] + C.container[i+j];
        }
    }
    for(int i = maxbits-1 ; i > 1 ; i--)
    {
        if(C.container[i] > 9)
        {
            C.container[i-1] = C.container[i]/10 + C.container[i-1];
            C.container[i] = C.container[i]%10;
        }
    }
    if(A.container[0] == B.container[0])
    {
        C.container[0] = -2;
    }
    else
    {
        C.container[0] = -1;
    }

    BigInt real_ans;
    int skip = 0 , r_b = 0 , st = 0;
    for(int i = 1 ; i < C.bits ; i++)
    {
        if(C.container[i] == 0 && st == 0)
        {
            skip++;

            continue;
        }
        else
        {
            st = 1;
            r_b++;
        }
    }
    if(r_b == 0)
    {
        real_ans.bits = 2;
        real_ans.container = new int[real_ans.bits];
        real_ans.container[0] = -2;
        real_ans.container[1] = 0;
    }
    else
    {
        real_ans.bits = r_b+1;
        real_ans.container = new int[real_ans.bits];
        for(int i = 1 ; i < real_ans.bits ; i++)
        {
            real_ans.container[i] = C.container[i+skip];
        }
        real_ans.container[0] = C.container[0];
    }
    return real_ans;
}

const BigInt operator /(const BigInt& A , const BigInt& B)
{
    BigInt cmp("0");
    if(B == cmp)
    {
        cout << "Denominator can't be zero" << endl;
        return 0;
    }
    else if((A.container[0] == B.container[0]) && A.container[0] == -2)
    {
        BigInt pre_ans;
        if(A < B)
        {
            pre_ans = BigInt("0");
            return pre_ans;
        }
        else if(A == B)
        {
            pre_ans = BigInt("1");
            return pre_ans;
        }
        else
        {
            BigInt ans, temp_A;
            temp_A = A;
            ans.bits = A.bits - B.bits + 2;
            ans.container = new int[ans.bits];
            ans.container[0] = -2;
            for(int i = 1 ; i < ans.bits ; i++)
            {
                ans.container[i] = 0;
            }

            BigInt ten("1") , temp;
            int t;
            for(int i = 0 ; ; i++)
            {
                if(temp > temp_A)
                {
                    t = i - 2;
                    break;
                }
                else
                {
                    ten = ten * BigInt("10");
                    temp = ten*B;
                }
            }

            int a = 0;
            while(temp_A > B || temp_A == B)
            {
                ten = BigInt("1");
                if(t != 0)
                {
                    for(int i = 0 ; i < t ; i++)
                    {
                        ten = ten * BigInt("10");
                        temp = ten * B;
                    }
                }
                else
                {
                    temp = B;
                }
                BigInt cmp("0");
                for(int i = 0;i <= 10;i++)
                {
                    if(temp_A - temp < cmp)
                    {
                        a = i;
                        break;
                    }
                    temp_A = temp_A - temp;
                }
                ans.container[ans.bits - t - 1] = a;
                t--;
            }
            ans.container[0] = -2;
            return ans;
        }
    }
    else
    {
        if(A.container[0] == -1)
        {
            return -(-A/B);
        }
        else if(B.container[0] == -1)
        {
            return -(A/-B);
        }
        else
        {
            return (-A/-B);
        }
    }
}

const BigInt operator %(const BigInt& A , const BigInt& B)
{
    return (A - ((A/B)*B));
}

BigInt& BigInt::operator =(const BigInt& rightSide)
{
    if(bits != rightSide.bits)
    {
        delete [] container;
        container = new int[rightSide.bits];
    }
    bits = rightSide.bits;
    for(int i = 0 ; i < bits ; i++)
    {
        container[i] = rightSide.container[i];
    }
    return *this;
}

const bool operator ==(const BigInt& A , const BigInt& B)
{
    int same = 1 , A_z = 1 , B_z = 1;
    if(A.bits != B.bits)
    {
        for(int i = 1 ; i < A.bits ; i++)
        {
            if(A.container[i] != 0)
            {
                A_z = 0;
                break;
            }
        }
        for(int i = 1 ; i < B.bits ; i++)
        {
            if(B.container[i] != 0)
            {
                B_z = 0;
                break;
            }
        }
        if(A_z == 1 && B_z == 1)
        {
            same = 1;
        }
        else
        {
            same = 0;
        }

    }
    else
    {
        for(int i = 0 ; i < A.bits ; i++)
        {
            if(A.container[i] != B.container[i])
            {
                same = 0;
                break;
            }
        }
    }
    return same;
}

const bool operator <(const BigInt& A , const BigInt& B)
{
    int smaller = 1 , Equ = 1;
    if(A.container[0] == -1 && B.container[0] == -2)//A- B+
    {
        smaller = 1;
    }
    else if(A.container[0] == -2 && B.container[0] == -1) // A+ B-
    {
        smaller = 0;
    }
    else // A sign == B sign
    {
        if(A.container[0] == -2) //+
        {
            if(A.bits < B.bits) // A < B
            {
                smaller = 1;
            }
            else if(A.bits == B.bits)
            {
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] > B.container[i]) // A > B
                    {
                        smaller = 0;
                        break;
                    }
                }
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] != B.container[i])
                    {
                        Equ = 0;
                    }
                }
                if(Equ == 1)
                {
                    smaller = 0;
                }
            }
            else
            {
                smaller = 0;  // A > B
            }
        }
        else  // -
        {
            if(A.bits > B.bits)
            {
                smaller = 1;
            }
            else if(A.bits == B.bits)
            {
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] < B.container[i]) // A > B
                    {
                        smaller = 0;
                        break;
                    }
                    for(int i = 1 ; i < A.bits ; i++)
                    {
                        if(A.container[i] != B.container[i])
                        {
                            Equ = 0;
                        }
                    }
                    if(Equ == 1)
                    {
                        smaller = 0;
                    }
                }
            }
            else
            {
                smaller = 0;
            }
        }
    }
    return smaller;
}

const bool operator >(const BigInt& A , const BigInt& B)
{
    int bigger = 1 , Equ = 1;
    if(A.container[0] == -1 && B.container[0] == -2)//A- B+
    {
        bigger = 0;
    }
    else if(A.container[0] == -2 && B.container[0] == -1) // A+ B-
    {
        bigger = 1;
    }
    else // A sign == B sign
    {
        if(A.container[0] == -2) //+
        {
            if(A.bits > B.bits) // A > B
            {
                bigger = 1;
            }
            else if(A.bits == B.bits)
            {
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] < B.container[i]) // A > B
                    {
                        bigger = 0;
                        break;
                    }
                }
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] != B.container[i])
                    {
                        Equ = 0;
                    }
                }
                if(Equ == 1)
                {
                    bigger = 0;
                }

            }
            else
            {
                bigger = 0;  // A<B
            }
        }
        else  // -
        {
            if(A.bits > B.bits) // A < B
            {
                bigger = 0;
            }
            else if(A.bits == B.bits)
            {
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] > B.container[i]) // A < B
                    {
                        bigger = 0;
                        break;
                    }
                }
                for(int i = 1 ; i < A.bits ; i++)
                {
                    if(A.container[i] != B.container[i])
                    {
                        Equ = 0;
                    }
                }
                if(Equ == 1)
                {
                    bigger = 0;
                }
            }
            else
            {
                bigger = 1;
            }
        }
    }
    return bigger;
}



const BigInt operator -(const BigInt& number)
{
    BigInt temp;
    temp = number;
    if(temp.container[0]==-1) //positive
    {
        temp.container[0]=-2; //negtive
    }
    else if(temp.container[0]==-2)
    {
        temp.container[0]=-1;
    }
    return temp;
}



/*const BigInt operator % (BigInt& A,BigInt& B)
{
    BigInt temp(A);
    while(temp>=B)
    {
        temp = temp - B;
    }
    return temp;
}*/

/*const BigInt Fractorail (BigInt number)
{
    BigInt temp,one(1),two(2);
    temp.bits=0;
    for(BigInt i(number);i >= one; i = i - one)
    {
        temp.bits=temp.bits + i;
    }
    temp.bits=temp.bits + 1;
    temp.container = new int[temp.bits];
    temp.container[0]=-2;

    for(int i=1;i<temp.bits;i++){
        temp.container[i]=0;
    }

    for(BigInt i(number) ; i >= two ;i = i - one)
    {
        temp = temp +( i * ( i - one) );
    }
    return temp;
}*/

int BigInt::getBits()const
{
    return bits;
}
