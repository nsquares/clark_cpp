#!/usr/bin/env bash

## runs the unit-tests in RationalTest.java assuming that the ADT is in Rational.java
## usage, if junit4 is already in the classpath: ./testrational.sh 
## usage, if classpath is not set or junit4 is not in the classpath: ./testrational.sh nocp

if [ "$#" -eq 0 ]
then   
    rm -f *class
    javac *java
    java org.junit.runner.JUnitCore RationalTest
elif [ "$#" -eq 1 ] && [ "$1" == "nocp" ]
then
    # Polaris (if junit.jar in not in the CLASSPATH)    
    rm -f *class
    javac -cp /usr/share/java/junit.jar *java
    java -cp  .:/usr/share/java/junit.jar org.junit.runner.JUnitCore RationalTest
else
    echo -e "usage: \`$0\` -- (if junit4.jar is already in the classpath)"
    echo -e "usage: \`$0 nocp\` -- (if junit4.jar is not in the classpath)"
fi

