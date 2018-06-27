/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marce
 *
 * Created on June 26, 2018, 10:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
 * 
 */
int main(int argc, char** argv) {
    //welcome the user
    printf("Welcome to Word Count \n");
    
    //input name of file
    char filename[] = "C:\\Users\\marce\\Documents\\NetBeansProjects\\WordCount\\wordcount1.txt";
    
    //now searching
    printf("Now Searching for File \n");
    
    //point filename to file on read
    FILE *file = fopen (filename,"r");
    
    // if file exists
    if (file != NULL){
       //create var to save output
        int words=0, chars=0, lines=0, spaces=0;
        char line[256], prevchar = '\0';
        // tell user the file was found
        printf("%s WAS FOUND!! \n", filename);
           
        
        while(fgets (line, sizeof line, file) != NULL){
            int i =0;
            //calculate number of lines
            lines++;  
            
            
           
            // number of words
            while(line[i]){ 
               if ((line[i] != ' ' && line[i-1]=='\0') || (line[i] != ' ' && line[i-1]==' ') ){
                   
                   words++;
               }
               
               
               i++;  
           }
            // calculate number of chars  
           for(int j=0; j<strlen(line)-1; j++){ 
               if (line[j] != ' ' ){              
                   chars++;
               }
           }
          
        }
        
        //close the file stream
        fclose(file);
        
        printf("Lines: %i  Chars: %i Words: %i \n",lines,chars, words);
    }
    else{
        //tell user the file wasnt found
        printf("%s was Not Found \n", filename);
        //output error to file name
        perror (filename);
        
        
    }
    
    return (EXIT_SUCCESS);
}

