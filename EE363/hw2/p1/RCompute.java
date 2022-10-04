package hw2.p1;

public class RCompute implements Runnable{
  
  private int min;
  private int max;

  public RCompute(int left, int right){
    min = left;
    max = right;
    System.out.println(left);
    System.out.println(right);

    System.out.println(min);
    System.out.println(max);
  }

  public void run(){

    double mean = 0;
    for(int i=min; i<=max; i++){

      mean += Math.sqrt(i);
    }
    mean = mean/((double)max-(double)min);
    System.out.println("["+Thread.currentThread()+"] Average of square roots ("+min+" to "+max+") = "+mean);
  }
}
