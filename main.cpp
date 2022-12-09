#include <iostream>
#include <string>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
    string subseq = "";
    string temp = "";
     int m = str1.length();
     int n = str2.length();
     int mat[m + 1][n + 1]; //creating a matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0){
                mat[i][j] = 0; //first column/row full of zeros
            }
            else if (str1[i - 1] == str2[j - 1]){
                mat[i][j] = mat[i - 1][j - 1] + 1; //when match, inc the value of the top left by one store in current
            }
            else{
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]); // if they don't match set current to the current max length (used for traversing purposes)
             } //case of matching or not matching store values from previous cells to keep track of the longest sequence thus far
        }
    }
//traversing the matrix to store characters in subsequence in a temp string
    while (m&&n) {
         if (str1[m - 1] == str2[n - 1]) {
            temp+= str1[m-1];
            m--;
            n--;
        }
        else if (mat[m - 1][n] > mat[m][n - 1]){
            m--;
        }
        else{
            n--;
        }
    } //because we traversed the matrix from top to bottom substring was stored in reverse order
 //Since stored in temp in reverse order, have to undo when storing to subsequence
    for(int i = temp.length(); i>=0;i--){
        subseq+= temp[i];
    }
 return temp;
  

}

// main to test findMaxSubSeq
// The actual test cases will provide their own command line arguments
int main(int argc, char const* argv[])
{
	// example sequences A, B
	string a = argv[1];

	string b = argv[2];

	string maxSubSeq = findMaxSubSeq(a, b);

	cout << maxSubSeq << endl;
    

	return 0;
}
