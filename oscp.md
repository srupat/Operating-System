## Operating System Course Project
> How do we search for data in our input string?

- The plan is to implement a system that consists of <mark>**Labels**</mark> that point to where the desired data is stored in memory.

- This will be done by the user himself, by writing the desired instruction from the given list of instructions given below 

    - GD (GetData)
    - PD (PutData)
    - LR (LoadRegister)
    - SR (StoreRegister)
    - CR (CompareWithReg)
    - BT 
    - H (Halt)

> For example, 
The input string contains the following data : `$DTA HELLO WORLD`
Now, we want to access the word *world* from this data. We will count the number of characters from the start, thus *world* is the 10th character. In the label, we will also specify the number of characters that we want to read, for example, here the length of the string *World*. Our final label will look like : `L010,6`. This is the first label, hence it has been indexed as **L0**. Further labels will follow subsequent indexing. 

This is how we will read the data from the input string and then process it according to the instructions on the program card. 