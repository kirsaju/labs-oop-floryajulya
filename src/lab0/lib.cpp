// Copyright 2023 SomeName

#include "../../include/lib.h"

bool checkBracesValidity(std::string str) {
    int counter = 0;

    if (str.length() <= 100){
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '('){
                counter += 1;
            }
            if (str[i] == ')'){
                counter -= 1;
            }
            if (counter == -1){
                break;
            }
        }
    }
    else {
        throw std::invalid_argument("String limit");
    } 

    return counter == 0;    
}

 