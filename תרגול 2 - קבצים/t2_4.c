/*=========================================================================
Program to mimic basic scanf() and printf functionality using system calls
Those mimics do not work exactly the same as scanf() and printf.
The goal is to demonstrate a basic ability to record information from the
keyboard (standrd input) and basic screen printing (standard output i.e., the terminal window)
Yoram Segal
==========================================================================*/

#include<unistd.h>
#include<stdio.h>

#define MAX_READ_SIZE 100

int myPrintf(char *data)
{
        char *p;
        //Print text to screen via fd=1 (without using printf)
        for(p =data ; *p ; p++){
                write(1, p, 1);
        }
}

int MyScanf(char *data, int max_limit)
{
        int nbytes;
        nbytes = read(0,data,max_limit);//Read data from keyboard till ENTER or till 20 chars
        data[nbytes]='\0';//Add end of string to the buffer
        return nbytes;
}

int main()
{
        char buf[21];
        char message[]="Please type number\n";

        myPrintf(message);//Print text to screen

        MyScanf(buf,MAX_READ_SIZE);//Get data from keyboard into buf

        myPrintf(buf);//Print buf text to screen

}

