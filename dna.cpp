#include <iostream>
#include<fstream>//filestream
#include<cmath>//cmath
#include<string>
#include<random>//radomD
using namespace std;
int main(int argc, char const *argv[]) {
  /* code */

  ofstream output("ericLim.out");
  output << "Eric Lim\n2295713\nAssignment 1\n\n";


  string filename = "";
  string providedDNA = "";
  string line = "";

  int A=0;
  int C=0;
  int T=0;
  int G=0;
  int AC=0, AT=0, AG=0, CA=0, CT=0, CG=0, TA=0, TC=0, TG=0, GA=0, GC=0, GT=0, AA=0, GG=0, TT=0, CC=0;
  int stringnumb=0, lens=0; //stirngnumb is the number of strings
  double mean=0, sum=0, variance=0, stddev=0, two=0;
  double probA, probC, probT, probG, probAA, probAC, probAT, probAG, probCC, probCA, probCT, probCG, probTT, probTA, probTC, probTG, probGG, probGA, probGC, probGT;
  filename = argv[1];//from command prompt
  ifstream inputDNA;
  inputDNA.open(filename);
  if(inputDNA.is_open()){
    while(getline(inputDNA,line)){//returns a false value if reached an illegal input(empty string)
      if(line.length()%2==1){
        cout<<"illegal dna strand\n";
        return 0;
      }
      for(int i=0;i<line.length();i=i+2){
        line[i]=(toupper(line[i]));
        line[i+1]=toupper(line[i+1]);
        if(line.substr(i,2)=="AC"){
          A++;
          C++;
          AC++;
          two++;
        }else if(line.substr(i,2)=="AT"){
          A++;
          T++;
          AT++;
          two++;
        }else if(line.substr(i,2)=="AG"){
          A++;
          G++;
          AG++;
          two++;
        }else if(line.substr(i,2)=="CA"){
          C++;
          A++;
          CA++;
          two++;
        }else if(line.substr(i,2)=="CT"){
          C++;
          T++;
          CT++;
          two++;
        }else if(line.substr(i,2)=="CG"){
          C++;
          G++;
          CG++;
          two++;
        }else if(line.substr(i,2)=="TA"){
          T++;
          A++;
          TA++;
          two++;
        }else if (line.substr(i,2)=="TC") {
          T++;
          C++;
          TC++;
          two++;
        }else if(line.substr(i,2)=="TG"){
          T++;
          G++;
          TG++;
          two++;
        }else if(line.substr(i,2)=="GA"){
          G++;
          A++;
          GA++;
          two++;
        }else if(line.substr(i,2)=="GC"){
          G++;
          C++;
          GC++;
          two++;
        }else if(line.substr(i,2)=="GT"){
          G++;
          T++;
          GT++;
          two++;
        }else if(line.substr(i,2)=="AA"){
          AA++;
          A+=2;
          two++;
        }else if(line.substr(i,2)=="GG"){
          GG++;
          G+=2;
          two++;
        }else if(line.substr(i,2)=="TT"){
          TT++;
          T+=2;
          two++;
        }else if(line.substr(i,2)=="CC"){
          CC++;
          C+=2;
          two++;
        }
      }
      providedDNA = providedDNA + line;//gets the line and adds to a big string
      stringnumb++;
    }
    sum = A+C+T+G;
    mean = sum/stringnumb;
  }else{
    cout<<"unable to open file\n";
    return 0;
  }
  inputDNA.close();//just to clear the cursor to read them again
  inputDNA.clear();
  inputDNA.open(filename);
  while(getline(inputDNA,line)){//calculate variance
    double diff = line.length()-mean;
    diff = pow(diff,2);
    variance=variance+diff;
  }
  probA = A/sum;
  probC = C/sum;
  probT = T/sum;
  probG = G/sum;
  probAT = AT/two;
  probAG = AG/two;
  probAC = AC/two;
  probCA = CA/two;
  probCT = CT/two;
  probCG = CG/two;
  probTA = TA/two;
  probTC = TC/two;
  probTG = TG/two;
  probGA = GA/two;
  probGC = GC/two;
  probGT = GT/two;
  probAA = AA/two;
  probCC = CC/two;
  probGG = GG/two;
  probTT = TT/two;
  variance=variance/stringnumb;
  stddev=sqrt(variance);
  output << "Sum = " << sum <<"\n";
  output << "Mean = " << mean <<"\n";
  output << "Variance = " << variance <<"\n";
  output << "Standard Deviation = " << stddev <<"\n\n";

  output << "Probability of: \n";
  output << "A = " << probA<<"\n";
  output << "C = " << probC<<"\n";
  output << "T = " << probT<<"\n";
  output << "G = " << probG<<"\n";
  output << "AA = " << probAA<<"\n";
  output << "AC = " << probAC<<"\n";
  output << "AT = " << probAT<<"\n";
  output << "AG = " << probAG<<"\n";
  output << "CA = " << probCA<<"\n";
  output << "CC = " << probCC<<"\n";
  output << "CT = " << probCT<<"\n";
  output << "CG = " << probCG<<"\n";
  output << "TA = " << probTA<<"\n";
  output << "TC = " << probTC<<"\n";
  output << "TT = " << probTT<<"\n";
  output << "TG = " << probTG<<"\n";
  output << "GA = " << probGA<<"\n";
  output << "GC = " << probGC<<"\n";
  output << "GT = " << probGT<<"\n";
  output << "GG = " << probGG<<"\n\n1000 DNA Strings:\n";

  /*Make the probablilties a whole number in order to make generating 1000 dna sequences easier*/
  probAT = round((AT/two)*100);
  probAG = round((AG/two)*100);
  probAC = round((AC/two)*100);
  probCA = round((CA/two)*100);
  probCT = round((CT/two)*100);
  probCG = round((CG/two)*100);
  probTA = round((TA/two)*100);
  probTC = round((TC/two)*100);
  probTG = round((TG/two)*100);
  probGA = round((GA/two)*100);
  probGC = round((GC/two)*100);
  probGT = round((GT/two)*100);
  probAA = round((AA/two)*100);
  probGG = round((GG/two)*100);
  probCC = round((CC/two)*100);
  probTT = round((TT/two)*100);
  //output<<probAT+probAG+probAC+probCA+probCT+probCG+probTA+probTC+probTG+probGA+probGC+probGT+probAA+probGG+probCC+probTT;

  for(int i=0; i<1000; ++i){
    double a = ((double)rand()/RAND_MAX);//get rand 0-1
    double b = ((double)rand()/RAND_MAX);
    double c = (sqrt(-2.0*log(a)))*(cos(2.0*M_PI*b));
    double dist = (stddev*c)+mean;//get gaussian distribution
    //output<<dist;
    if(dist < 0){//it gave me negative values so im just gonna skip them
      i--;
      continue;
    }
    int rounded = round(dist/2);//this will give us generated number/2, because DNAs come in pairs.
    if(rounded!=0){
      for(int j=0;j<rounded;j++){//Here I generate DNA sequences according to the probabilities
        int seq = (rand()%100)+1;//a random number generated from 1~100.
        //output<<seq<<",";
        //here, we will be using the probabilities that were converted into a whole number
        //if probAA was 80%, 80% of the DNA should be AA. So, we'll be simply printing out all of the numbers under 80 to be DNA AA.
        //this applies to everything else - this will ensure that the distribution of all the DNA pairs are as inputted.
        //here, we make use of the characteristics of the if statement; the if statement checks from the top and exits the if/else if executed an option.
        if(seq<probAA){
          output<<"AA";
        }else if(seq<(probAA+probAT)){
          output<<"AT";
        }else if(seq<(probAA+probAT+probAC)){
          output<<"AC";
        }else if(seq<(probAA+probAT+probAC+probAG)){
          output<<"AG";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA)){
          output<<"TA";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT)){
          output<<"TT";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC)){
          output<<"TC";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG)){
          output<<"TG";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA)){
          output<<"CA";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT)){
          output<<"CT";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC)){
          output<<"CC";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG)){
          output<<"CG";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA)){
          output<<"GA";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA+probGT)){
          output<<"GT";
        }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA+probGT+probGC)){
          output<<"GC";
        }else{
          output<<"GG";
        }
      }
      output<<"\n";
    }else{
      i--;
      continue;
    }
  }
  std::cout << "Process another list? [yes/no]" << '\n';
  string answer = "";
  cin>>answer;
  if(answer=="yes"){
    output<<"\n\n\n\n";
    string filename = "";
    string providedDNA = "";
    string line = "";

    int A=0;
    int C=0;
    int T=0;
    int G=0;
    int AC=0, AT=0, AG=0, CA=0, CT=0, CG=0, TA=0, TC=0, TG=0, GA=0, GC=0, GT=0, AA=0, GG=0, TT=0, CC=0;
    int stringnumb=0, lens=0; //stirngnumb is the number of strings
    double mean=0, sum=0, variance=0, stddev=0, two=0;
    double probA, probC, probT, probG, probAA, probAC, probAT, probAG, probCC, probCA, probCT, probCG, probTT, probTA, probTC, probTG, probGG, probGA, probGC, probGT;

    std::cout << "Enter a file name:" << '\n';
    std::cin >> filename;;//from command input
    ifstream inputDNA;
    inputDNA.open(filename);
    if(inputDNA.is_open()){
      while(getline(inputDNA,line)){//returns a false value if reached an illegal input(empty string)
        if(line.length()%2==1){
          cout<<"illegal dna strand\n";
          return 0;
        }
        for(int i=0;i<line.length();i=i+2){
          line[i]=(toupper(line[i]));
          line[i+1]=toupper(line[i+1]);
          if(line.substr(i,2)=="AC"){
            A++;
            C++;
            AC++;
            two++;
          }else if(line.substr(i,2)=="AT"){
            A++;
            T++;
            AT++;
            two++;
          }else if(line.substr(i,2)=="AG"){
            A++;
            G++;
            AG++;
            two++;
          }else if(line.substr(i,2)=="CA"){
            C++;
            A++;
            CA++;
            two++;
          }else if(line.substr(i,2)=="CT"){
            C++;
            T++;
            CT++;
            two++;
          }else if(line.substr(i,2)=="CG"){
            C++;
            G++;
            CG++;
            two++;
          }else if(line.substr(i,2)=="TA"){
            T++;
            A++;
            TA++;
            two++;
          }else if (line.substr(i,2)=="TC") {
            T++;
            C++;
            TC++;
            two++;
          }else if(line.substr(i,2)=="TG"){
            T++;
            G++;
            TG++;
            two++;
          }else if(line.substr(i,2)=="GA"){
            G++;
            A++;
            GA++;
            two++;
          }else if(line.substr(i,2)=="GC"){
            G++;
            C++;
            GC++;
            two++;
          }else if(line.substr(i,2)=="GT"){
            G++;
            T++;
            GT++;
            two++;
          }else if(line.substr(i,2)=="AA"){
            AA++;
            A+=2;
            two++;
          }else if(line.substr(i,2)=="GG"){
            GG++;
            G+=2;
            two++;
          }else if(line.substr(i,2)=="TT"){
            TT++;
            T+=2;
            two++;
          }else if(line.substr(i,2)=="CC"){
            CC++;
            C+=2;
            two++;
          }
        }
        providedDNA = providedDNA + line;//gets the line and adds to a big string
        stringnumb++;
      }
      sum = A+C+T+G;
      mean = sum/stringnumb;
    }else{
      cout<<"unable to open file\n";
      return 0;
    }
    inputDNA.close();//just to clear the cursor to read them again
    inputDNA.clear();
    inputDNA.open(filename);
    while(getline(inputDNA,line)){//calculate variance
      double diff = line.length()-mean;
      diff = pow(diff,2);
      variance=variance+diff;
    }
    probA = A/sum;
    probC = C/sum;
    probT = T/sum;
    probG = G/sum;
    probAT = AT/two;
    probAG = AG/two;
    probAC = AC/two;
    probCA = CA/two;
    probCT = CT/two;
    probCG = CG/two;
    probTA = TA/two;
    probTC = TC/two;
    probTG = TG/two;
    probGA = GA/two;
    probGC = GC/two;
    probGT = GT/two;
    probAA = AA/two;
    probCC = CC/two;
    probGG = GG/two;
    probTT = TT/two;
    variance=variance/stringnumb;
    stddev=sqrt(variance);
    output << "Sum = " << sum <<"\n";
    output << "Mean = " << mean <<"\n";
    output << "Variance = " << variance <<"\n";
    output << "Standard Deviation = " << stddev <<"\n\n";

    output << "Probability of: \n";
    output << "A = " << probA<<"\n";
    output << "C = " << probC<<"\n";
    output << "T = " << probT<<"\n";
    output << "G = " << probG<<"\n";
    output << "AA = " << probAA<<"\n";
    output << "AC = " << probAC<<"\n";
    output << "AT = " << probAT<<"\n";
    output << "AG = " << probAG<<"\n";
    output << "CA = " << probCA<<"\n";
    output << "CC = " << probCC<<"\n";
    output << "CT = " << probCT<<"\n";
    output << "CG = " << probCG<<"\n";
    output << "TA = " << probTA<<"\n";
    output << "TC = " << probTC<<"\n";
    output << "TT = " << probTT<<"\n";
    output << "TG = " << probTG<<"\n";
    output << "GA = " << probGA<<"\n";
    output << "GC = " << probGC<<"\n";
    output << "GT = " << probGT<<"\n";
    output << "GG = " << probGG<<"\n\n1000 DNA Strings:\n";

    /*Make the probablilties a whole number in order to make generating 1000 dna sequences easier*/
    probAT = round((AT/two)*100);
    probAG = round((AG/two)*100);
    probAC = round((AC/two)*100);
    probCA = round((CA/two)*100);
    probCT = round((CT/two)*100);
    probCG = round((CG/two)*100);
    probTA = round((TA/two)*100);
    probTC = round((TC/two)*100);
    probTG = round((TG/two)*100);
    probGA = round((GA/two)*100);
    probGC = round((GC/two)*100);
    probGT = round((GT/two)*100);
    probAA = round((AA/two)*100);
    probGG = round((GG/two)*100);
    probCC = round((CC/two)*100);
    probTT = round((TT/two)*100);
    //output<<probAT+probAG+probAC+probCA+probCT+probCG+probTA+probTC+probTG+probGA+probGC+probGT+probAA+probGG+probCC+probTT;

    for(int i=0; i<1000; ++i){
      double a = ((double)rand()/RAND_MAX);//get rand 0-1
      double b = ((double)rand()/RAND_MAX);
      double c = (sqrt(-2.0*log(a)))*(cos(2.0*M_PI*b));
      double dist = (stddev*c)+mean;//get gaussian distribution
      //output<<dist;
      if(dist < 0){//it gave me negative values so im just gonna skip them
        i--;
        continue;
      }
      int rounded = round(dist/2);//this will give us generated number/2, because DNAs come in pairs.
      if(rounded!=0){
        for(int j=0;j<rounded;j++){//Here I generate DNA sequences according to the probabilities
          int seq = (rand()%100)+1;//a random number generated from 1~100.
          //output<<seq<<",";
          //here, we will be using the probabilities that were converted into a whole number
          //if probAA was 80%, 80% of the DNA should be AA. So, we'll be simply printing out all of the numbers under 80 to be DNA AA.
          //this applies to everything else - this will ensure that the distribution of all the DNA pairs are as inputted.
          //here, we make use of the characteristics of the if statement; the if statement checks from the top and exits the if/else if executed an option.
          if(seq<probAA){
            output<<"AA";
          }else if(seq<(probAA+probAT)){
            output<<"AT";
          }else if(seq<(probAA+probAT+probAC)){
            output<<"AC";
          }else if(seq<(probAA+probAT+probAC+probAG)){
            output<<"AG";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA)){
            output<<"TA";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT)){
            output<<"TT";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC)){
            output<<"TC";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG)){
            output<<"TG";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA)){
            output<<"CA";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT)){
            output<<"CT";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC)){
            output<<"CC";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG)){
            output<<"CG";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA)){
            output<<"GA";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA+probGT)){
            output<<"GT";
          }else if(seq<(probAA+probAT+probAC+probAG+probTA+probTT+probTC+probTG+probCA+probCT+probCC+probCG+probGA+probGT+probGC)){
            output<<"GC";
          }else{
            output<<"GG";
          }
        }
        output<<"\n";
      }else{
        i--;
        continue;
      }
    }
  }else{
    std::cout << "exiting" << '\n';
  }
  return 0;
}
