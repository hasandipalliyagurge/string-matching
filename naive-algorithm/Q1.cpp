#include <iostream>
#include <string>
#include <fstream>
#define MAX 100

using namespace std;

int index[MAX];
int m = 0;

void search_pattern(string parag, string pat){
    int lt = parag.length();
    int lp = pat.length();
   
	if(lt==0 || lp==0) cout<<"Empty text file or pattern file";
	else{
		for(int i=0; i<=lt-lp; i++){
        	int j=0;
        	while(parag[i+j]==pat[j] || pat[j]=='_'){
            	j++;
            	if(j==lp){
                	index[m]=i;  //m=index of an index array
                	m++;
                	break;
        		}
            
        	}
    	}
	}			
}

int main(){
	string parag,pat,textfile,patternfile,outputfile;
	
	cout<<"Enter text file name: ";
	getline(cin,textfile);		//get text file
	
	cout<<"Enter pattern file name: ";
	getline(cin,patternfile);	//get pattern file
	
	
	fstream t(textfile.c_str());      //read input text file
	fstream p(patternfile.c_str());     //read  input pattern file
	
	cout<<"Enter name for the output file: ";
    getline(cin,outputfile);                  //write output in a file
    ofstream output(outputfile.c_str());
	
	if(t.is_open()){
		if(p.is_open()){
			
			getline(t,parag);    //read string from input file
			getline(p,pat);		//read string from input file
			search_pattern(parag, pat);
    		
    		if(m!=0){
		
    		output<<"Index numbers of matched strings : ";
			for(int i=0;i<m;i++) output<<index[i]<<" ";
    		cout<<endl;
    		}
    		else output<<"No matching pattern found";
    		
    		
    	}
	}
}

