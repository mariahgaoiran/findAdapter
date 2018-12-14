// GOALS:
// fix lowercase function dribbling into next word
// clean print statements so theyre all the same

// FIRST TEST: HMDI -> VGA
// SECOND TEST: DP (-> HDMI) -> DVI


// For string manipulation and printing
#include <algorithm> // for transform
#include <string>
#include <iostream>
#include <stdio.h>

/*
  Converts the word (string, ending with \0) to lowercase
*/
std::string lowercase(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

int main (int argc, char* argv[]) {

  /* Variable explanations */
  // input: connector type they NEED for src
  // in_gender: connector gender they NEED for src
  // output: connector type they NEED for dest
  // out_gender: connector gender they NEED for dest

  /* Check for proper usage */
  if (argc != 5) {
    // printf("Usage: %s input output in_gender out_gender\n", argv[0]);
    // printf ("\nList of possible connections:\n");
    // printf ("VGA\nDVI\nDP\nHDMI\n"); // dont forget mini
    return(1);
  }

  std::cout << "Welcome to the adapter finder." << "\n";

  /* Clean arguments, set all to lowercase */
  std::string input = lowercase(argv[1]);
  std::string output = lowercase(argv[2]);
  std::string in_gender = lowercase(argv[3]); // get first letter only
  std::string out_gender = lowercase(argv[4]);

  // printf("-------------------%s %s %s %s\n", input, output, in_gender, out_gender);

  // # passive?
  // # different DVI connections?
  // # bidirectional?

  printf("You selected to go from %s (%s) -> %s (%s)\n", input.c_str(), in_gender.c_str(), output.c_str(), out_gender.c_str());

  // Find row with V1: VGA

  // Find column with V2: hdmi
  // Split by :, get G1
  // If >0, return direct adapter

  // If we do not have direct adapter...
  // For every row
    // Find column with V2: hdmi
    // Split by :, get G1 (first slice)
    // If >0, push V3 (type) / V4 (gender) onto queue
    // Split by :, get G1 (second slice)
    // If >0, push V3 (type) / V4 (gender) onto queue
    // while queue !empty
      // Find row with V1: VGA
      // Find column with V3 (middle man)
      // Split by :, get G4
      // if >0, return V5, V3+V4, V2

  // print "no adapters available for that input and output"


}

// Funciton to find value from input, output, and gender (aka: row, column, and slice)


//
// ### FIND DIRECT CONNECTION ###
//
// # for finding matching row
// input_gender=$input+$in_gender
//
// file="./adapters_avail"
// while IFS=',' read -r name gender vga dvi dp hdmi
// do
//     # find row with the same connector type
//     name_gender=$name+$gender
//     if [ "$input_gender" = "$name_gender" ]
//         then
//             # find column for desired connector
//             eval avail_out=\$$output
//             f_count="$(cut -d':' -f1 <<< "$avail_out")"
//             m_count="$(cut -d':' -f2 <<< "$avail_out")"
//             printf "$f_count $m_count\n"
//     fi
//     if [ $avail_count -eq 0 ] # no direct connection
//         then
//             printf "There are no direct connections."
//             ### CHECK OUTPUT ###
//
//             break
//     fi
// done < "$file"
