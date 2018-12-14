// GOALS:
// fix lowercase function dribbling into next word

#include <stdio.h>
#include <ctype.h>

char* lowercase(char* word) {
    for(char i=0; i < (sizeof(word)/sizeof(char)); i++) {
      // printf("%d\n",i);
      word[i] = tolower(word[i]);
    }
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
    printf("Usage: %s input output in_gender out_gender\n", argv[0]);
    printf ("\nList of possible connections:\n");
    printf ("VGA\nDVI\nDP\nHDMI\n"); // dont forget mini
    return(1);
  }

  /* Clean arguments, set all to lowercase */
  // char* input = lowercase(argv[1]);
  char* input = lowercase(argv[1]);
  char* output = argv[2];
  char* in_gender = argv[3]; // get first letter only
  char* out_gender = lowercase(argv[4]);

  // printf("-------------------%s %s %s %s\n", input, output, in_gender, out_gender);

  // # passive?
  // # different DVI connections?

  printf("You selected to go from %s (%s) -> %s (%s)\n", input, in_gender, output, out_gender);



}




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
