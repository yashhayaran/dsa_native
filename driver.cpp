#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
#include <tuple>
#include <iostream>
#include <sstream>

#include "src/dsa_solutions/array.hpp"
#include "src/dsa_solutions/search.cpp"
#include "src/dsa_solutions/bit_manipulations.hpp"
#include "src/dsa_solutions/matrix.hpp"
#include "src/dsa_solutions/string.hpp"
#include "src/dsa_solutions/tree.hpp"
#include "src/design/design_patterns.hpp"
#include "src/dsa_solutions/heap.hpp"
#include "src/design/tic_tac_toe.hpp"
#include "src/dsa_solutions/heap.hpp"
#include "src/dsa_solutions/dynamic.hpp"
#include "src/basics/notes.hpp"
#include "src/dsa_solutions/linked_list.hpp"
#include "src/dsa_solutions/back_tracking.hpp"
#include "src/design/test.hpp"

namespace TESTER
{
    template <typename T>
    std::string formatVector(const std::vector<T>& vec)
    {
        std::stringstream s;
        for (auto& e: vec)
        {
            s << e << ",";
        }
        return s.str();
    }

    int dsa_test_driver()
    {   
        // Solutions::HeapOOPS::test();
        // Solutions::LinkedList::test_solution();
        // Solutions::String::test();
        Solutions::Backtracking::test();

        return 0; 
    }

    void basics_test_driver()
    {
        //Basics::TYPEID::example();
        Basics::OOPS_BASICS::test();
    }
}

int main()
{
    std::cout << "Hey" << std::endl;
    
    TESTER::dsa_test_driver();
    //TESTER::basics_test_driver();
    
    return 0;
}