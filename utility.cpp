#include "utility.h"

bool containsPrefix(std::string prefix, std::string title){
    int prelen = prefix.length();
    if(prelen > title.length()) { return false; }  // title can't contain prefix if it is shorter than prefix
    std::string pretitle = title.substr(0, prelen);  // get substring of title
    return (prefix == pretitle);  // check if the prefixes are equal
}

bool lessPrefix(std::string prefix, std::string title){
    int prelen = prefix.length();
    std::string pretitle = title.substr(0, prelen);
    return (prefix < pretitle);
}