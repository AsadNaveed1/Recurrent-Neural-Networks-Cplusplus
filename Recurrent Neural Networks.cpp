// Author :  Muhammad Asad Naveed
// U.No : 3035957848
// Assignment 1 Question 2
// Description  : make Recurrent Neural Networks program in c++



#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double e=2.72;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// Function: sigmoid activation function
// Input: double x: the input of sigmoid activation function
// Ouput: the output of sigmoid activation function
double sigmoid(double x)
{
  double valuetoreturn2;
  valuetoreturn2= (1/(1+ (pow(e,-x))));      //sigmoid value is evaluates here and rerturned

  return valuetoreturn2;



}

// Function: tanh activate function
// Input: double x: the input of tanh activation function
// Ouput: double: the output of tanh activation function.
double tanh(double x)
{
  double valuetoreturn;
  valuetoreturn= (2*sigmoid(2*x))-1;       //tanh value is evaluates here and rerturned

  return valuetoreturn;

}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  double inputvalue, outputvalue;
  inputvalue=(0.5*x)-(2*h);
  outputvalue=tanh(inputvalue);              //computes the value that is needed as an input for the tanh function


  return outputvalue;


}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  double inputvalue2, outputvalue2;

  inputvalue2=(0.1*x) + (1.5*h);
  outputvalue2= sigmoid(inputvalue2);     //computes the value that is needed as an input for the sigmoid function 

  return outputvalue2;




}

// Function: print the values stored in a 1D-array to screen
// Input: double xs[100]: the value of the sequence
//        int seq_len: the length of the sequence
void PrintSeqs(double xs[100], int seq_len)
{
  for(int i=0; i<seq_len; i++)
    cout<< fixed << showpoint << setprecision(10)<<xs[i]<<" ";  //loop to print out 
    cout<<endl;

}

// Function: main function
int main()
{
  int T,j;                                  //T denotes the reccurent times
  double ho;                                //ho denoting the initial hidden state

  double inputofx[100],outputseq[100],hiddenseq[100];    //creating arrays x depicts input sequence

  cin>>T>>ho;

  for(int x=0; x<T; ++x)
  {
    cin>>inputofx[x];
  }
  hiddenseq[0]= ComputeH(inputofx[0], ho);          //arrays are initially populated here, initial hidden state is used
  
  outputseq[0]= ComputeO(inputofx[0], ho);          //first outputseq is generated

  for(int j=1; j<T; ++j)                           //a loop for generating the remaing states
  {

    hiddenseq[j]= ComputeH(inputofx[j], hiddenseq[j-1]);
    outputseq[j]= ComputeO(inputofx[j], hiddenseq[j-1]);
    

  }

  PrintSeqs(hiddenseq, T);    //these functions print out the states and output sequences
  PrintSeqs(outputseq, T);




}
