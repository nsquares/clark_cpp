Nathan Nguyen

I worked alone on this problem.

I did not use a non-trivial amount of content.



[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype $HOME
/home/nguyennt: directory
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /run/dmeventd-server
/run/dmeventd-server: fifo
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /etc/shadow
/etc/shadow: regular
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /dev/tty5
/dev/tty5: character special
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /lib64
/lib64: symbolic link
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /dev/log
/dev/log: socket
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /run/systemd/initctl/fifo
/run/systemd/initctl/fifo: fifo
[nguyennt@polaris:~/ee462/hw2/p2]$ ./fltype /dev/sdb
/dev/sdb: block special
[nguyennt@polaris:~/ee462/hw2/p2]$


