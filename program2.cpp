#include "program1.h"

int max(int a, int b){
 if(a>=b)
   return a;
 else
   return b;
}

int recursion(string s1, string s2, int i1, int i2){
 if(i1 == 0 || i2 ==0)
   return 0;
  if(s1[i1-1] == s2[i2-1])
    return recursion(s1, s2, i1-1, i2-1);
  else
    return max (lcs(s1, s2, i1, i2 - 1), lcs(s1, s2, i1 - 1, i2));
}

int main(int argc, char *argv[]){
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;
	
	string file1;
	string file2;
	
	infile1.open(argv[1]);
	infile2.open(argv[2]);
	outfile.open(argv[3]);
	
	infile1 >> file1;
	infile2 >> file2;
	
	int size1 = file1.length();
	int size2 = file2.length();
	struct timeval start, end; 
	gettimeofday(&start, NULL); 
	ios_base::sync_with_stdio(false);
  recursion(file1, file2, size1, size2);
  
}
