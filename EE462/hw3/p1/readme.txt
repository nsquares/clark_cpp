Nathan Nguyen

I worked on this problem alone. I did not look up anything extensive.

I ran:
./grtee file6.txt 1>out6.log 2>err6.log

and the output is (if SIGQUIT is given):


[nguyennt@polaris:~/ee462/hw3/p1]$ ./grtee file6.txt 1>out6.log 2>err6.log
so
this is a story
about a blue guy
living in a blue world
and all day
and all night
all he sees
is blue
inside and outside
^\[nguyennt@polaris:~/ee462/hw3/p1]$ ls
err6.log  file6.txt  grtee  grtee.c  grtee.c~  out6.log  readme.txt



[nguyennt@polaris:~/ee462/hw3/p1]$ cat err6.log
Received signal: Quit

[nguyennt@polaris:~/ee462/hw3/p1]$ cat out6.log
so
this is a story
about a blue guy
living in a blue world
and all day
and all night
all he sees
is blue
inside and outside

[nguyennt@polaris:~/ee462/hw3/p1]$ cat file6.txt
so
this is a story
about a blue guy
living in a blue world
and all day
and all night
all he sees
is blue
inside and outside
Closing the file gracefully.












If no interrupt is given:



[nguyennt@polaris:~/ee462/hw3/p1]$ ./grtee file6.txt 1>out6.log 2>err6.log
this is another test but no interrupt this time
test test 123

[nguyennt@polaris:~/ee462/hw3/p1]$ ls
err6.log  file6.txt  grtee  grtee.c  grtee.c~  out6.log  readme.txt  readme.txt~

[nguyennt@polaris:~/ee462/hw3/p1]$ cat err6.log
[nguyennt@polaris:~/ee462/hw3/p1]$ cat out6.log
this is another test but no interrupt this time
test test 123

[nguyennt@polaris:~/ee462/hw3/p1]$ cat file6.txt
this is another test but no interrupt this time
test test 123

[nguyennt@polaris:~/ee462/hw3/p1]$
