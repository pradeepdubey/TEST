#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256
#define debug 0
int max (int a,int b ) { return (a > b)? a:b;}
void   fill_badChar(int badChar[MAX_CHAR], char *pat)
{
    int i=0;
    for (i=0;i<MAX_CHAR;i++)
    {
        badChar[i] = -1;
    }

    for (i=0;i<strlen(pat);i++)
    {
        badChar[(int)pat[i]] = i;
    }
}
void search(char *txt, char *pat) {

    int l1,l2,i,s=0;

    l1= strlen(txt);
    l2 = strlen(pat);

    int badChar[MAX_CHAR];
    fill_badChar(badChar, pat);

    if (debug) {
        printf("String is %s and array is",txt);
        for (i=0;i<MAX_CHAR;i++) {
            if (badChar[i] != -1)
                printf("%c:%d ", (char)i, badChar[i]);
        }
    }

    while (s <= (l1-l2)) {
       i = l2-1; 

       while (i >= 0 && txt[s+i] == pat[i])
        i--;

      if (i < 0)
      {
        printf("Pattern Found at Position %d\n", s);
        s += (s+l2 < l1) ? l2 - badChar[txt[s+l2]] : 1;
      } else {
        s += max(1, i - badChar[txt[s+i]]) ;
      }
    }
}

void main()
{

    char txt[] = "logic Where logiclogiclois the intrest and logic going";
    char pat[] = "logiclo";

    search(txt,pat);
}
