class Solution {
public:
    string intToRoman(int num) {
        //always try dividing in multiples of highest possible notation
        //if it's not possible with current multiple , 
        //move to the next lower multiple.
        //whenever we divide the multiple, we need to reduce our no.
        //we will go for this all notations:-
        //1 4  5 9 10  40  50  90  100 400  500  900  1000
        //I IV V IX X  XL  L   LC   C   CD   D    CM   M
        //we do by subtraction method as well as by division.
        string roman;
        //here, Entire array is in decreasing order
        vector<string> notations =
        {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        //and adding their values correspondingly
        vector<int>value={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        //we had taken a pointer which start from left and goes till
        // right from higher value to the lower value
        for(int pos=0;num>0;++pos)
        {
            //while loop will do the substraction as long as
            //the number is greater than equal to the current value
            while(num>=value[pos])
            {
                //As soon as it decreases below the notation value we will go
                //on the previous notation value
                //by doing division we can do it without while loop in 
                //O(1) Time complexcity  i. N/d=x
                roman+=notations[pos];
                num-=value[pos];
                //will return corresponding roman value in our answer
            }
        }
        return roman;
    }
};