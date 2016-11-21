#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {beginLine, beginBlock, endLine, endBlock, doubleQuote, singleQuote, none} event;
typedef enum {noComment, LC, BC, DQ, SQ} state;
//--                                                                                                                                                                                           
event detect(char input[2]){

  if(input[0] == '/' && input[1] == '/'){
    return beginLine;
  }

  if(input[0] != '\\' && input[1] == '\n'){
    return endLine;
  }

  if(input[0] == '/' && input[1] == '*'){
    return beginBlock;
  }

  if(input[0] == '*' && input[1] == '/'){
    return endBlock;
  }

  if(input[0] != '\\' && input[1] == '"'){
    return doubleQuote;
  }

  if(input[0] != '\\' && input[1] == '\''){
    return singleQuote;
  }

  return none;

}

int main (void){

  char iden[2] = {0,0};
  char input;
  state state = noComment;

  while((input = getchar()) != EOF){
    iden[0] = iden[1];
    iden[1] = input;
    event current = detect(iden);
    switch(state){
      case noComment:
        if(current == beginLine){
          putchar(iden[0]);
          state = LC;
        }
        if(current == beginBlock){
          putchar(iden[0]);
          state = BC;
        }
        if(current == doubleQuote){
          state = DQ;
        }
        if(current == singleQuote){
          state = SQ;
        }
        break;
    case LC:
      if(current == endLine){
        putchar(iden[1]);
        state = noComment;
      }
      break;
    case BC:
      if(current == endBlock){
        putchar(iden[1]);
        state = noComment;
      }
      break;
    case DQ:
      if(current == doubleQuote){
        state = noComment;
      }
      break;
    case SQ:
      if(current == singleQuote){
        state = noComment;
      }
      break;
    }

    if(state == BC || state == LC){
      putchar(iden[1]);
    }
  }

  return(EXIT_SUCCESS);

}

