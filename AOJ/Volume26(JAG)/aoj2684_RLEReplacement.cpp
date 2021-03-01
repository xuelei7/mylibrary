// H - RLE Replacement
// Problem Statement
// In JAG Kingdom, ICPC (Intentionally Compressible Programming Code) is one of the common programming languages. Programs in this language only contain uppercase English letters and the same letters often appear repeatedly in ICPC programs. Thus, programmers in JAG Kingdom prefer to compress ICPC programs by Run Length Encoding in order to manage very large-scale ICPC programs.

// Run Length Encoding (RLE) is a string compression method such that each maximal sequence of the same letters is encoded by a pair of the letter and the length. For example, the string "RRRRLEEE" is represented as "R4L1E3" in RLE.

// Now, you manage many ICPC programs encoded by RLE. You are developing an editor for ICPC programs encoded by RLE, and now you would like to implement a replacement function. Given three strings [Math Processing Error], [Math Processing Error], and [Math Processing Error] that are encoded by RLE, your task is to implement a function replacing the first occurrence of the substring [Math Processing Error] in [Math Processing Error] with [Math Processing Error], and outputting the edited string encoded by RLE. If [Math Processing Error] does not occur in [Math Processing Error], you must output [Math Processing Error] encoded by RLE without changes.

// Input
// The input consists of three lines.

// [Math Processing Error]
// [Math Processing Error]
// [Math Processing Error]
// The lines represent strings [Math Processing Error], [Math Processing Error], and [Math Processing Error] that are encoded by RLE, respectively. Each of the lines has the following format:

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] $
// Each [Math Processing Error] ([Math Processing Error]) is an uppercase English letter (A-Z) and [Math Processing Error] ([Math Processing Error], [Math Processing Error]) is an integer which represents the length of the repetition of [Math Processing Error]. The number [Math Processing Error] of the pairs of a letter and an integer satisfies [Math Processing Error]. A terminal symbol $ indicates the end of a string encoded by RLE. The letters and the integers are separated by a single space. It is guaranteed that [Math Processing Error] holds for any [Math Processing Error].

// Output
// Replace the first occurrence of the substring [Math Processing Error] in [Math Processing Error] with [Math Processing Error] if [Math Processing Error] occurs in [Math Processing Error], and output the string encoded by RLE. The output must have the following format:

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] $
// Here, [Math Processing Error] for [Math Processing Error] and [Math Processing Error] for [Math Processing Error] must hold.

