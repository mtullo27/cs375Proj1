#include "program1.h"

const int big = 100;
int max(int a, int b){
 if(a>=b)
   return a;
 else
   return b;
}

int memo(string s1, string s2, int i1, int i2, int mem[][big]){
  if(i1 == 0 || i2 == 0)
    return 0;
  if(mem[i1-1][i2-1] != -1)
    return mem[i1-1][i2-1];
  if(s1[i1-1] == s2[i2-1]){
    mem[i1-1][i2-1] = memo(s1, s2, i1-1, i2-1, mem)+1;
    return mem[i1-1][i2-1];
  }
  else { 
    mem[i1-1][i2-1] = max(memo(s1, s2, i1, i2-1, mem), memo(s1, s2, i1-1, i2, mem)); 
    return mem[i1-1][i2-1];
  }
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
  int grid[size1][big];
  
  memset(grid, -1, sizeof(grid));
  
	struct timeval start, end; 
	gettimeofday(&start, NULL); 
	ios_base::sync_with_stdio(false);
	
  	outfile << "The length of the LCS is " << memo(file1, file2, size1, size2, grid) << endl;
	
	gettimeofday(&end, NULL); 
	double time_taken; 
    	time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6; 
    	outfile << "Time taken by program is : " << fixed << time_taken << setprecision(6); 
	outfile << " sec" << endl;
  
}
