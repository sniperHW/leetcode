/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
    int atoi(const char *str) {
  	for(;;){
  		if(str[0] == ' ') str = str + 1;
  		else break;
  	}
 	int len = strlen(str);
  	int sign = str[0] == '-' ? -1:1;
    int end = 0;
	if(str[0] == '-' || str[0] == '+')
		end = 1;
        int begin;
        for(begin = end; begin < len; begin++)
          if(!(str[begin] >= '0' && str[begin] <= '9')){
                break;
        }
        --begin;
        if(begin < end) return 0; 
  		int product = 0;
  	    int base = 1;
        int flag = 0;
        bool overflow = false;
  	    for(int i = begin; i >= end; --i){
  		 if(!(str[i] >= '0' && str[i] <= '9')) return 0;
                if(base != 1 && base % 10 != 0){
                  overflow = true;
                  if(sign > 0) product = 0x7FFFFFFF;
                  else product = 0x80000000;                    
                }              
              if(!overflow){
      		    product =  product + (int)(str[i] - '0')*base;
                  int newflag = product & 0x80000000;
                  if(newflag != flag){
                    overflow = true;
                    if(sign > 0) product = 0x7FFFFFFF;
                    else product = 0x80000000;
                  }
                  base *= 10;
            }
  	   }
       if(overflow)
       	return product;
       else 
        return product*sign;	
    }
};