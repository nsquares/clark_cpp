package hw2.p1;

import java.util.concurrent.ThreadLocalRandom;

public class ClientAvgPar {
    public static void main(String[] args) {
	if (args.length != 3) {
	    System.err.println("usage: ClientAvg <MAX_LEFT> <MAX_RIGHT> <NUM_LISTS>");
	    System.exit(1);
	}
	
	int MAX_LEFT = 0;
	int MAX_RIGHT = 0;
	int NUM_LISTS = 0;	
	
	try {
	    //user input
	    MAX_LEFT = Integer.parseInt(args[0]); //max value of the left endpoint
	    MAX_RIGHT = Integer.parseInt(args[1]); //max value of right endpoint
	    NUM_LISTS = Integer.parseInt(args[2]); //number of lists
	} catch (NumberFormatException e) {
	      System.err.println("usage: arguments must be integers.");
	      System.exit(1);
	}

	Thread[] thr = new Thread[NUM_LISTS];
	RCompute[] computeUnits = new RCompute[NUM_LISTS]; //the avg of each list is to be computed in a separate thread
       
	//the left and right endpoints of each of the NUM_LISTS lists are computed randomly; they must lie between MAX_LEFT and MAX_RIGHT
	for (int i = 0; i < NUM_LISTS; i++) {
	    int left = ThreadLocalRandom.current().nextInt(0, MAX_LEFT);
	    int right = ThreadLocalRandom.current().nextInt(MAX_LEFT+1, MAX_RIGHT);
	    String label = "thr_" + i; 

	    //the range is [left, right]; note that 0<left<MAX_LEFT<right<MAX_RIGHT
	    computeUnits[i] = new RCompute(left, right); //creates the Runnable
	    
	    //this thread should average the numbers {sqrt(left), sqrt(left+1), ... sqrt(right)}
	    thr[i] = new Thread(computeUnits[i], label); //pass the Runnable to a Thread constructor
	    thr[i].start();
	}

	for (int i = 0; i < NUM_LISTS; i++) {
	    try {
		thr[i].join();
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	   
	}

    }
}

