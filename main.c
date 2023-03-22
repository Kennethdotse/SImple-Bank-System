#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>// header file for sleep function.

float balance = 124;
int tries = 0;
int authenticate(int pin);
float requestAmount();
//void deposit(int amt);
float withDraw();
void transfer();

int main()
{
    start:
        printf("WELCOME TO ABC BANK :) \nEnter your four digit pin: ");
        int pin;
        scanf("%d", &pin);
    menu:
        if(authenticate(pin) && tries <4){
        int menu_item;
    pass:
        printf("\n1.Check Balance\n2.Withdrawal\n3.Deposit\n4.Transfer\nSelect an option: ");
        scanf("%d", &menu_item);
        switch(menu_item){
            case 1: printf("\nYour balance is %f\n", balance);
                break;
            case 2: withDraw(requestAmount());
                break;
            case 3: deposit();
                break;
            case 4: transfer();
                break;
            default:
                printf("\nInvalid Entry.\n");
                goto pass;
                    }
            }
        else{
            ++tries;
            printf("\nInvalid pin after %d tries\n", tries);
            //if (tries<4)
                //goto start;
         }
        int response;

        if (tries<4)
        {printf("\nWould you like to perform another transaction?\n1.Yes\n2.No\n");
        scanf("%d", &response);}
        if(response == 1){goto pass;}

         printf("\nThank you for banking with us ;) \n");


        return 0;
}

    int authenticate(int pin){
        while(tries<=4)
            {
                if (pin == 1322)
                    {
                        printf("Login Successful\n");
                        break;
                    }
                else
                    {
                        printf("Try Again: ");
                        scanf("%d",&pin);

                    }
            ++tries;
            }


    return pin;
    }

    float requestAmount()
    {
        float amt;
        printf("\nPlease Enter the amount: ");
        scanf("%f",&amt);
        return amt;
    }

    void deposit(float amt)
    {
        printf("\nPlease Enter the amount: ");
        scanf("%f",&amt);
        balance += amt;
        printf("\nYour account has been credited with %f. Your new balance is %f\n", amt,balance);
    }

    float withDraw()
    {
        float amt;
        //printf("Please Enter the amount: ");
        if(amt<balance){
        balance -= amt;
        printf("\nYour account has been debited with %f. Your new balance is %f\n",amt, balance);
        }
        else
        {printf("Insufficient balance");}

        return amt;
    }

    void transfer()
    {
        float amt;
        int recipient;
        printf("Enter the recipient's account number: ");
        scanf("%s", &recipient); // receive and store recipients number in the "recipient" address
        int sender;
        printf("Enter the senders account number: ");
        scanf("%s", &sender);// receive and store senders number in the "senders" address
        printf("Enter amount to send: ");
        scanf("%f",&amt);
        if(balance>=amt){
            balance -= amt;
            printf("You've sent %f to account number: %s",amt,sender);}
        else
        {printf("Insufficient balance");}// make the debit into the recipients account
        //return amt;
    }

