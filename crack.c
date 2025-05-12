#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    int size;
    char **hashes = loadFileAA(argv[1], &size);
    if (!hashes) {
        fprintf(stderr, "Failed to load hashes file.\n");
        exit(1);
    }

    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    FILE *dict = fopen(argv[2], "r");
if (!dict) {
    perror("Error opening dictionary file");
    freeAA(hashes, size);
    exit(1);
}


    // TODO
    char pass[PASS_LEN];
    char hash[HASH_LEN];
    int found = 0;
    
    while (fgets(pass, PASS_LEN, dict)) {
        pass[strcspn(pass, "\n")] = '\0';  // Strip newline
    
        // Hash the password
        md5String(pass, hash);
    
        // Search for the hash in hashes array
        char *match = stringSearchAA(hash, hashes, size);
        if (match) {
            printf("Cracked: %s -> %s\n", hash, pass);
            found++;
        }
    }
    
    
    // TODO
    // When done with the file:
    fclose(dict);
    printf("Total hashes cracked: %d\n", found);
    freeAA(hashes, size);
    
}


