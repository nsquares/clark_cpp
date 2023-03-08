Nathan Nguyen

I worked on this problem alone. I did not search for code on the internet to help me with this problem.


I compiled by having the ClientRational.java in the same directory as Rational.java, then I used the command:

javac *.java


I then used this command from the p1 folder as working directory:

java -ea -cp ~/ee363 hw1.p1.ClientRational

I had the hw1 folder within a folder I made called ee363 so that is why I had to set the class path. -ea is for enabling assertion checking so that overflow can be detected and printed out to the user on screen. For no assertion checking, I used this command instead:

java -cp ~/ee363 hw1.p1.ClientRational
 
-cp or the class path is dependent on where the package hw1.p1 is located.
