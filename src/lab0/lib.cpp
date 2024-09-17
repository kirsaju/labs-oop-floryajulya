#include "../../include/lib.h"

bool checkBracesValidity(const std::string &str) {
    int counter = 0;

    if (str.length() > 100){
        throw std::invalid_argument("String limit");
    }

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '(') {
            counter += 1;
        }
        else if (str[i] == ')') {
            counter -= 1;
        }
        if (counter == -1) {
            break;
        }
    }

    return counter == 0;    
}

 