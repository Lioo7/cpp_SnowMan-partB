#include "snowman.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace ariel
{
    const int H = 0; // Hat
    const int N = 1; // Nose
    const int L = 2; // Left Eye
    const int R = 3; // Right Eye
    const int X = 4; // Left Arm
    const int Y = 5; // Right Arm
    const int T = 6; // Torso
    const int B = 7; // Base
    const int LEN = 8; // Valid Length 

    // Utility functions
    string hat(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = " _===_";
            break;
        case '2':
            str = "  ___\n .....";
            break;
        case '3':
            str = "   _\n  /_\\";
            break;
        case '4':
            str = "  ___\n (_*_)";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string nose(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = ",";
            break;
        case '2':
            str = ".";
            break;
        case '3':
            str = "_";
            break;
        case '4':
            str = " ";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between 1-4"};
        }
        return str;
    }

    string left_eye(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = ".";
            break;
        case '2':
            str = "o";
            break;
        case '3':
            str = "O";
            break;
        case '4':
            str = "-";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string right_eye(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = ".";
            break;
        case '2':
            str = "o";
            break;
        case '3':
            str = "O";
            break;
        case '4':
            str = "-";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string left_arm(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = "<";
            break;
        case '2':
            str = "\\";
            break;
        case '3':
            str = "/";
            break;
        case '4':
            str = "";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string right_arm(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = ">";
            break;
        case '2':
            str = "/";
            break;
        case '3':
            str = "\\";
            break;
        case '4':
            str = "";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string torso(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = " : ";
            break;
        case '2':
            str = "] [";
            break;
        case '3':
            str = "> <";
            break;
        case '4':
            str = "   ";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    string base(char num)
    {
        string str;
        switch (num)
        {
        case '1':
            str = " : ";
            break;
        case '2':
            str = "\" \"";
            break;
        case '3':
            str = "___";
            break;
        case '4':
            str = "   ";
            break;
        default:
            throw std::out_of_range{"The input must be an integer between '1'-'4'"};
        }
        return str;
    }

    // Main function
    string snowman(int x)
    {
        string str = to_string(x);
        if (str.length() != LEN)
        {
            throw std::out_of_range{"The length of the input must be eight"};
        }

        bool l_exist = false;
        if (str[X] != '4') {l_exist = true;}
        bool l_up = false;
        if (str[X] == '2') {l_up = true;}
        bool r_up = false;
        if (str[Y] == '2') {r_up = true;}

        // if(left_exist){
        //     snow += " ";
        //     snow += hat(str[0]);
        //     snow += "\n";
        // }
        // else{
        //     snow += hat(str[0]);
        //     snow += "\n";
        // }

        // if(left_up){
        //     snow += left_arm(str[4]);
        //     snow += "(";
        //     snow += left_eye(str[2]);
        //     snow += nose(str[1]);
        //     snow += right_eye(str[3]);
        //     snow += ")";
        // }
        // else{
        //     snow += " ";
        //     snow += "(";
        //     snow += left_eye(str[2]);
        //     snow += nose(str[1]);
        //     snow += right_eye(str[3]);
        //     snow += ")";
        // }

        // if(right_up){
        //     snow += right_arm(str[5]);
        //     snow += "\n";
        // }

        // if(!left_up){
        //     snow += left_arm(str[4]);
        // }

        // if(!left_exist || !left_up){
        //     snow += left_arm(str[4]);
        //     snow += "(";
        //     snow += torso(str[6]);
        //     snow += ")";
        // }

        // if(!right_up){
        //     snow += right_arm(str[5]);
        //     snow += "\n";
        // }
        // else{
        //     snow += "\n";
        // }

        // if(left_exist){
        //     snow += " ";
        //     snow += "(";
        //     snow += base(str[7]);
        //     snow += ")";
        // }
        // else{
        //     snow += "(";
        //     snow += base(str[7]);
        //     snow += ")";
        // }

        // Creates a variable for each part of the body
        string snow_body;
        string hat_s = hat(str[H]);
        string nose_s = nose(str[N]);
        string left_eye_s = left_eye(str[L]);
        string right_eye_s = right_eye(str[R]);
        string left_arm_s = left_arm(str[X]);
        string right_arm_s = right_arm(str[Y]);
        string torso_s = torso(str[T]);
        string base_s = base(str[B]);

        if (!l_exist)
        {
            switch (str[H])
            {
            case '1':
                hat_s = "_===_";
                break;
            case '2':
                hat_s = " ___\n.....";
                break;
            case '3':
                hat_s = "  _\n /_\\";
                break;
            case '4':
                hat_s = " ___\n(_*_)";
                break;
            }
        }

        torso_s = "(" + torso_s + ")";
        base_s = "(" + base_s + ")";

        string head_s = "(" + left_eye_s + nose_s + right_eye_s + ")";

        if (l_up)
        {
            head_s = left_arm_s + head_s;
            base_s = " " + base_s;
            torso_s = " " + torso_s;
        }
        else if (l_exist && !l_up)
        {
            torso_s = left_arm_s + torso_s;
            head_s = " " + head_s;
            base_s = " " + base_s;
        }

        if (r_up)
        {
            head_s = head_s + right_arm_s;
        }
        else if (!r_up)
        {
            torso_s = torso_s + right_arm_s;
        }

        snow_body = hat_s + "\n" + head_s + "\n" + torso_s + "\n" + base_s;
        return snow_body;
    }

} // namespace ariel
