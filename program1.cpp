#include "program1.h"

int main(int argc, char *argv[]){
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;
	
	string file1;
	string file2;
	
	infile1.open(argv[1]);
	infile2.open(argv[2]);
	outfile.open("output1.txt");
	
	infile1 >> file1;
	infile2 >> file2;
	
	int size1 = file1.length();
	int size2 = file2.length();
	int ret[size1+1][size2+1];
	struct timeval start, end; 
	gettimeofday(&start, NULL); 
	ios_base::sync_with_stdio(false);
		for(int i = 0; i<=size1; i++){
			for(int j = 0; j<=size2; j++){
				if(i ==0 || j ==0)
					ret[i][j] = 0;
				else if(file1[i-1] == file2[j-1]){
					ret[i][j] = ret[i-1][j-1]+1;
				}
				else if(ret[i-1][j] >= ret[i][j-1]){
					ret[i][j] = ret[i-1][j];
				}
				else{
					ret[i][j] = ret[i][j-1];
				}
			}
		}
		if(size1<=10 || size2<=10){
			for(int i = 0; i<=size1; i++){
				for(int j = 0; j<=size2; j++){
					outfile << ret[i][j]<< " ";
				}
				outfile << endl;
			}
			int max = ret[size1][size2];
			char lcs[max+1];
			lcs[max] = '\0';
			int i = size1;
			int j = size2;
			while(i > 0 && j> 0){
				if(file1[i-1] == file2[j-1]){
					lcs[max-1] = file1[i-1];
					i--; j--; max--;
				}
				else if(ret[i-1][j] > ret[i][j-1])
					i--;
				else
					j--;
			}
			outfile << lcs << endl;
		}
		else
			outfile << ret[size1][size2] << endl;
		gettimeofday(&end, NULL); 
		double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
  
    outfile << "Time taken by program is : " << fixed 
         << time_taken << setprecision(6); 
    outfile << " sec" << endl;	
		
}
