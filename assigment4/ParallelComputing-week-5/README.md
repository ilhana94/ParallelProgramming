In this task, I tested different ways of adding numbers to see which one was the most accurate and fastest.
It is a **global sum problem**, where the order of addition affects the result because computers use limited precision (floating point).
In the file `main.c`, I ran and tested several addition methods:

* **Double sum** – the fastest, but the least accurate
* **Long double sum** – more accurate, but slower
* **Pairwise sum** – adds numbers in pairs, quite accurate
* **Kahan sum** – uses error correction, very accurate
* **Knuth sum** – similar to Kahan, but even more accurate

I tested and measured each method:

* **Runtime**
* **Error** in the result

I entered the results in a table with the columns:

`Method | Error | Time`

Simple methods are faster, but make more errors.
Kahan and Knuth are the most accurate and stable, which is important in parallel computing.


-Spreadsheet link: https://docs.google.com/spreadsheets/d/1W-wSHCfj6oTL_QlrsmRapQuR0ZUwrNiTI6bbuXBL0f8/edit?usp=sharing

![Make output](images/Screenshot%20from%202025-10-30%2015-32-54.png)
![Make output](images/Screenshot%20from%202025-10-30%2015-35-12.png)
![Make output](images/Screenshot%20from%202025-10-30%2015-35-35.png)