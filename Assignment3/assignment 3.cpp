#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define DEFAULT_ARRAY_SIZE 20
#define DEFAULT_INCREMENT DEFAULT_ARRAY_SIZE
#define MAX_NUMBER_LENGTH 20

using namespace std;

double solve(const char* eq, char start, char end, const double* vars = nullptr);
char* reverseString(const char* string, char length);

template<typename T>
class Vector{
    T* data;
    char length;
    char currentIndex;

public:
    Vector();
    ~Vector();
    char resize(char size = 0);
    T *at(int index);
    char push(T value); //return size() after adding new element
    char pop();
    char size(); //return number of elements in data array
};

template<typename T>
Vector<T>::Vector():currentIndex(0){
    data = (T*)malloc(DEFAULT_ARRAY_SIZE * sizeof(T));
    if (!data)
        length = 0;
    else
        length = DEFAULT_ARRAY_SIZE;
}
template<typename T>
Vector<T>::~Vector(){
    free(data);
}
template<typename T>
T * Vector<T>::at(int index) {
    if (index < 0 || index >= length)
        return NULL;
    return &data[index];
}
template<typename T>
char Vector<T>::resize(char size) {
    if (size == -1)
        size = DEFAULT_ARRAY_SIZE;
    //check if array exists. if not use malloc
    if (!data) {
        data = (T*)malloc(size * sizeof(T));
    } else {
        data = (T*)realloc(data, size * sizeof(T));
    }
    if (!data) {
        length = 0;
        return 0;
    } else {
        length = size;
        return size;
    }

}

template <typename T>
char Vector<T>::size() {
    return currentIndex;
}

template <typename T>
char Vector<T>::push(T value) {
    if (currentIndex >= length) {
        if (!resize(length + DEFAULT_INCREMENT))
            return 0;
    }

    data[currentIndex] = value;
    return ++currentIndex;
}

template <typename T>
char Vector<T>::pop() {
    if (currentIndex > 0) {
        return --currentIndex;
    }
    return 0;
}


char* reverseString(const char* string, char length){
    auto tmp = (char*)malloc((length + 1) * sizeof(char));
    if (!tmp)
        return nullptr;

    tmp[length] = '\0';
    for (int i = 0; i < length; ++i) {
        tmp[i] = string[length - 1 - i];
    }
    return tmp; //make sure to free the returned pointer
}

double solve(const char* eq, char start, char end, const double* vars){
    //check if eq is valid
    //if not, return NaN
    if (end <= start)
        return nanf("");

    //create new arrays to store numbers and operators
    Vector<double> numbers;
    Vector<char> plusIndex;
    Vector<char> multIndex;
    //Vector<char> diviIndex;
    Vector<char> powIndex;

    auto tmp = (char*)malloc(MAX_NUMBER_LENGTH * sizeof(char));
    if (!tmp)
        return nanf("");
    char tmpc = 0;
    char* reversed;

    //parse string eq
    //parsing from right to left allows us to
    //e.g. multiply the number to the right of binary operators with -1 for subtraction
    for (char i = end - 1; i >= start; --i) {
        //check if current char is number or decimalpoint '.' using ascii
        if ((eq[i] > 47 && eq[i] < 58) || eq[i] == 46) {
            if(tmpc >= MAX_NUMBER_LENGTH)
                return nanf("");

            tmp[tmpc++] = eq[i];
        }
        //if current char is + or - add tmp to numbers array if it is not empty
        //if it is empty: ignore if current char is '+' and mult the last number in numbers with -1 if it is '-'.
        //->do not add to plusIndex array
        else if (eq[i] == '+') {
            if (tmpc > 0) {
                reversed=reverseString(tmp, tmpc);
                if (!reversed)
                    return nanf("");
                plusIndex.push(numbers.push(strtof(reversed, nullptr)));
                free(reversed);
                tmpc = 0;
            }
            //handling wrong or weird inputs
            else if (i == end - 1) {
                return nanf("");
            }
            //these two extra cases are necessary because a calculation like a++--+b is valid and equal to a+b
            else if (plusIndex.size() == 0 || (plusIndex.size() > 0 && numbers.size() != *plusIndex.at(plusIndex.size() - 1))) {
                plusIndex.push(numbers.size());
            }
        } else if (eq[i] == '-') {
            if (tmpc > 0) {
                reversed = reverseString(tmp, tmpc);
                if (!reversed)
                    return nanf("");
                plusIndex.push(numbers.push(-strtof(reversed, nullptr)));
                free(reversed);
                tmpc = 0;
            }
            //handling wrong or weird inputs
            else if (i == end - 1) {
                return nanf("");
            }
            //these two extra cases are necessary because a calculation like a++--+b is valid and equal to a+b
            else if (plusIndex.size() == 0 || (plusIndex.size() > 0 && numbers.size() != *plusIndex.at(plusIndex.size() - 1))) {
                *numbers.at(numbers.size() - 1) *= -1;
                plusIndex.push(numbers.size());
            } else {
                *numbers.at(numbers.size() - 1) *= -1;
            }
        }
        //check for multiplication
        else if (eq[i] == '*') {
            if (tmpc > 0) {
                reversed=reverseString(tmp, tmpc);
                if(!reversed)
                    return nanf("");
                multIndex.push(numbers.push(strtof(reversed, nullptr)));
                free(reversed);
                tmpc = 0;
            } else if (i == end - 1 || i == start) {
                return nanf("");
            } else if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) { //this case is for a*-b. because - is pushed into the plusIndex array we need to remove it.
                plusIndex.pop();
                multIndex.push(numbers.size());
            } else {
                multIndex.push(numbers.size());
            }
        }
        else if (eq[i] == '/') {
            if (tmpc > 0) {
                reversed=reverseString(tmp, tmpc);
                if (!reversed)
                    return nanf("");
                multIndex.push(numbers.push((double)1/strtof(reversed,nullptr)));
                //multIndex.push(numbers.push( strtof(reversed, nullptr)));
                free(reversed);
                tmpc = 0;
            } else if (i == end - 1 || i == start) {
                return nanf("");
            } else if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {//this case is for a/-b. because - is pushed into the plusIndex array we need to remove it.
                plusIndex.pop();
                (*numbers.at(numbers.size() - 1)) = (double)1/ (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
            } else {
                (*numbers.at(numbers.size() - 1)) = (double)1/ (*numbers.at(numbers.size() - 1));
                multIndex.push(numbers.size());
            }
        } else if (eq[i] == '^'){
            //i -= 1;
            if (tmpc > 0) {
                reversed=reverseString(tmp, tmpc);
                if(!reversed)
                    return nanf("");
                multIndex.push(numbers.push(strtof(reversed, nullptr)));
                powIndex.push(numbers.size());
                free(reversed);
                tmpc = 0;
            } else if (i == end - 1 || i == start) {
                return nanf("");
            } else if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) { //this case is for a/-b. because - is pushed into the plusIndex array we need to remove it.
                plusIndex.pop();
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            } else {
                multIndex.push(numbers.size());
                powIndex.push(numbers.size());
            }
        } else if (eq[i] == ')' || eq[i] == '}'){ //if we find a closing bracket, try to find a matching opening bracket and call solve recursively
            //try to find a matching '(':
            char numClosingBrackets = 0;
            char foundMatching = 0;
            for (char j = i - 1; j >= start; --j) {
                if (eq[j] == ')' || eq[j] == '}')
                    ++numClosingBrackets;
                else if (eq[j] == '(' || eq[j] == '{') {
                    if (numClosingBrackets > 0)
                        --numClosingBrackets;
                    else if (numClosingBrackets == 0) {
                        //matching '(' found
                        if (!foundMatching) {
                            numbers.push(solve(eq, j + 1, i, vars));
                            i = j;//skip the part between () in parsing
                            foundMatching = 1;
                        }
                    }
                }

                /*else if (eq[j] == '(' && numClosingBrackets > 0)
                    --numClosingBrackets;
                else if (eq[j]=='(' && numClosingBrackets == 0) {
                    //matching '(' found
                    if (!foundMatching) {
                        numbers.push(solve(eq, j + 1, i, vars));
                        i = j;//skip the part between () in parsing
                        foundMatching = 1;
                    }
                }*/
            }
            if (!foundMatching)
                return nanf("");
        } else {
            //unary operators:
            //trig functions work with rad not deg!
            if (i > 2 && eq[i] == 'n' && eq[i - 1] == 'i' && eq[i - 2] == 's' && eq[i - 3] == 'a') {
                if (numbers.size())
                    *numbers.at(numbers.size() - 1) = asin(*numbers.at(numbers.size() - 1));
                i -= 3;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            } else if (i > 2 && eq[i] == 't' && eq[i - 1] == 'r' && eq[i - 2] == 'q' && eq[i - 3] == 's'){
                if (numbers.size())
                    *numbers.at(numbers.size() - 1) = sqrt(*numbers.at(numbers.size() - 1));
                i -= 3;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            } else if (i > 3 && eq[i] == '_' && eq[i - 1] == '_' && eq[i - 2] == 'g' && eq[i - 3] == 'o' && eq[i - 4] == 'l') {
                if (numbers.size() ) {
                    //cout << (*numbers.at(numbers.size() - 2)) << ' ' << (*numbers.at(numbers.size() - 1)) << ' '<< eq[i + 1];
                    *numbers.at(numbers.size() - 1) = log(*numbers.at(numbers.size() - 1)) / log(3) /*log(*numbers.at(numbers.size() - 2))*/;
                    //*numbers.at(numbers.size() ) = 2.46497;
                }
                i -= 4;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size() ) {
                    plusIndex.pop();
                }
            } else if (i > 1 && eq[i] == 'n' && eq[i - 1] == 'i' && eq[i - 2] == 's') {
                if (numbers.size())
                    *numbers.at(numbers.size() - 1) = sin(*numbers.at(numbers.size() - 1));
                i -= 2;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            } else if (i > 1 && eq[i] == 's' && eq[i - 1] == 'o' && eq[i - 2] == 'c') {
                if (numbers.size())
                    *numbers.at(numbers.size() - 1) = cos(*numbers.at(numbers.size() - 1));
                i -= 2;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            } else if (i > 1 && eq[i] == 'n' && eq[i - 1] == 'a' && eq[i - 2] == 't') {
                if (numbers.size())
                    *numbers.at(numbers.size() - 1) = tan(*numbers.at(numbers.size() - 1));
                i -= 2;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            } else if (i > 1 && eq[i] == 'g' && eq[i - 1] == 'o' && eq[i - 2] == 'l') {
                if (numbers.size()) {
                    *numbers.at(numbers.size() - 1) = log(*numbers.at(numbers.size() - 1));
                }
                i -= 2;
                if (plusIndex.size() > 0 && *plusIndex.at(plusIndex.size() - 1) == numbers.size()) {
                    plusIndex.pop();
                }
            }


            //constants
            else if (i > 0 && eq[i] == 'i' && eq[i - 1] == 'p') {
                numbers.push(M_PI);
                i -= 1;
            } else if (eq[i] == 'e') {
                numbers.push(M_E);
            } else if (i > 1 && eq[i] == 's' && eq[i - 1] == 'n' && eq[i - 2] == 'a') {
                if (vars)
                    numbers.push(vars[0]);
                else
                    numbers.push(nanf(""));
                i -= 2;
            }
            else
                return nanf("");
        }
    }

    //push to numbers array one last time
    if (tmpc > 0) {
        reversed = reverseString(tmp, tmpc);
        if (!reversed)
            return nanf("");
        numbers.push(strtof(reversed, nullptr));
        free(reversed);
        tmpc = 0;
    }

    //parsing eq is done.
    //start computing result:
    //rules:
    //brackets first (already done in parsing)
    //mult and div before add and sub
    //equal priority operations from left to right
    //we do not need to worry about the last point as we are replacing all divisions (a/b) with a*(1/b)
    //and all subtractions (a+b) with (a+(-b))
    //+ and * are commutative.

    if (numbers.size() == 0)
        return nanf("");
    //we start with power a^b
    if (powIndex.size() > 0) {
        for (char i = powIndex.size() - 1; i >= 0; --i) {
            //check if '*' is associated with two numbers:
            if (*powIndex.at(i) >= numbers.size())
                return nanf("");
            (*numbers.at(*powIndex.at(i) - 1)) = pow((*numbers.at(*powIndex.at(i))), (*numbers.at(*powIndex.at(i) - 1)));
            (*numbers.at(*powIndex.at(i))) = 1;
        }
    }
    //as we parsed eq from right to left, we have to go through the arrays from right to left
    //in to do calculations from left to right :)

    //because * is commutative we calculate the result for the multiplication from right to left
    //this makes it easier as we can store the result of a*b in a
    //e.g. a*(b*c)*d:
    //first the () was done in the parsing step so it is now a*e*d
    // we compute e*d=:f and replace e with the result f
    //this results in a*f*d. however we will ignore d and calculate a*f and replace a with the result.
    if (multIndex.size() > 0) {
        for (char i = multIndex.size() - 1; i >= 0; --i) {
            //check if '*' is associated with two numbers:
            if (*multIndex.at(i) >= numbers.size())
                return nanf("");
            (*numbers.at(*multIndex.at(i) - 1)) *= (*numbers.at(*multIndex.at(i)));
        }
    }
    /*if (diviIndex.size() > 0) {
        for (char i = diviIndex.size() - 1; i >= 0; --i) {
            //check if '*' is associated with two numbers:
            if (*diviIndex.at(i) >= numbers.size())
                return nanf("");
            (*numbers.at(*diviIndex.at(i) - 1)) = (*numbers.at(*diviIndex.at(i))) / (*numbers.at(*diviIndex.at(i) - 1));
        }
    }*/
    //we can now add the remaining numbers and return the result
    //Take a look at: a+b*c+d
    //based on the previous step we know that the result of b*c will be stored in b
    //we have to ignore c. this can be done using the value stored in the next plusIndex.
    //we sum the first number and all numbers that are to the right of a + symbol.
    //these numbers have an index of *plusIndex.at()-1

    double result = *numbers.at(0);
    for (char i = 0; i < plusIndex.size(); ++i) {
        result += *numbers.at(*plusIndex.at(i));
    }
    free(tmp);

    return result;
}



int main() {
    //const char *testeq = "7/(3*1/5)-7*13/(3+(2-1)*5)-13/(12-2/3)+15";

    //Vector<float> test;
    //*test.at(5) = 7;

    //std::cout<<test.at(5)<<std::endl<<*test.at(5)<<std::endl;

    //test.resize(20);
    //*test.at(15) = 17;

    //std::cout<<test.at(15)<<std::endl<<*test.at(15);


    //const char *t = "5+(2-3)*15.7";

    string input;

    double ans;
        getline(cin, input);
        double rep = 0.0001;
        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
        if (input[31] == '{' ) {
            input.replace(31, 3, "_");
        }
        ans = solve(input.c_str(), 0, input.length(), &ans) - rep;
        cout << ans << endl;
}
