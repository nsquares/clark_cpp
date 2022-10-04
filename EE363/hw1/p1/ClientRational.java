package hw1.p1;

public class ClientRational {

public static void main(String[] args) {
		Rational r1 = new Rational(5, 6);
		Rational r2 = new Rational(3, 4);
		System.out.println("r1: " + r1);
		System.out.println("r2: " + r2);

		Rational rsum = r1.plus(r2);
		System.out.println("r1 + r2: " + rsum);
		
		Rational rdiff = r1.minus(r2);
		System.out.println("r1 - r2: " + rdiff);
		
		Rational rprod = r1.times(r2);
		System.out.println("r1 * r2: " + rprod);
		
		Rational rquot = r1.divides(r2);
		System.out.println("r1 / r2: " + rquot);


		System.out.println();

		System.out.println("[Rational cr1 = r1;]");
		Rational cr1 = r1;
		System.out.println("cr1: " + cr1);
		

		Rational n5 = new Rational(7, 8);
		System.out.println("[Rational n5 = new Rational(7, 8);]");
		System.out.println("r1: " + r1);
		System.out.println("n5: " + n5);		
		System.out.println("r1 equals cr1: " + r1.equals(cr1));
		System.out.println("r1 equals n5: " + r1.equals(n5));
		System.out.println();

		//another equals test (test contents, not just references)		
		Rational cr2 = new Rational(5, 6);
		System.out.println("[Rational cr2 = new Rational(5, 6);]");
		System.out.println("r1: " + r1);
		System.out.println("cr2: " + cr2);		
		System.out.println("r1 equals cr2: " + r1.equals(cr2));
		System.out.println();
				


		Rational r2plusn5 = r2.plus(n5);
		Rational res_r2plusn5 = new Rational(15, 8);
		System.out.println("r2 + n5: "+ r2plusn5); 
		System.out.println("res_r2plusn5: " + r2plusn5);
		
		//use VM flag '-ea' to cause overflow exception
		System.out.println("\nOverflow test:");
		System.out.println("Integer.MAX_VALUE: " + Integer.MAX_VALUE);
		Rational r3 = new Rational(Integer.MAX_VALUE, 3);
		Rational r4 = new Rational(10,1);
		System.out.println("r3: " + r3);
		System.out.println("r4: " + r4);
		System.out.println("Will attempt r3*r4 ...");
		Rational ofl = r3.times(r4);
		System.out.println("r3*r4 = " + ofl);
	}

}
