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
        // Checks that the input is valid 
        string str = to_string(x);
        if (str.length() != LEN)
        {
            throw std::out_of_range{"The length of the input must be eight"};
        }

        // Checks if the snowman has a left arm
        bool l_exist = false;
        if (str[X] != '4') {l_exist = true;}
        // Checks if the left hand of snowman is up
        bool l_up = false;
        if (str[X] == '2') {l_up = true;}
        // Checks if the right hand of snowman is up
        bool r_up = false;
        if (str[Y] == '2') {r_up = true;}

        // Builds the snowman

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

        // Adds space before the hat if the snowman has no left hand 
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

        // Adds space before the base and the torso if the left is up
        if (l_up)
        {
            head_s = left_arm_s + head_s;
            base_s = " " + base_s;
            torso_s = " " + torso_s;
        }
        // If not adds space before the head and the base
        else if (l_exist && !l_up)
        {
            torso_s = left_arm_s + torso_s;
            head_s = " " + head_s;
            base_s = " " + base_s;
        }
        // Adds the arm after the head if the right arm is up
        if (r_up)
        {
            head_s = head_s + right_arm_s;
        }
        // Adds the right arm after the torso if the right arm is not up 
        else if (!r_up)
        {
            torso_s = torso_s + right_arm_s;
        }
        // Unions all the parts of the snowman and returns it
        snow_body = hat_s + "\n" + head_s + "\n" + torso_s + "\n" + base_s;
        return snow_body;
    }

} // namespace ariel
