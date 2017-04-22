/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    
    int reverse(const char *input,char *output){
    	if(*input == 0)
    		return 0;
    	else{
    		int index = reverse(input+1,output);
    		output[index] = input[0];
    		return index + 1;
    	}
    }

    int reverse(int x) {
        char input[32];
        char output[32];
        snprintf(input,32,"%d",x);
        const char *inptr = &input[0];
        int sign = 1;
        if(x < 0){
        	sign = -1;
        	inptr = &input[1];
        }
        int len = reverse(inptr,output);
        output[len] = 0;
        int val = atoi(output);

        const char *outptr = &output[0];
        for(int i = 0; i < len; ++i){
        	if(*outptr == '0') outptr++;
        	else break;
        }
        snprintf(input,32,"%d",val);
        if(string(input) != string(outptr))
        	return 0;
        else
        	return val*sign;
    }
};
