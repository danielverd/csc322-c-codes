//----------------------------------------------                                
#include <stdio.h>
#include <stdlib.h>

#define FEET_PER_ATM 33
#define MAXIMAL_PRESSURE 1.4
#define CONTINGENCY_PRESSURE 1.6
//----------------------------------------------                                
int main(void){

  int depth;
  int o2Percent;
  float ambientPressure;
  float partialPressure;
  char oxygenGroup;

  printf("Enter depth and percentage O2   : ");
  scanf("%d %d", &depth, &o2Percent);

  ambientPressure = (float)(depth / FEET_PER_ATM)+1;
  partialPressure =((float) o2Percent)/100 * ambientPressure;
  oxygenGroup =(char)(((int)(partialPressure*10)) + 65);

  printf("\nAmbient pressure                : %2.1f\n", ambientPressure);
  printf("O2 pressure                     : %3.2f\n", partialPressure);
  printf("O2 group                        : %c\n\n\n", oxygenGroup);

  if(partialPressure > MAXIMAL_PRESSURE){
    printf("\nExceeds maximal O2 pressure     : true\n");
  } else {
    printf("\nExceeds maximal O2 pressure     : false\n");
  }

  if(partialPressure > CONTINGENCY_PRESSURE){
    printf("Exceeds contingency O2 pressure : true\n");
  } else {
    printf("Exceeds contingency O2 pressure : false\n");
  }

  return(EXIT_SUCCESS);

}
//-----------------------------------------------------------------------       
