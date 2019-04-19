#include <stdio.h>
//step1 1:Initialisation of Main function
int main() 
{
 //Step 2: Initialization & Declaration of Variables & Matrices
    int n, m, i, j, k,a[5][3],max[5][3],avail[3]; 
    n = 5; // Number of processes 
    m = 3; // Number of resources 
// allocation matrix declaration   
    a[5][3] = {         { 0, 1, 0 }, // P0     
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
// declaration of max matrix   
    max[5][3] = {     { 7, 5, 3 }, // P0    
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 
// Available Resources  
    avail[3] = { 3, 3, 2 };  
  
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) 
    { 
        f[k] = 0; 
    } 
//Initialisation & Declaration of Need Matrix. 
    int need[n][m]; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - a[i][j]; 
    } 
    int y = 0; 
 //step 3:Finding the safe sequence;
    for (k = 0; k < 5; k++) 
    { 
        for (i = 0; i < n; i++) 
        { 
            if (f[i] == 0)
            { 
  
                int flag = 0; 
                for (j = 0; j < m; j++)
                { 
                    if (need[i][j] > avail[j]) 
                        flag = 1; 
                    break; 
                } 
  
                if (flag == 0) 
                { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += a[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  //Step 4:processes safe state sequence
    printf("This is the Safe Sequence of the given Processes:-\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
} 
