//Nathan Nguyen
//EE 363
//HW 1

package hw1.p1;

//immutable, internal fields/data do not change once constructed
public class Rational { 
  //handles/throws divison by zero by never creating a rational if den equals zero
  //and assert memory overflow in every public member function
  //underflow is not checked nor specified in homework 1

    //private data members of the class
    private final int num;
    private final int den; 
      
    //local helper method to keep rational in lowest form
    private static int gcd(int p, int q) { 
	    
      if(q==0) return p;
	    int r = p % q;
	    return gcd(q,r);    //Euclid's algorithm, from Java textbook
    }

    
    //constructor for class
    public Rational(int numerator, int denominator) { 
	          
      //throw runtime exception, this is unchecked so no need for throws clause
      if(denominator == 0){
        throw new ArithmeticException("Setting up a rational with division by zero is not allowed");
      }
 
      int common = gcd(numerator, denominator);
      //try reducing into lowest form, 
      //this does not need to be a function because the class is immutable 
      //and every member function will return a new instance of Rational 
      //so this is the one and only needed check, same for denominator == zero.
      //The definition of rational number is that denominator cannot equal zero.

    
      //Want numerator to always have the negative sign.
      
      //If both num and den are negative, this can also handle that.

      //Also noticed that the common variable can be a negative number from gcd and 
      //can influence the denominator to hold the negative for the Rational during final division in this constructor.
      if((0>denominator) || (common < 0)){ 
         numerator *= (-1);
         denominator *= (-1);
      }
  
      num = numerator/common;
      den = denominator/common;      
    }

    //sum of this (receiving object) and b together,
    //return a new Rational object because immutable
    public Rational plus(Rational b) { 
      
      long num1 = this.num;
      long num2 = b.num;

      long den1 = this.den;
      long den2 = b.den;

      long newNum = (num1*den2) + (num2*den1);
      long newDen = den1*den2;

      //check num overflow
      assert newNum<Integer.MAX_VALUE : "Overflow detected";
      //check den overflow
      assert newDen<Integer.MAX_VALUE : "Overflow detected";
      return new Rational((int)newNum,(int)newDen); 
    }

    //difference of this (receiving object) and b together,
    //return a new Rational object because immutable
    public Rational minus(Rational b) { 
      
      long num1 = this.num;
      long num2 = b.num;

      long den1 = this.den;
      long den2 = b.den;

      long newNum = (num1*den2) - (num2*den1);
      long newDen = den1*den2;

      //check num overflow
      assert newNum<Integer.MAX_VALUE : "Overflow detected";
      //check den overflow
      assert newDen<Integer.MAX_VALUE : "Overflow detected";
      return new Rational((int)newNum,(int)newDen); 
    }
    
    //product of this (receiving object) and b together,
    //return a new Rational object because immutable
    public Rational times(Rational b) { 
      
      long newNum = (long)this.num * (long)b.num;
      long newDen = (long)this.den * (long)b.den;      

      //check num overflow
      assert newNum<Integer.MAX_VALUE : "Overflow detected";
      //check den overflow
      assert newDen<Integer.MAX_VALUE : "Overflow detected";
      return new Rational((int)newNum,(int)newDen); 
    } 

    //quotient of this (receiving object) and b together,
    //return a new Rational object because immutable
    public Rational divides(Rational b) { 
      
      long newNum = (long)this.num * (long)b.den;
      long newDen = (long)this.den * (long)b.num;      
      
      //check num overflow
      assert newNum<Integer.MAX_VALUE : "Overflow detected";
      //check den overflow
      assert newDen<Integer.MAX_VALUE : "Overflow detected";
      return new Rational((int)newNum,(int)newDen); 
    }
    
    //give boolean if this (receiving object) is equal to b (value-wise)
    public boolean equals(Rational b) { 
      
      if((this.num == b.num) && (this.den == b.den)){  
        
        //it is assumed that both are in the lowest form 
        //because of the constructor and immutable
        return true;
      }
      else{
        return false;  
      }      
    }

    //for printing and overloading/overrriding what the Object superclass has for toString()
    public String toString() { 

      return (num+"/"+den);
    }
}
