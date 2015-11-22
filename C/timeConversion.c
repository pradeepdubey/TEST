#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
        int hh,mm,ss,am;
        char *s,*ptr;
        char inp[11],tmp[4],tmphh[4];
        s = inp;
        ptr = tmp;
        scanf("%s", s);
        ptr  = strncpy(ptr,s,2);
        tmp[2] = '\0';
        hh = atoi(ptr); 
        if (hh < 0 || hh > 12)
            return -1;

        s+=8;
        ptr  = strncpy(ptr,s,2);
        tmp[2] = '\0';
        if (strncmp(tmp,"PM",2) == 0) {
            if (hh != 12) 
            {
                hh = 12 + hh;
                snprintf(tmphh,3,"%d",hh);
                strncpy(inp,tmphh,2);
            }    
        } 
        else
        {
            if (hh == 12)
            {
                snprintf(tmphh,3,"%s","00");
                strncpy(inp,tmphh,2);
            }
        }
        inp[8] = '\0';    
        printf("%s\n", inp);
        return 0;

}
