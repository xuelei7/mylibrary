// Problem Statement
// Nathan O. Davis is a student at the department of integrated systems.

// Today's agenda in the class is audio signal processing. Nathan was given a lot of homework out. One of the homework was to write a program to process an audio signal. He copied the given audio signal to his USB memory and brought it back to his home.

// When he started his homework, he unfortunately dropped the USB memory to the floor. He checked the contents of the USB memory and found that the audio signal data got broken.

// There are several characteristics in the audio signal that he copied.

// The audio signal is a sequence of N samples.

// Each sample in the audio signal is numbered from 1 to N and represented as an integer value.

// Each value of the odd-numbered sample(s) is strictly smaller than the value(s) of its neighboring sample(s).

// Each value of the even-numbered sample(s) is strictly larger than the value(s) of its neighboring sample(s).

// He got into a panic and asked you for a help. You tried to recover the audio signal from his USB memory but some samples of the audio signal are broken and could not be recovered. Fortunately, you found from the metadata that all the broken samples have the same integer value.

// Your task is to write a program, which takes the broken audio signal extracted from his USB memory as its input, to detect whether the audio signal can be recovered uniquely.

// Input
// The input consists of multiple datasets. The form of each dataset is described below.

// N
// a1 a2 ... aN
// The first line of each dataset consists of an integer, N(2≤N≤1,000). N denotes the number of samples in the given audio signal. The second line of each dataset consists of N values separated by spaces. The i-th value, ai, is either a character x or an integer between −109 and 109, inclusive. It represents the i-th sample of the broken audio signal. If ai is a character x , it denotes that i-th sample in the audio signal is broken. Otherwise it denotes the value of the i-th sample.

// The end of input is indicated by a single 0. This is not included in the datasets.

// You may assume that the number of the datasets does not exceed 100.

// Output
// For each dataset, output the value of the broken samples in one line if the original audio signal can be recovered uniquely. If there are multiple possible values, output ambiguous. If there are no possible values, output none.

