package hw2.p1;

import java.text.DecimalFormat;

public class RCompute implements Runnable{
  
  private int min;
  private int max;

  public RCompute(int left, int right){
    min = left;
    max = right; 
  }

  public void run(){

    double mean = 0;
    for(int i=min; i<=max; i++){

      mean += Math.sqrt(i);
    }
    mean = mean/(((double)max-(double)min)+1);
    
    System.out.println("[Thread "+Thread.currentThread().getName()+"] Average of square roots  ("+min+" to "+max+") = "+ new DecimalFormat("#.##").format(mean));
  }
}
