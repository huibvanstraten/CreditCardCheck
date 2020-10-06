# include <stdio.h>
# include <cs50.h>

long reversDigits(long ccNumber) // reversing the creditcard number to get the last 2 digits for checking company
{
long rev_num = 0;
while(ccNumber > 0)
{
rev_num = rev_num*10 + ccNumber%10;
ccNumber = ccNumber/10;
}
return rev_num;
}

int main(void)
{
    long l;
    printf("Number: ");
    long ccNumber = scanf("%ld", &l); 
    long number = ccNumber;
    int numDigits = 0; 
    
    while (number != 0) //counting number of digits
    { 
        number = number / 10; 
        ++numDigits; 
    } 

    int sumOfUneven = 0;
    int sumOfEven = 0;
    long N = ccNumber;

    for (int i=0; i < numDigits; i++) // loop for getting the the two calculations for checksum
    { 
        int sumNumber = N % 10;
        N = N / 10;
        if (i % 2 == 1) //the numbers that we need to multiply
        {
            sumNumber = sumNumber * 2;
            if (sumNumber > 9) //if number needs to be split
            {
                int lastDigit = sumNumber %10;
                int firstDigit = sumNumber /10;
                sumOfUneven += lastDigit + firstDigit;
            }
            else  
            {
                sumOfUneven += sumNumber;
            }
        }
        else // if doesnt need multiplication
        {
            sumOfEven += sumNumber; 
        }
    } 

    int checksum = sumOfUneven + sumOfEven;
    //which card is it? 
    long lastTwoDigits = reversDigits(ccNumber);

    if (numDigits < 13 || numDigits > 16) //checking if amount of digits suffices
    {
        printf("INVALID\n");
    }
    else if (checksum % 10 != 0) {
        printf("INVALID\n");
    }
    else if (lastTwoDigits % 10 == 4)
    {
        printf("VISA\n");
    }
    else if (lastTwoDigits % 100 == 43 || lastTwoDigits % 100 == 73 )
    {
        printf("AMEX\n");
    }
    else if (lastTwoDigits % 100 == 15 || lastTwoDigits % 100 == 25 ||
            lastTwoDigits % 100 == 35 || lastTwoDigits % 100 == 45 ||
            lastTwoDigits % 100 == 55 )
    {
        printf("MASTERCARD\n");
    }    
    else 
    {
        printf("INVALID\n");
    }
}

    

    
