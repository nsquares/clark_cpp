//    javac hw4/p1/*.java
//    java org.junit.runner.JUnitCore hw4.p1.IntSetTest

package hw4.p1;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;


public class IntSetTest {


    //The homework says to write tests based on the specification file and the specification file does not state that there needs to be a check Representation Invariant function. Thus, this function will not be used because it will be assumed that not all IntSet implementations will have that. 


    //Test 1: Testing insert method and verifying that proper data is stored in IntSet (indirectly also testing getAll method) according to specifications.
@Test
public void test1_insert_and_getAll_Methods(){

    IntSet is1 = new IntSet();

    assertEquals(is1.size(), 0); //also test the basic constructor to be empty

    is1.insert(13);               //any positive number
    is1.insert(-5);               //any negative number
    is1.insert(0);                // and zero, the specifications say frame condition (assignable: \everything)
    assertEquals(is1.size(), 3);

    int foo[] = is1.getAll();


    for(int i:foo){
	System.out.println(i);
    }

    assertEquals(foo[0], 13);
    assertEquals(foo[1], -5);
    assertEquals(foo[2], 0);
}



    //Test 2: Test removing method based on specifications and mutable property.
    @Test
    public void test2_remove_method(){

	IntSet is2 = new IntSet();
	is2.insert(1);
	is2.insert(8);
	is2.insert(-3);
	is2.insert(-4);

	assertEquals(is2.size(), 4);

	is2.remove(-3);
	is2.remove(2);

	assertEquals(is2.size(), 3);
    }


    //Test 3: Checking Abstraction function or a toString method and empty set property. 
    @Test
    public void test3_AbstractionFunction(){

	IntSet is3 = new IntSet();
	assertNotNull(is3);

	is3.insert(-59);
	is3.insert(0);
	is3.insert(31);

	assertNotNull(is3);

	System.out.println(is3);
	
	//assertEquals("{-59, 0, 31}", is3);
	//this cannot be done because this compares an object type String class to an object type IntSet class. Both objects need to be the same class type for the equals to work.

    }


    //Test 4: Check that the choose method throws EmptyException properly according to specifications.
    @Test(expected=EmptyException.class)
    public void test4_throwEmptyException(){

	IntSet is4 = new IntSet();
	assertFalse(is4.isIn(0));    //check that there is no data, indicating empty set

	int bar = is4.choose();   //throw RuntimeException
    }


}
