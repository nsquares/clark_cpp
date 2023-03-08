Nathan Nguyen
I worked on this problem alone. I did not use a non-trivial amount of content.



I compiled by having the client in the same directory as RCompute.java, then I used the command:

javac *.java


I then used this command from the p1 folder as working directory:

java -cp ~/ee363 hw2.p1.ClientAvgPar 30 250 15

I had the hw2 folder within a folder I made called ee363 so that is why I had to set the class path. For creating avg15.txt, I used this following command:

java -cp ~/ee363 hw2.p1.ClientAvgPar 30 250 15 >> avg15.txt
 
-cp or the class path is dependent on where the package hw2.p1 is located.
