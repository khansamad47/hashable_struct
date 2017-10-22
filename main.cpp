#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

#include<boost/functional/hash.hpp>

struct Hashable {
    std::string d_name;
    int d_age;
    Hashable(std::string name, int age): d_name(name), d_age(age) {}
    bool operator==(const Hashable &other) const{
        return (d_name == other.d_name) && (d_age == other.d_age);
    }

};

struct Hasher
{
  std::size_t operator () (const Hashable &obj) const 
  {
    std::size_t seed = 0;
    boost::hash_combine(seed, boost::hash_value(obj.d_name));
    boost::hash_combine(seed, boost::hash_value(obj.d_age));
    return seed;
  }
};

int main() {
    std::unordered_map<Hashable, int, Hasher> myMap;
    Hashable rohit("Rohit", 25);
    myMap[rohit] = 5;
    //std::unordered_map<Hashable, int>::const_iterator map_iter = myMap.find(Hashable("Rohit", 25));
    auto map_iter = myMap.find(Hashable("Rohit", 25));
    
    if(map_iter != myMap.end()){
        std::cout << "Found!" << "\n";
    }
    else {
        std::cout << "Not Found!" << "\n";
    }
    // Rohit's code
    // Construct map for all possible comdinations of the col valus
    /*
    for(){
        // step1. construct struct for the current row
        // step2. check if struct is in the map
        //        if so get the value string stored in the map
        // step3. else get the value string in the else condition
    }
    */
    return 0;
}
