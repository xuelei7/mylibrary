// Problem C: Dial Lock
// A dial lock is a kind of lock which has some dials with printed numbers. It has a special sequence of numbers, namely an unlocking sequence, to be opened.

// You are working at a manufacturer of dial locks. Your job is to verify that every manufactured lock is unlocked by its unlocking sequence. In other words, you have to rotate many dials of many many locks.

// It’s a very hard and boring task. You want to reduce time to open the locks. It’s a good idea to rotate multiple dials at one time. It is, however, a difficult problem to find steps to open a given lock with the fewest rotations. So you decided to write a program to find such steps for given initial and unlocking sequences.

// Your company’s dial locks are composed of vertically stacked k (1 ≤ k ≤ 10) cylindrical dials. Every dial has 10 numbers, from 0 to 9, along the side of the cylindrical shape from the left to the right in sequence. The neighbor on the right of 9 is 0.

// A dial points one number at a certain position. If you rotate a dial to the left by i digits, the dial newly points the i-th right number. In contrast, if you rotate a dial to the right by i digits, it points the i-th left number. For example, if you rotate a dial pointing 8 to the left by 3 digits, the dial newly points 1.

// You can rotate more than one adjacent dial at one time. For example, consider a lock with 5 dials. You can rotate just the 2nd dial. You can rotate the 3rd, 4th and 5th dials at the same time. But you cannot rotate the 1st and 3rd dials at one time without rotating the 2nd dial. When you rotate multiple dials, you have to rotate them to the same direction by the same digits.

// Your program is to calculate the fewest number of rotations to unlock, for given initial and unlocking sequences. Rotating one or more adjacent dials to the same direction by the same digits is counted as one rotation.

// Input
// The input consists of multiple datasets. Each datset consists of two lines. The first line contains an integer k. The second lines contain two strings, separated by a space, which indicate the initial and unlocking sequences.

// The last dataset is followed by a line containing one zero. This line is not a part of any dataset and should not be processed.

// Output
// For each dataset, print the minimum number of rotations in one line.
