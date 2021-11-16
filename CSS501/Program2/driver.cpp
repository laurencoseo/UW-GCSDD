/* ---------------------------------------------------------------------------
 * driver.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 11/11/21
 *
 * Date of Last Modification: 11/12/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: This file explores the differences between finding the Longest
 * Common Sequence by either using an iterative method or a recursive one.
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 * Implementation and assumptions:
 *   -- Assumes input file is good
 *   -- Assumes good user input
 * -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

/* ---------------------------------------------------------------------------
 * lcs_it
 *
 * description:
 * Iteratively fills out a 2D Matrix to find the LCS and returns the length
 *
 * preconditions: 
 * C = 2D matrix of two strings and results of common sequence
 * X = 1st string from input file
 * Y = 2nd string from input file
 * m = String X's size
 * n = String Y's size
 *
 * postconditions:
 * Returns the length of the LCS
 * -------------------------------------------------------------------------*/
int lcs_it(int **C, string X, string Y, int m, int n )
{
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if ((i == 0) || (j == 0))
        C[i][j] = 0;                  // first row & col are 0
      else if (X[i - 1] == Y[j - 1])
        C[i][j] = C[i - 1][j - 1] + 1;
      else
        C[i][j] = max(C[i][j - 1], C[i - 1][j]);
    }
  }
  return C[m][n];
}

/* ---------------------------------------------------------------------------
 * backtrack
 *
 * description:
 * Recursively goes through 2D Matrix and returns the LCS string
 *
 * preconditions: 
 * C = 2D matrix of two strings and results of common sequence
 * X = 1st string from input file
 * Y = 2nd string from input file
 * m = String X's size
 * n = String Y's size
 *
 * postconditions:
 * Returns the LCS string
 * -------------------------------------------------------------------------*/
string backtrack(int **C, string X, string Y, int m, int n)
{
  if (m == 0 | n == 0)
    return "";
  if (X[m - 1] == Y[n - 1]) // x-1, y-1
    return backtrack(C, X, Y, m - 1, n - 1) + X[m - 1]; // x-1
  if (C[m][n - 1] > C[m - 1][n])
    return backtrack(C, X, Y, m, n - 1);
  return backtrack(C, X, Y, m - 1, n);
}

/* ---------------------------------------------------------------------------
 * lcs_it_test
 *
 * description:
 * Creates a new 2D matrix and iteratively fills it out to find the LCS 
 * and returns the length
 *
 * preconditions: 
 * X = 1st string from input file
 * Y = 2nd string from input file
 * m = String X's size
 * n = String Y's size
 *
 * postconditions:
 * Returns the length of the LCS
 * -------------------------------------------------------------------------*/
int lcs_it_test(string X, string Y, int m, int n )
{
  // Create 2D matrix
  int **C = new int*[m + 1];
  for (int i = 0; i < m + 1; ++i) 
  {
    C[i] = new int [n + 1];
  }

  // Use 2D matrix in lcs_it
  return lcs_it(C, X, Y, m, n);
}

/* ---------------------------------------------------------------------------
 * lcs_re
 *
 * description:
 * Recursively goes through the 2 strings and returns the LCS length
 *
 * preconditions: 
 * X = 1st string from input file
 * Y = 2nd string from input file
 * m = String X's size
 * n = String Y's size
 *
 * postconditions:
 * Returns the length of the LCS
 * -------------------------------------------------------------------------*/
int lcs_re(string X, string Y, int m, int n)
{
  if ((m == 0) || (n == 0))
    return 0;
  else if (X[m - 1] == Y[n - 1])
    return 1 + lcs_re(X, Y, m - 1, n -1);
  else
    return max(lcs_re(X, Y, m - 1, n), lcs_re(X, Y, m, n - 1));
}
  
/* ---------------------------------------------------------------------------
 * getSubstring
 *
 * description:
 * Creates a substring from a user input
 *
 * preconditions: 
 * str = string to shorten
 * input = user input
 *
 * postconditions:
 * Returns the substring
 * -------------------------------------------------------------------------*/
string getSubstring(string str, int input)
{
  return str.substr(0, input);
}

/* ---------------------------------------------------------------------------
 * runIterative
 *
 * description:
 * Runs iterative method from 1 up to the user's input number and logs time
 *
 * preconditions: 
 * X = 1st string from input file
 * Y = 2nd string from input file
 * input = user input
 *
 * postconditions:
 * Time output in the form of clog
 * -------------------------------------------------------------------------*/
void runIterative(string X, string Y, int input)
{
  int i = 1;
  while (i <= input)
  {
    int start_s, stop_s;

    start_s=clock();

    string str1 = getSubstring(X, input);
    string str2 = getSubstring(Y, input);

    lcs_it_test(str1, str2, i, i);

    stop_s=clock();

    clog << i << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    i++;
  }
}

/* ---------------------------------------------------------------------------
 * runRecursive
 *
 * description:
 * Runs recursive method from 1 up to the user's input number and logs time
 *
 * preconditions: 
 * X = 1st string from input file
 * Y = 2nd string from input file
 * input = user input
 *
 * postconditions:
 * Time output in the form of clog
 * -------------------------------------------------------------------------*/
void runRecursive(string X, string Y, int input)
{
  int i = 1;

  while (i <= input)
  {
    int start_s, stop_s;
    start_s=clock();

    string str1 = getSubstring(X, i);
    string str2 = getSubstring(Y, i);

    lcs_re(str1, str2, i, i);

    stop_s=clock();

    clog << i << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    i++;
  }
  
}

int main() {

  string X, Y; 

  // Read 2 strings from input file
  ifstream fileName("input.txt");
  getline(fileName, X);
  getline(fileName, Y);

  // Assign the string lengths to m, n
  int m = X.size();
  int n = Y.size();

  // Print 2 strings
  cout << "X String: " << endl << X << endl << endl;
  cout << "Y String: " << endl << Y << endl << endl;

  // Create 2D Array
  int **C = new int*[m + 1];
  for (int i = 0; i < m + 1; ++i) 
  {
    C[i] = new int [n + 1];
  }

  // find the Longest Common Sequence length and print it
  int len = lcs_it(C, X, Y, m, n);
  cout << "LCS length is: " << len << endl << endl;

  // find the Longest Common Sequence string and print it
  cout << "LCS is " << backtrack(C, X, Y, m, n) << endl << endl;

  // Get user input for Iterative Method
  int iterativeInput;
  cout << "Enter trial time for iterative version (less than 800)" << endl;
  cin >> iterativeInput;
  runIterative(X, Y, iterativeInput);
  cout << endl;

  // Get user input for Recursive Method
  int recursiveInput;
  cout << "Enter trial time for recursive version (less than 20)" << endl;
  cin >> recursiveInput;
  runRecursive(X, Y, recursiveInput);

} 