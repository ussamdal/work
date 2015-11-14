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

    while(fgets(input_num, sizeof(input_num), fd))
    {
        num = atof(input_num);
        printf("float input : %f\n", num);
        print_bin(num);
        print_hex(num);
    }
        
    fclose(fd);
    return 0;
}
void print_bin(float number)
{
    char temp[100];

//    temp[0] = (number0x70000000)?'2':'1';

 //   printf("%s\n", temp);

}

void print_hex(float f)
{
    union float_bits t;
    t.f = f;
    printf("The float looks like 0x%x in hex\n", t.bits);
}
