//this liberary i work on it right now;
//now i'm updating performance of multiplication from O(n^2) to O(n*logn) =====> (n = digits of large number);
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

string clear_left_zeros(string n)
{
    int i=0;
    for(i;i<n.size();i++)
        if(n[i]!='0')
            break;
    if(n.size()==i)
        return "0";
tahdith
    return n.substr(i);

}

string Add (string num1 ,string num2)
{
    int sum2=0,carry=0;      // sum2 just sum 2digits of 2 numbers strings and carry store the carry of sum;
    string result="";

    for(int i=(num1.size()-1) , j=(num2.size()-1) ;; j-- ,i--)
    {

        if(i>=0&&j>=0)
            sum2 = (num1[i]-'0') + (num2[j] - '0') + carry;

        else if(j>=0 && i<0)
            sum2 = (num2[j] - '0') + carry;

        else if(i>=0 && j<0)
            sum2 = (num1[i]-'0') + carry;

        else
            break;


        if(sum2 > 9)
            result += char(sum2%10 + 48);
        else
            result += char(sum2 + 48);

        carry = sum2/10;

    }

    if (carry>0)
    {
        result += char(carry + 48);
    }



    reverse(result.begin(),result.end());


    return clear_left_zeros(result);

}

//since n is number of digits.
//multplication func is O(n^2) but it still OK because its numbers so n hardly hit upove 1000 expected work will in range(50:9000) digits;
string mult(string num1 , string num2)
{
    //in this code num2 must be the big number only in size;
    if (num1.size()>num2.size())
    {
        string temp = num2;
        num2=num1;
        num1=temp;
    }


    string multstep=""; //multstep ==> its operation of multplying num1[i]*num2 ex: if 156*65 then 1st multstep will be 5*156
    string sum="";     //that sum all multisteps;
    int step;         //every mult operation in multstep ex: 5 * 156 : 5*6==>5*5==>5*1;
    int carry = 0 ;  //carries used in previous operation
    int crnt;       //current num1[i]
    int size1=num1.size(),size2=num2.size();

    for(int i=size1-1;i>=0;i--)
    {
            multstep="";
            for(int j=size2-1;j>=0;j--)
            {
                step=(num1[i]-48)*(num2[j]-48)+carry; //-48 to convert from char to int ('0'asscii code)

                if(step>9)
                    multstep+=char(step%10 + 48);
                else
                    multstep+=char(step + 48);

                carry = step/10;

            }
            if (carry>0)
            {
                multstep+=char(carry + 48);
                carry=0;

            }

            reverse(multstep.begin(),multstep.end());

            //this part to put zeros before addition Oerartion ex: 65*21  ==> 1*65=65 then 2*65 will be start under 6.
            int diff = abs(size1-size2);
            for(int j=0; j<(size2-(i+1+diff));j++)
                multstep+='0';


            sum=Add(sum,multstep);


    }

    return clear_left_zeros(sum);

}
