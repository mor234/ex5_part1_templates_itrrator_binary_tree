
#include "doctest.h"
#include <bits/stdc++.h>//rand
#include <iostream>
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;


 



  
int genrate_random_positive_negative() {

}

int genrate_random_double() {
    double tmp_rand = ((double) rand() / (rand() + 0.1));
    return tmp_rand * genrate_random_positive_negative();
}


TEST_CASE("good tests")
{
    


}

TEST_CASE("bad tests")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(1));    
    CHECK_NOTHROW(tree_of_ints.add_left(1, 9) );     // Now 9 is the left child of 1
    CHECK_NOTHROW(tree_of_ints.add_left(9, 4).add_right(9, 5) );     // Now 4 is the left child of 9
    CHECK_NOTHROW(tree_of_ints.add_right(9, 5)  );   // Now 5 is the right child of 9
    CHECK_NOTHROW(tree_of_ints.add_right(1, 3) );    // Now 3 is the right child of 1
    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
    CHECK_NOTHROW(cout << tree_of_ints << endl);  /* Prints the tree in a reasonable format. For example:*/
    vector<int> vec_check{};
    vector<int> vec_ans{};
    vec_ans.push_back(1);
    vec_ans.push_back(2);
    vec_ans.push_back(3);
    vec_ans.push_back(4);
    vec_ans.push_back(5);

    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        vec_check.push_back((*it));
    }  // prints: 1 2 4 5 3
    CHECK_EQ(vec_check,vec_ans);
    vec_check.clear();
    vec_ans.clear();
     vec_ans.push_back(4);
    vec_ans.push_back(2);
    vec_ans.push_back(5);
    vec_ans.push_back(1);
    vec_ans.push_back(3);
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        vec_check.push_back((*it));
  }  // prints: 4 2 5 1 3 
      CHECK_EQ(vec_check,vec_ans);
    vec_check.clear();

  for (int element: tree_of_ints) {  // this should work like inorder
        vec_check.push_back((element));
  }  // prints: 4 2 5 1 3 
      CHECK_EQ(vec_check,vec_ans);


 vec_check.clear();
    vec_ans.clear();
     vec_ans.push_back(4);
    vec_ans.push_back(5);
    vec_ans.push_back(2);
    vec_ans.push_back(3);
    vec_ans.push_back(1);


for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        vec_check.push_back((*it));
  }  // prints: 4 5 2 3 1
   
      CHECK_EQ(vec_check,vec_ans);

  // The same should work with other types, e.g. with strings:
  vector<string> vec_check_str{};
    vector<string> vec_ans_str{};
  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root("1")     
  .add_left("1", "9")      // Now 9 is the left child of 1
  .add_left("9", "4")      // Now 4 is the left child of 9
  .add_right("9", "5")     // Now 5 is the right child of 9
  .add_right("1", "3")     // Now 3 is the right child of 1
  .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  CHECK_NOTHROW( cout << tree_of_strings << endl); 
   vec_ans_str.push_back("1");
    vec_ans_str.push_back("2");
    vec_ans_str.push_back("4");
    vec_ans_str.push_back("5");
    vec_ans_str.push_back("3");

  for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
   vec_check_str.push_back(*it);
  }  // prints: 1 2 4 5 3
        CHECK_EQ(vec_check_str,vec_ans_str);

  for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 2 5 1 3 
  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 5 2 3 1

  // demonstrate the arrow operator:
  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
    cout << it->size() << " " ;
  }  // prints: 1 1 1 1 1 


  for (const string& element: tree_of_strings) {  // this should work like inorder
    cout << element << " " ;
  }   // prints: 4 2 5 1 3 

}