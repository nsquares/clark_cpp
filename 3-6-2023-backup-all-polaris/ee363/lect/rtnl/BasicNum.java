public class  BasicNum {

    //@ exceptional_behavior
    //@ requires x == 0 && y == 0
    //@ signals_only:  ZeroException (a user-defined, checked exception)
    //@ signals (ZeroException e) true
    //@ also
    //@ normal_behavior
    //@ requires: ! (x==0 && y == 0), i.e. one of the arguments may be zero, but not both    
    //@ ensures: \result = gcd of x and y.
    public static int  gcd(int x, int y) throws ZeroException {
	if (x == 0 && y == 0)
	    throw new ZeroException("gcd: both arguments can't be zero.");
	
	if (x < 0)
	    x = -x;

	if (y < 0)
	    y = -y;

	while (y != 0) {	    
	    int rem = x % y;
	    x = y;
	    y = rem;
	}
	return x;
    }
}
