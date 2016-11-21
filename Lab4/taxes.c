#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------       
double getInputs(double * income, double * deductions){

  double input;

  do {
    printf("Enter next amount : ");
    scanf("%lf", &input);
    if(input > 0){
      *income += input;
    } else {
      *deductions += abs(input);
    }
  } while (input != 0);

  return(EXIT_SUCCESS);

}
//----------------------------------------------------------------------             
double computeTaxableIncome(double income, double deductions){

  double taxableInc;

  if(income > deductions){
    taxableInc = (income - deductions);
  } else {
    taxableInc = 0;
  }

  return(taxableInc);

}
//---------------------------------------------------------------------         
char  findTaxGroup (double taxableInc){

  if(taxableInc >= 500000){
    return('S');
  } else if (taxableInc >= 200000){
    return('Q');
  } else if (taxableInc >= 100000){
    return('M');
  } else if (taxableInc >= 50000){
    return('A');
  } else if (taxableInc >= 20000){
    return('R');
  } else {
    return('P');
  }
}
//-----------------------------------------------------------------------       
double computeTax(char taxGroup, double taxableInc){

  double tax;

  if(taxGroup == 'S' || taxGroup == 'Q'){
    tax = 0.25 * taxableInc;
  } else if (taxGroup == 'M'){
    tax = 0.10 * taxableInc;
  } else if (taxGroup == 'A' || taxGroup == 'R'){
    tax = 0.03 * taxableInc;
  } else if (taxGroup == 'P'){
    tax = 0;
  } else {
    printf("There was an error. Improper tax group.");
  }

  if(tax > 50000){
    tax = 50000;
  }

  return tax;

}
//-------------------------------------------------------------------------     
int printOutput(double income, double deductions, double taxableInc, char taxGr\
oup, double taxOwed){

  printf("\nIncome         = $%8.2f\n", income);
  printf("Deductions     = $%8.2f\n", deductions);
  printf("Taxable Income = $%8.2f\n", taxableInc);
  printf("Tax group      = %c\n", taxGroup);
  printf("Tax owed       = $%8.2f\n", taxOwed);

  return(EXIT_SUCCESS);

}
//--------------------------------------------------------------------------    
int main(void){

  double income;
  double deductions;
  double taxableInc;
  char taxGroup;
  double taxOwed;

  getInputs(&income, &deductions);
  taxableInc = computeTaxableIncome(income,deductions);
  taxGroup = findTaxGroup(taxableInc);
  taxOwed = computeTax(taxGroup, taxableInc);
  printOutput(income, deductions, taxableInc, taxGroup, taxOwed);

  return(EXIT_SUCCESS);

}
//---------------------------------------------------------------------------  
