/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int current_position = n / 2;

        while ( true ) {
            int currect = guess(current_position);
            if ( currect == -1 )
                current_position--;
            else if (currect == 1)
                current_position++;
            else return current_position;
        }
        return 0;
    }   
};