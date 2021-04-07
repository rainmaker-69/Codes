﻿void firstFit(int blockSize[], int m, 
              int processSize[], int n)
{
    // Stores block id of the 
    // block allocated to a process
    int allocation[n];
  
    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));
  
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocation[i] = j;
  
                // Reduce available memory in this block.
                blockSize[j] -= processSize[i];
  
                break;
            }
        }
    }
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" 
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}