#include "tests.h"
#include "utility.h"
#include <string>
#include <iostream>

void assertEquals(std::string expected, std::string actual, std::string testDescription){
    if(expected == actual){
        std::cout << "PASSED " << testDescription << std::endl;
    }
    else{
        std::cout << "FAILED " << testDescription << std::endl;
        std::cout << "EXPECTED: " << expected << std::endl;
        std::cout << "ACTUAL: " << actual << std::endl;
    }
}

void assertEquals(int expected, int actual, std::string testDescription){
    if(expected == actual){
        std::cout << "PASSED " << testDescription << std::endl;
    }
    else{
        std::cout << "FAILED " << testDescription << std::endl;
        std::cout << "EXPECTED: " << expected << std::endl;
        std::cout << "ACTUAL: " << actual << std::endl;
    }
}

void assertEquals(double expected, double actual, std::string testDescription){
    if(expected == actual){
        std::cout << "PASSED " << testDescription << std::endl;
    }
    else{
        std::cout << "FAILED " << testDescription << std::endl;
        std::cout << "EXPECTED: " << expected << std::endl;
        std::cout << "ACTUAL: " << actual << std::endl;
    }
}

void assertEquals(bool expected, bool actual, std::string testDescription){
    if(expected == actual){
        std::cout << "PASSED " << testDescription << std::endl;
    }
    else{
        std::cout << "FAILED " << testDescription << std::endl;
        std::cout << "EXPECTED: " << expected << std::endl;
        std::cout << "ACTUAL: " << actual << std::endl;
    }
}

void test_InsertRoot(){
    MovieList newList;
    Movie newMovie = Movie("ABCDEF", 6.9);
    assertEquals(true, newList.insert(newMovie), "Testing regular insertion case");
    assertEquals("ABCDEF", newList.getRoot()->getTitle(), "Testing Inserting into Root (Title)");
    assertEquals(6.9, newList.getRoot()->getRating(), "Testing Inserting Into Root (Rating)");
}

void test_MultipleInserts(){
    MovieList newList;
    Movie movie1 = Movie("ABCDEF", 6.9);
    Movie movie2 = Movie("ABCDEF", 6.9);
    assertEquals(true, newList.insert(movie1), "Testing regular insertion case");
    assertEquals(false, newList.insert(movie2), "Testing Inserting Duplicate Case");
}

void test_DepthForRoot(){
    MovieList newList;
    Movie movie1 = Movie("ABCDEF", 6.9);
    newList.insert(movie1);
    assertEquals(0, newList.getDepth("ABCDEF"), "Testing depth for root");

}
void test_DepthForNonRoot(){
    MovieList newList;
    Movie movie1 = Movie("A", 6.9);
    Movie movie2 = Movie("B", 2.1);
    Movie movie3 = Movie("C", 3.4);
    Movie movie4 = Movie("D", 3.6);
    newList.insert(movie1);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie4);
    assertEquals(1, newList.getDepth("B"), "Testing depth for one level down");
    assertEquals(2, newList.getDepth("C"), "Testing depth for two levels down");
    assertEquals(3, newList.getDepth("D"), "Testing depth for three levels down");
}

void test_printPreOrderForEmptyBST(){
    MovieList newList;
    std::cout << "Testing PreOrder for Empty BST" << std::endl;
    newList.printPreOrder();
    std::cout << std::endl;
    Movie movie1 = Movie("A", 6.9);
    Movie movie2 = Movie("B", 2.1);
    Movie movie3 = Movie("C", 3.4);
    Movie movie4 = Movie("D", 3.6);
    newList.insert(movie1);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie4);

}
void test_printPreOrderForOneElement(){
    MovieList newList;
    Movie movie1 = Movie("A", 6.9);
    newList.insert(movie1);
    std::cout << "Testing PreOrder for One Element" << std::endl;
    newList.printPreOrder();
    std::cout << std::endl;
}
void test_printPreOrderGeneralCase(){
    MovieList newList;
    Movie movie1 = Movie("A", 6.9);
    Movie movie2 = Movie("B", 2.1);
    Movie movie3 = Movie("C", 3.4);
    Movie movie4 = Movie("D", 3.6);
    newList.insert(movie1);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie4);
    std::cout << "Testing PreOrder for General Case" << std::endl;
    newList.printPreOrder();
    std::cout << std::endl;
}
void test_getBestMovieForNonPresentMovie(){
    MovieList newList;
    Movie movie1 = Movie("The Apple", 6.9);
    Movie movie2 = Movie("The Bread", 2.1);
    Movie movie3 = Movie("The Chicken", 3.4);
    Movie movie4 = Movie("The Dragon", 3.6);
    Movie movie5 = Movie("Different", 10.0);
    newList.insert(movie1);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie4);
    newList.insert(movie5);
    std::cout << "testing getting best movie with nonpresent prefix (Blank)" << std::endl;
    newList.getBestMovie("Hello");
}
void test_getBestMovieWithPrefixOrdered(){
    MovieList newList;
    Movie movie1 = Movie("The Apple", 6.9);
    Movie movie2 = Movie("The Bread", 2.1);
    Movie movie3 = Movie("The Chicken", 3.4);
    Movie movie4 = Movie("The Dragon", 3.6);
    Movie movie5 = Movie("Different", 10.0);
    newList.insert(movie5);
    newList.insert(movie1);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie4);
    std::cout << "testing getting best movie in order (The Apple 6.9)" << std::endl;
    newList.getBestMovie("The");
}

void test_getBestMovieWithPrefixRandom(){
    MovieList newList;
    Movie movie1 = Movie("The Apple", 6.9);
    Movie movie2 = Movie("The Bread", 2.1);
    Movie movie3 = Movie("The Chicken", 3.4);
    Movie movie4 = Movie("The Dragon", 3.6);
    Movie movie5 = Movie("Different", 10.0);
    newList.insert(movie4);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie1);
    newList.insert(movie5);
    std::cout << "testing getting best movie randomized (The Apple 6.9)" << std::endl;
    newList.getBestMovie("The");
}

void test_prefixContains(){
    assertEquals(true, containsPrefix("the", "the american president"), "testing prefix in title");
    assertEquals(false, containsPrefix("the", "spiderman"), "testing prefix not in title");
}

void test_search(){
    MovieList newList;
    Movie movie1 = Movie("The Apple", 6.9);
    Movie movie2 = Movie("The Bread", 2.1);
    Movie movie3 = Movie("The Chicken", 3.4);
    Movie movie4 = Movie("The Dragon", 3.6);
    Movie movie5 = Movie("Different", 10.0);
    newList.insert(movie4);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie1);
    newList.insert(movie5);
    assertEquals(true, newList.search("The Apple"), "searching for present movie");
    assertEquals(false, newList.search("Up"), "searching for absent movie");
}

void test_totalnodes(){
    MovieList newList, newList2;
    Movie movie1 = Movie("The Apple", 6.9);
    Movie movie2 = Movie("The Bread", 2.1);
    Movie movie3 = Movie("The Chicken", 3.4);
    Movie movie4 = Movie("The Dragon", 3.6);
    Movie movie5 = Movie("Different", 10.0);
    newList.insert(movie4);
    newList.insert(movie2);
    newList.insert(movie3);
    newList.insert(movie1);
    newList.insert(movie5);
    assertEquals(0, newList2.getTotalNodes(), "Testing total nodes on empty BST");
    assertEquals(5, newList.getTotalNodes(), "Testing total nodes with regular BST");
}

void runAllTests(){
    test_InsertRoot();
    test_MultipleInserts();
    test_DepthForRoot();
    test_DepthForNonRoot();
    test_printPreOrderForEmptyBST();
    test_printPreOrderForOneElement();
    test_printPreOrderGeneralCase();
    test_getBestMovieForNonPresentMovie();
    test_getBestMovieWithPrefixOrdered();
    test_getBestMovieWithPrefixRandom();
    test_prefixContains();
    test_search();
    test_totalnodes();
}

int main(){
    runAllTests();
    return 0;
}