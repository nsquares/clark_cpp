//javac SimpleTest1.java
//java org.junit.runner.JUnitCore SimpleTest1

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class SimpleTest1 {
    @Test
    public void test1() {
	String str = "Go away corona";
	assertEquals("Go away corona", str);
    }


    @Test(expected=NullPointerException.class)
    public void test2() {
	throw new NullPointerException("Test NpE"); 

	//both works, I can either throw new or set a variable to null

	//String x = null;






	//String x = "non-null"; //test should fail
	//System.out.println(x.length());
    }
}


