#include<iostream>
using namespace std;

/*void fullSuffixMatch(int shiftArr[], int borderArr[], string pattern) {
   int n = pattern.size();       //find length of pattern
   int i = n;
   int j = n+1;
   borderArr[i] = j;

   while(i > 0) {
      //search right when (i-1)th and (j-1)th item are not same
      while(j <= n && pattern[i-1] != pattern[j-1] ) {
         if(shiftArr[j] == 0)
            shiftArr[j] = j-i;     //shift pattern from i to j
         j = borderArr[j];       //update border
      }
      i--;
      j--;
      borderArr[i] = j;
   }  
}

void partialSuffixMatch(int shiftArr[], int borderArr[], string pattern) {
   int n = pattern.size();    //find length of pattern
   int j;
   j = borderArr[0];

   for(int i = 0; i<n; i++) {
      if(shiftArr[i] == 0)
         shiftArr[i] = j;        //when shift is 0, set shift to border value
         if(i == j)
            j = borderArr[j];    //update border value
   }
}

void searchPattern(string mainString, string pattern, int array[], int *index) {
   int patLen = pattern.size();
   int strLen = mainString.size();
   int borderArray[patLen+1];
   int shiftArray[patLen + 1];

   for(int i = 0; i<=patLen; i++) {
      shiftArray[i] = 0;     //set all shift array to 0
   }

   fullSuffixMatch(shiftArray, borderArray, pattern);
   partialSuffixMatch(shiftArray, borderArray, pattern);
   int shift = 0;

   while(shift <= (strLen - patLen)) {
      int j = patLen - 1;
      while(j >= 0 && pattern[j] == mainString[shift+j]) {
         j--;         //reduce j when pattern and main string character is matching
      }

      if(j < 0) {
         (*index)++;
         array[(*index)] = shift;
         shift += shiftArray[0];
      }else {
          shift += shiftArray[j+1];
      }
   }
}

int main() {
   string mainString = "ABAAABCDBBABCDDEBCABC";
   string pattern = "ABC";
   int locArray[mainString.size()];
   int index = -1;
   searchPattern(mainString, pattern, locArray, &index);

   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i]<<endl;
    }
}*/

/* C++ Program for Bad Character Heuristic of Boyer
Moore String Matching Algorithm */
#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic( string str, int size,
						int badchar[NO_OF_CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence
	// of a character
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search( string &txt, string &pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];

	/* Fill the bad character array by calling
	the preprocessing function badCharHeuristic()
	for given pattern */
	badCharHeuristic(pat, m, badchar);

	int s = 0; // s is shift of the pattern with
				// respect to text
	while(s <= (n - m))
	{
		int j = m - 1;

		/* Keep reducing index j of pattern while
		characters of pattern and text are
		matching at this shift s */
		while(j >= 0 && pat[j] == txt[s + j])
			j--;

		/* If the pattern is present at current
		shift, then index j will become -1 after
		the above loop */
		if (j < 0)
		{
			cout << "pattern occurs at shift = " << s << endl;

			/* Shift the pattern so that the next
			character in text aligns with the last
			occurrence of it in pattern.
			The condition s+m < n is necessary for
			the case when pattern occurs at the end
			of text */
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;

		}

		else
			/* Shift the pattern so that the bad character
			in text aligns with the last occurrence of
			it in pattern. The max function is used to
			make sure that we get a positive shift.
			We may get a negative shift if the last
			occurrence of bad character in pattern
			is on the right side of the current
			character. */
			s += max(1, j - badchar[txt[s + j]]);
	}
}

/* Driver code */
int main()
{
	string txt= "ABAAABCD";
	string pat = "ABC";
	search(txt, pat);
	return 0;
}

// This code is contributed by rathbhupendra
