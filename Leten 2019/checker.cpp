/* the checker has three arguments:
   - first - name of the input file
   - second - name of the correct_output file
   - third - name of the contestant_output file */
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const static int MAX_TESTS = 5;
const static int MAX_N = 200;
static char corridors[MAX_TESTS][MAX_N + 1];
static int corridorLength[MAX_TESTS];

string message[] = { "Step limit exceeded!\n",
                     "Different set_memory call history on identical tests!\n",
                     "set_memory call limit exceeded!\n",
                     "Wrong answer!\n",
                     "Invalid step!\n",
                     "Different step history on identical tests!\n",
                     "Different set_memory call history on identical tests!\n",
                     "No answer!\n" };
int main (int argc, char** argv) {
    FILE *in1,*out1,*out=stdout,*err=stderr;
    int num,numberOfTests;
    if (argc<2) {
       fprintf(out,"0\n");
       fprintf(err,"The checker needs arguments!\n");
       return 0;
       }
    if (argc<3) {
       fprintf(out,"0\n");
       fprintf(err,"The checker needs input_file and output_file\n");
       return 0;
       }
    in1=fopen(argv[1],"rt");
    if (!in1) {
       fprintf(out,"0\n");
       fprintf(err,"Could not open input file!\n");
       return 0;
       }
    out1=fopen(argv[2],"rt");
    if (!out1) {
       fprintf(out,"0\n");
       fprintf(err,"Could not open output file!\n");
       return 0;
       }
    if (fscanf(out1,"%d",&num)==EOF) {
       fprintf(out,"0\n");
       fprintf(err,"No numbers in output!\n");
       return 0;
       }
    if (num<=0) {
       fprintf(out,"0\n");
       if (num>=-7) fprintf(err,"%s",message[-num].c_str());
       else fprintf(err,"Wrong answer!\n");
       return 0;
       }
    fscanf(in1,"%d%d",&numberOfTests,&numberOfTests);
    for (int i=0; i<numberOfTests; i++) {
        fscanf(in1,"%s",&corridors[i]);
        corridorLength[i]=strlen(corridors[i]);
        }
    long long int hashCode=0;
    const long long mod=1e9+7;
    for (int i=0; i<numberOfTests; i++) {
        hashCode=(hashCode*3301+corridorLength[i])%mod;
        }
    hashCode=((hashCode*685008889LL)+874362901LL)%mod+1;
    if (num!=hashCode) {
       fprintf(out,"0\n");
       fprintf(err,"Don't cheat!\n");
       return 0;
       }
    fprintf(out,"1\n");
    fprintf(err,"OK!\n");
    return 0;
}
