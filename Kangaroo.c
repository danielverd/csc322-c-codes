//-----------------------------------------------------                         
#include <stdio.h>
#include <stdlib.h>

#define ROADKILL_CONSTANT 1.47
#define ROAD_WIDTH 0.010
//-----------------------------------------------------                         
int main(void) {

  float landLength;
  int roadLength;
  int kangaroos;
  float landArea;
  float kangaroosPerKM;
  float roadArea;
  float kills;

  printf("Enter side of square in km  : ");
  scanf("%f", &landLength);
  printf("Enter roads length in km    : ");
  scanf("%d", &roadLength);
  printf("Enter number of 'roos       : ");
  scanf("%d", &kangaroos);

  landArea = landLength * landLength;
  kangaroosPerKM = kangaroos / landArea;

  roadArea = roadLength * ROAD_WIDTH;

  kills = roadArea * kangaroosPerKM * ROADKILL_CONSTANT;

  printf("Expected number of kills is : %2.1f\n", kills);

  return(EXIT_SUCCESS);

}
//---------------------------------------------------------   
