# Fully Homomorphic Encryption

### test-TFHE Result

```
root@d5d26e6d92c7:/work/test-TFHE# ls
HomOperGD.c  testGDStep1    testGDStep2    testGDStep3
run.sh       testGDStep1.c  testGDStep2.c  testGDStep3.c
root@d5d26e6d92c7:/work/test-TFHE# ./testGDStep1
Step1 start
Hi there! Today, I will ask the cloud what is the linear regeression-gradient descent of :
(1.000000, 1.000000),
(4.000000, 2.000000),
(2.000000, 3.000000),
(6.000000, 4.000000),
(3.000000, 5.000000),
root@d5d26e6d92c7:/work/test-TFHE# ./testGDStep2
Step2 start
update loop starts
loop 1 initialization
loop 1 termination
loop 2 initialization
loop 2 termination
loop 3 initialization
loop 3 termination
loop 4 initialization
loop 4 termination
loop 5 initialization
loop 5 termination
done in 1717.042725 seconds...
```

<br/>

<br/>

### SEAL Test Result
```
root@d5d26e6d92c7:/work/SEAL-demo# ./sealTest
encrypt and decrypt x = 3
Number of slots: 4096

    [ 3.0000000, 3.0000000, 3.0000000, ..., 3.0000000, 3.0000000, 3.0000000 ]

time : 0.000000
```