#include <stdio.h>
#include <string.h>

/*Caso en el que se encuentre un missmatch entre el texto y el patron
se tiene que movel el patron hasta que se encuentre un prefijo que encaje 
con la seccion del texto valida antes del missmatch*/
void preprocess_strong_suffix(int *shift, int *bpos,
                        string pat, int m)
{
   int i=m, j=m+1;
   bpos[i]=j;

   while(i>0)
   {

      while(j<=m && pat[i-1] != pat[j-1])
      {

         if (shift[j]==0)
            shift[j] = j-i;

         j = bpos[j];
      }

      i--;j--;
      bpos[i] = j;
   }
}

/*Caso en que no coincida ningun prefijo del patron con 
el sufijo acertado del texto, se mueve el patron hasta pasar 
por completo el match anterior */
void preprocess_case2(int *shift, int *bpos,
               string pat, int m)
{
   int i, j;
   j = bpos[0];
   for(i=0; i<=m; i++)
   {

      if(shift[i]==0)
         shift[i] = j;

      if (i==j)
         j = bpos[j];
   }
}

void search(string &text, string &pat)
{
   // s es las posiciones de movimiento del texto 
   int s=0, j;
   int m = pat.size();
   int n = text.size();

   int bpos[m+1], shift[m+1];

   //initialize all occurrence of shift to 0
   for(int i=0;i<m+1;i++) shift[i]=0;

   preprocess_strong_suffix(shift, bpos, pat, m);
   preprocess_case2(shift, bpos, pat, m);

   while(s <= n-m)
   {

      j = m-1;

      /* Keep reducing index j of pattern while characters of
         pattern and text are matching at this shift s*/
      while(j >= 0 && pat[j] == text[s+j])
         j--;

      /* If the pattern is present at the current shift, then index j
         will become -1 after the above loop */
      if (j<0)
      {
         //printf("pattern occurs at shift = %d\n", s);
         s += shift[0];
      }
      else
         /*pat[i] != pat[s+j] so shift the pattern
         shift[j+1] times */
         s += shift[j+1];
   }

}

