# hello  
This is my implmentation of a Peterson based tournment tree lock for ANY n number of threads.  
To run the scripts I have included a make file  
First: make  
Seconde: ./a.out < type-of-lock > < n-number-of-threads >  
i.e ./a.out 0 20  
The above example will run 10 threads on Peterson Lock mode. Each thread will execute the critical section 1000 times  
there three possible modes, 0 for peterson, 1 for TAS [test and set] lock, 2 for FAI [Fetch and Increment] lock 
my code is based on this idea.  
<img width="639" height="454" alt="Screenshot 2025-09-04 at 12 51 50 AM" src="https://github.com/user-attachments/assets/9155412a-d04b-4b2c-ba86-de4ae8bb977b" />
<img width="657" height="464" alt="Screenshot 2025-09-04 at 12 51 32 AM" src="https://github.com/user-attachments/assets/d2365d55-677a-4d59-938c-c99b0f67759c" />  
For any n number of threads first we have to know how many locks are needed.  
Second we need to find an efficient data structure to hold the locks.  
We need to understand how to index the locks 
Note: The most difficult thing about the project is understanding and coming up with the equation that determines which thread holds which instance of a peterson
lock in the tree. If you can understand that the rest of the code is just using recurison to go all the way up and releasing the lock when the recursion comes back.
<img width="647" height="460" alt="Screenshot 2025-09-04 at 12 52 37 AM" src="https://github.com/user-attachments/assets/f4cc8de7-bee1-4831-bcb4-e5f2021de79e" />
<img width="648" height="467" alt="Screenshot 2025-09-04 at 12 52 27 AM" src="https://github.com/user-attachments/assets/0b53f442-713b-43e0-a729-d3fce0dc5bab" />


