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
        int right_position{ 0 };
        int left_position = n;

        while (right_position < left_position ) {
            int middle_position = (right_position + left_position) / 2;

            int currect = gues_number(middle_position);
            if (currect == -1)
                left_position = middle_position - 1;
            else if (currect == 1)
                right_position = middle_position + 1;
            else return middle_position;
        }
        return 0;
    }   
};