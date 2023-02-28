// // public class FinalPrac {
// //   public static void main(String[] args){

// //     Integer[] i1 = {5};
// //     Integer[] i2 = {3};

// //     //int i4 = 3;

// //     System.out.println(i1);  //5
// //     System.out.println(i2);  //3

// //     i2 = i1;  //give memory address so now both point to the same memory, thanks Java

// //     System.out.println(i1);  //5
// //     System.out.println(i2);  //5

// //     i1[0] = 25;

// //     System.out.println(i1);  //25
// //     System.out.println(i2);  //25?????????

// //   }


// // }


// //demonstrate mutability 
// //demonstrate shared array objects 
// //https://docs.oracle.com/javase/8/docs/api/java/util/Arrays.html

// import java.util.Arrays;

// public class FinalPrac {
//     public static void main(String[] args) {
// 	System.out.println("Testing mutability and sharing in arrays:\n");
// 	int[] arr = {10, 0, -100, 50, 1, 1, 2000, 74};
// 	int[] secarr;

// 	//secarr and arr refer to the same object
// 	secarr = arr;

// 	System.out.println("Initial state of arr and secarr:");
// 	System.out.println("arr: " + Arrays.toString(arr));
// 	System.out.println("secarr: " + Arrays.toString(secarr));
// 	System.out.println("(just) arr: " + arr.hashCode());
// 	System.out.println("secarr == arr? ... " + (secarr == arr) + "\n");
	

// 	//System.out.println("\n");
// 	arr[2] = 200;

// 	// //the only negative value was changed to 200
// 	// //this shows that arr is mutable
// 	// //note also that the change was reflected in secarr, as it refers to the same object as arr

// 	System.out.println("\nState of arr and secarr after assinging 200 to arr[2]:");
// 	System.out.println("arr: " + Arrays.toString(arr));
// 	System.out.println("secarr: " + Arrays.toString(secarr));
// 	System.out.println("secarr == arr? ... " + (secarr == arr) + "\n");



// 	int[] thirdarr = {0, 0, -1, 1, 0};        		

// 	//secarr will now refer to the object pointed to by thirdarr
// 	secarr = thirdarr;
	
// 	System.out.println("\nState after 'secarr = thirdarr': ");
// 	System.out.println("arr: " + Arrays.toString(arr));
// 	System.out.println("secarr: " + Arrays.toString(secarr));
// 	System.out.println("thirdarr: " + Arrays.toString(thirdarr));	
// 	System.out.println("secarr == arr? ... " + (secarr == arr));
// 	System.out.println("secarr == thirdarr? ... " + (secarr == thirdarr));



// 	// // //creating a new object
// 	int[] copyOfarr = Arrays.copyOf(arr, arr.length);	
// 	System.out.println("\n\narr: " + Arrays.toString(arr));
// 	System.out.println("copyOfarr: " + Arrays.toString(copyOfarr));

// 	System.out.println("secarr: " + Arrays.toString(secarr));
// 	System.out.println("thirdarr: " + Arrays.toString(thirdarr));	

// 	System.out.println("copyOfarr == arr? ... " + (copyOfarr == arr));
// 	System.out.println("secarr == arr? ... " + (secarr == arr));
// 	System.out.println("secarr == thirdarr? ... " + (secarr == thirdarr));	
//     }

// }


//demonstrate mutability and immutability
//demonstrate shared objects
//discuss Object.equals(); Object.hashCode()

//Note: Read section 2.3 of the textbook (ISBN: 0201657686)

import java.util.Arrays;

public class FinalPrac {
    public static void main(String[] args) {
	System.out.println("Demonstrate immutability and sharing using String objects.\n");


	System.out.println("Testing String objects with String.concat:");
	String s1 = "a simple string. ";
	String cs1 = s1;
	String s2 = "(enhancement)";

	System.out.println("\nInitial state of s1, cs1, and s2:");
	System.out.println("s1: " + s1);
	System.out.println("cs1: " + cs1);
	//System.out.println("s1 hc: " + s1.hashCode());
	//System.out.println("cs1 hc: " + cs1.hashCode());
	System.out.println("s2: " + s2);
	System.out.println("s1 == cs1? ..." + (s1==cs1));

	// //https://docs.oracle.com/javase/8/docs/api/java/lang/Object.html#equals-java.lang.Object-
	System.out.println("s1.equals(cs1)? ..." + (s1.equals(cs1)));
	System.out.println("do and print s1.concat(s2): " + s1.concat(s2));
	// //s1 was not modified by the concatenation operation
	System.out.println("\nPost concatenation state of s1, cs1, and s2:");
	 System.out.println("s1: " + s1);
	System.out.println("cs1: " + cs1);
	System.out.println("s2: " + s2);		
	System.out.println("s1 == cs1? ..." + (s1==cs1));
	 System.out.println("s1.equals(cs1)? ..." + (s1.equals(cs1)));
	


	System.out.println("\n\nTesting String objects with operator '+':");
	String t1 = "Don't mind if I do. ";
	String ct1 = t1;
	String t2 = "Hurricane!";
	
	System.out.println("\nInitial state of t1, ct1, and t2:");
	System.out.println("t1: " + t1);
	System.out.println("ct1: " + ct1);
	System.out.println("t2: " + t2);		
	System.out.println("t1 == ct1? ..." + (t1==ct1));
	System.out.println("t1.equals(ct1)? ..." + (t1.equals(ct1)));		
	System.out.print("Performing t1 += t2 ..");
	t1 += t2;
	System.out.println(". done"); 

	// // // // //t1 now points to a new string value
	// // // // //note that ct1 points to the original object that t1 was also pointing to before
	// // // // //this means that the original object did not change;
	// // // // //a new object was created, and t1 is now referencing this new object
	System.out.println("\nPost concatenation state of t1, ct1,  and t2:");
	System.out.println("t1: " + t1);
	System.out.println("ct1: " + ct1);
	System.out.println("t2: " + t2);
	System.out.println("t1 == ct1? ..." + (t1==ct1));
	System.out.println("t1.equals(ct1)? ..." + (t1.equals(ct1)));		
    }

}


