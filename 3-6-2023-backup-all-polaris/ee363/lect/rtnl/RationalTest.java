import org.junit.Test;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
    

/**
 * Tests Rational class.
 * 
 * @author murphycd (Chris Murphy)
 * @author fhussain
 * 
 * AbsFunc: a/b
 * Invariant: b != 0
 */
public class RationalTest {

    /**
     * Test default constructor of Rational
     * which assumes a = 0 and b = 1.
     */
    @Test
    public void test1() {
	Rational rat = new Rational();
		
	// check state of rational after construction
	assertTrue(rat.numerator() == 0);
	assertTrue(rat.denominator() == 1);
    }

    /**
     * Test single argument constructor of Rational 
     * which specifies a and assumes b = 1.
     */
    @Test
    public void test2() {
	Rational rat = new Rational(7);
		
	// check internal state of rat
	assertTrue(rat.numerator() == 7);
	assertTrue(rat.denominator() == 1);
    }

    /**
     * Test two argument (primary) constructor of Rational 
     * which specifies a and b explicitly.
     */
    @Test
    public void test_rationalConstructionState() {
	Rational rat = new Rational(3, 4);
		
	// check state of rational
	assertTrue(rat.numerator() == 3);
	assertTrue(rat.denominator() == 4);
    }


   @Test
   public void test4() {
       Rational r1 = new Rational(3, -7);
       Rational r2 = new Rational(-3, 7);

       assertTrue(r1.isEqual(r2));
   }

   @Test
   public void test5() {
       Rational r1 = new Rational(-3, -7);
       Rational r2 = new Rational(3, 7);

       assertTrue("sign test", r1.isEqual(r2));
   }


   @Test
   public void test_equalityWithSign() {
       Rational r1 = new Rational(-16, 24);

       assertEquals(r1, new Rational(-2, 3)); //pass
   }


   @Test
   public void test_equalsWithSign() {
       Rational r1 = new Rational(-16, 24);

       assertEquals(r1, new Rational(2, -3));  //pass
   }

   @Test
   public void test_notEqualWithSign() {
       Rational r1 = new Rational(-16, 24);

       assertNotEquals(r1, new Rational(-2, 5)); //fail
   }

    @Test
   public void test_equalSameVal() {
	Rational r1 = new Rational(3, 7);
	Rational r2 = new Rational(3, 7);

       assertEquals(r1, r2); 
   }


    @Test
   public void test_equalSameObj() {
	Rational r1 = new Rational(3, 7);

       assertEquals(r1, r1); 
   }
    
    
    

   @Test
   public void test_equalityReduce() {
       Rational r1 = new Rational(0, 24);
       Rational r2 = new Rational(0, -3);

       assertTrue("zero num test", r1.isEqual(r2));
   }


   @Test
   public void test_reciprocalSign() {
       Rational r1 = new Rational(4, 11);
       Rational r2 = new Rational(-4, 11);

       assertFalse(r1.isEqual(r2));
   }
    

   @Test
   public void test_reciprocal() {
       Rational r1 = new Rational(18, 7);
       Rational r2 = new Rational(7, 18);

       assertTrue(r1.isEqual(r2.recip()));
   }


   @Test
   public void test_equalitySign() {
       Rational r1 = new Rational(0, 4);
       Rational r2 = new Rational(0, -4);

       assertTrue(r1.isEqual(r2));
   }



   @Test
   public void test_equalitySigns() {
       Rational r1 = new Rational(0, 4);
       Rational r2 = new Rational(-0, -4);

       assertTrue(r1.isEqual(r2));
   }


    @Test
    public void test_nonNullity() {
	Rational rnn = new Rational(0, 1);
	assertNotNull("rnn is null", rnn);
    }


    @Test(expected=RuntimeException.class)
    public void test_dbzRuntimeException1() {
	Rational dbz = new Rational(1, 0);
    }


    @Test(expected=RuntimeException.class)
    public void test_dbzRuntimeException2() {
	Rational r = new Rational(0, 0);
    }
	
}
