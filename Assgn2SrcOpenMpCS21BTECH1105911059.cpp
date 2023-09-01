#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  
#include <math.h>
#include <omp.h>
#include <stdint.h>
#include <sys/time.h>
#include<limits.h>
#include <bits/stdc++.h>
using namespace std;

struct Node // for grid
{
    int x_cord;
    int y_cord;
    int index;
};


int n, k;  // n * n
int **arr; // grid
int *Row;
int row;
int *Colum;
int *Grid;
int grid_it;
int gridnum;
struct Node *node;

void ColumnIterator(int a)
{
    a = a - n;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(arr[i][a]);
    }
        sort(begin(v), end(v));
        for (int i = 1; i < v.size(); ++ i) 
        {
            if (v[i] == v[i - 1]) {
                Colum[a] = 0;
                return;
            }
        }    
    Colum[a] = 1; 
}

void RowIterator(int a)
{
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(arr[a][i]);
    }
    sort(begin(v), end(v));
        for (int i = 1; i < v.size(); ++ i) 
        {
            if (v[i] == v[i - 1]) {
                Row[row] = 0;
                row++;
                return;
            }
        }    
    Row[row] = 1;
    row++;
}

void Grids_Iterator(struct Node *nd)
{
    int a = nd->x_cord;
    int b = nd->y_cord;
    int indx = nd->index;
    vector <int> v;
    int t = sqrt(n);
    for (int i = a; i < a + t; i++)
    {
        for (int j = b; j < b + t; j++)
        {
            v.push_back(arr[i][j]);
        }
    }  
        for (int i = 1; i < v.size(); ++ i) 
        {
            if (v[i] == v[i - 1]) {
                Grid[indx] = 0;
                return;
            }
        }    
    Grid[indx] = 1;   
}

void Thread_Function(int i)
{
    int start = i * ((3 * n) / k);
    int end = (i + 1) * ((3 * n) / k);
    for (int j = start; j < end; j++)
    {
        if (j < n)
        {
            RowIterator(j);
        }
    
        else if (n <= j && j < 2 * n)
        {
            ColumnIterator(j);
        }
        else if (2 * n <= j && j < 3 * n)
        {
            for (int a = 0; a < n; a += sqrt(n))
            {
                for (int b = 0; b < n; b += sqrt(n))
                {
                    node->x_cord = a;
                    node->y_cord = b;
                    node->index = j - 2 * n;
                    Grids_Iterator(node);
                }
            }
        }
    }   
}

int main()
{
    FILE *file;

    file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }

    // Read in the value of n
    fscanf(file, "%d %d", &k, &n);
    struct timespec start, end;
    Row = (int *)malloc(sizeof(int) * n);
    Colum = (int *)malloc(sizeof(int) * n);
    Grid = (int *)malloc(sizeof(int) * n);    
    int root = sqrt(n);
    if(k > 3 * n)
    {
        printf("**********Excess thread allocation***********\n");
        return 0;
    }
    else if(root * root != n)
    {
        printf("n is not a perfect square\n");
        return 0;
    }
    else if(k <= 0)
    {
        cout<<"Invalid thread count "<<endl;
    }
    arr = (int **)malloc(n * n *sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * n *sizeof(int));
    }

    // Read in the remaining values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &arr[i][j]);
        }
    }

    fclose(file);

    gridnum = 0;
    row = 0;
    grid_it = 0;
    pthread_t threadIDs;
    node = (struct Node *)malloc(sizeof(struct Node));
    struct timeval now1;
    uint64_t init_time;
    struct timeval now2;
    uint64_t fin_time;
    gettimeofday(&now1, NULL); //time starts now      
    #pragma omp parallel num_threads(k)
    {
       int id = omp_get_thread_num();
       Thread_Function(id);
    }
    gettimeofday(&now2, NULL); //time ends now
    init_time = (uint64_t)now1.tv_sec * 1000000 + (uint64_t)now1.tv_usec;
    fin_time = (uint64_t)now2.tv_sec * 1000000 + (uint64_t)now2.tv_usec;

    FILE *fptr = fopen("Outmain.txt", "w");

    for (int i = 0; i < k; i++)
    {
        int start = i * ((3 * n) / k);
        int end = (i + 1) * ((3 * n) / k);
        if (i == k - 1)
        {
            for (int j = start; j < 3 * n; j++)
            {
                 if (n <= j && j < 2 * n)
                {
                    if (Colum[j - n] == 1)
                    {
                        fprintf(fptr, "Thread %d checks column %d and is valid\n", i + 1, j - n + 1);
                    }
                    else
                    {
                        fprintf(fptr, "Thread %d checks column %d and is invalid\n", i + 1, j - n + 1);
                    }
                }
                else if (2 * n <= j && j < 3 * n)
                {
                    if (Grid[j - 2 * n] == 1)
                    {
                        fprintf(fptr, "Thread %d checks Grid %d and is valid\n", i + 1, j - 2 * n + 1);
                    }
                    else
                    {
                        fprintf(fptr, "Thread %d checks Grid %d and is invalid\n", i + 1, j - 2 * n + 1);
                    }
                }
            }
        }
        else
        {
            for (int j = start; j < end; j++)
            {
                if (j < n)
                {
                    if (Row[j] == 1)
                    {
                        fprintf(fptr, "Thread %d checks row %d and is valid\n", i + 1, j + 1);
                    }
                    else
                    {
                        fprintf(fptr, "Thread %d checks row %d and is invalid\n", i + 1, j + 1);
                    }
                }

                else if (n <= j && j < 2 * n)
                {
                    if (Colum[j - n] == 1)
                    {
                        fprintf(fptr, "Thread %d checks column %d and is valid\n", i + 1, j - n + 1);
                    }
                    else
                    {
                        fprintf(fptr, "Thread %d checks column %d and is invalid\n", i + 1, j - n + 1);
                    }
                }
                else if (2 * n <= j && j < 3 * n)
                {
                    if (Grid[j - 2 * n] == 1)
                    {
                        fprintf(fptr, "Thread %d checks Grid %d and is valid\n", i + 1, j - 2 * n + 1);
                    }
                    else
                    {
                        fprintf(fptr, "Thread %d checks Grid %d and is invalid\n", i + 1, j - 2 * n + 1);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(Row[i] == 0 || Colum[i] == 0 || Grid[i] == 0 )
        {
            fprintf(fptr, "Sudoku is invalid\n");
            fprintf(fptr, "Time taken by program is : %lu microseconds\n", (fin_time-init_time));  
            return 0;
        }
    }
    fprintf(fptr, "Sudoku is valid\n");      
    fprintf(fptr, "Time taken by program is : %lu microseconds\n", (fin_time-init_time));  
}