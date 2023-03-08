Nathan Nguyen

I worked alone on this problem. I did not use any sources.


[nguyennt@polaris:~/ee462/hw1/p3]$ ./bkUp.sh bkUp.sh
[nguyennt@polaris:~/ee462/hw1/p3]$ echo $?
0
[nguyennt@polaris:~/ee462/hw1/p3]$ ./bkUp.sh /etc/hosts
[nguyennt@polaris:~/ee462/hw1/p3]$ echo $?
0
[nguyennt@polaris:~/ee462/hw1/p3]$ ls /tmp/nguyennt/
bkUp.sh_01Feb23_2343.bk  readme.txt_01Feb23_2331.bk
bkUp.sh_01Feb23_2355.bk  readme.txt_01Feb23_2356.bk
bkUp.sh_01Feb23_2358.bk  readme.txtWed Feb  1 23:10:44 EST 2023
hosts_01Feb23_2333.bk    readme.txtWed Feb  1 23:10:51 EST 2023
hosts_01Feb23_2335.bk    readme.txtWed Feb  1 23:10:54 EST 2023
hosts_01Feb23_2359.bk    readme.txtWed Feb  1 23:12:36 EST 2023.bk
[nguyennt@polaris:~/ee462/hw1/p3]$






Backing up these two files worked and they were listed in the /tmp/nguyennt directory.
