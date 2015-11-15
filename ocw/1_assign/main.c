#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
union float_bits{
    float f;
    unsigned int bits;
};


void print_bin(float number);
void print_hex(float f);


int main(int argc, char *argv[])
{

    FILE* fd;
    char input_num[100];
    float num=0;
    int len =0;
    int i;
    if(argc != 2)
    {
        printf("Please input data file!\n");
        exit(1);
    }


    if((fd = fopen(argv[1], "r")) == 0 )
    {
        printf("%s : file open fail \n", argv[1]);
        exit(1);
    } 
    fgets(input_num, sizeof(input_num), fd);
    len = atoi(input_num);


    for (i=0;i<len; i++)
    {
        fgets(input_num, sizeof(input_num), fd);
        num = atof(input_num);
//        printf("float input : %f\n", num);
        print_bin(num);
//        print_hex(num);
    }
    printf("\n\n");       
    fclose(fd);
    return 0;
}
void print_bin(float number)
{
    union float_bits t;
    int i; 
    t.f = number;

    if( 0 == (t.bits>>31 & 0x1))
       printf("1.");
    else
        printf("-1.");

    for(i = 22; i>=0 ; i--)
    {
        if((t.bits >> i) & 0x1)
            printf("1");
        else
            printf("0");
    }
    
    printf(" * 2^%d \n",((t.bits >> 23 ) & 0xff)-127  );
    
}

void print_hex(float f)
{
    union float_bits t;
    t.f = f;
    printf("The float looks like 0x%x in hex\n", t.bits);
}
