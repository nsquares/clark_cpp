//shared with students


#include <stdio.h>
#include "mth3.h"

int main(void) {
  const int NUM  = 11;

  int nums[] = {
		1327,
		1331, //no
		//1329, //no
		2801,
		26459,
		27069, //no
		761,
		809,
		2621,
		40849,
		33997,
		//8, no
		16 // no
  };

  int failures = 0;
  for (int i = 0; i < NUM; i++) {
    if (!isPrime(nums[i])) {
      printf("%d: ", nums[i]);
      failures++;
      printFactors(nums[i]);
      printf("\n");
    }
  }


  printf("#non-primes: %d\n", failures);
	 
  return 0;
}


