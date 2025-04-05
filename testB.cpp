#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/array_functions/array_functions.h"
// ^^../..  exits out of the 2 folders and gets us into the right folders 
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_allocate(bool debug = false)
{
  int capacity = 5;
  allocate<int>(capacity);
  return true;
}

bool test_reallocate(bool debug = false) 
{
  int capacity = 5;
  int size = 5;
  int *a = allocate<int>(6);
  //*a = {1,2,3,4,5}; you cant do this cause a is a pointer 
  //cout << "Array a after reallocation: ";
  // print_array(a, size, capacity);
  // cout << endl;

  // cout << "Array a after reallocation: ";
  reallocate(a, size, capacity);
  //print_array(a, size, capacity);
  cout << endl;
  return true;
}

bool test_print(bool debug = false)
{
  int arr[5]={1,2,3,4,5};
  int *a = arr;
  //print(a,5, cout);

  return true;

}

bool test_search_entry(bool debug = false)
{
  int arr[5]={1,2,3,4,34};
  int *a = arr;
  int size = 10;
  int key = 3;
  int* address = search_entry(a, size, 34);
  if(address != &a[4])
  {
    return false;
  }


  return true;
}

bool test_shiftLeft(bool debug = false)
{
  int arr[]={15,25,35,45,55,65,0,0,0};
  int arr2[]={15,25,35,45,55,65, 0, 0, 0};
int size = 7;
shift_left<int>(arr, size, 4);
if(arr[4] == arr2[4])
{
  cout << arr[4] << " == " << arr2[4] << endl;
  return false;
}
// if(debug = true)
// {
//   cout << "Array before shift left: ";
//   print_array(arr, size, 6);
//   cout << "Array after shift left: ";
//   print_array(arr2, size, 6);
// }
return true;
}

bool test_shiftLeftPointer(bool debug = false)
{
  int arr[]={15,25,35,45,55,65,0,0,0};
  int arr2[]={15,25,35,45,55,65, 0, 0, 0};
  int *p = arr;
  int size = 7;
shift_left(p, size, 4);
if(arr[4] == arr2[4])
{
  cout << arr[4] << " == " << arr2[4] << endl;
  return false;
}
return true;
}

bool test_shiftRight(bool debug = false)
{
  int arr[]={15,25,35,45,55,65,0,0,0};
  //int arr2[]={15,25,35,45,55,65, 0, 0, 0};

int size = 7;
shift_right<int>(arr, size, 4);
if(arr[4] != arr[5])
{
  cout << arr[4] << " == " << arr[5] << endl;
  return false;
}
return true;
}

bool test_shiftRightPointer(bool debug = false)
{
  int arr[]={15,25,35,45,55,65,0,0,0};
  //int arr2[]={15,25,35,45,55,65, 0, 0, 0};
  int *p = arr;

int size = 7;
shift_right(p, size, 4);
if(arr[4] != arr[5])
{
  cout << arr[4] << " == " << arr[5] << endl;
  return false;
}
return true;
}

bool test_copyArray(bool debug = false)
{
  int arr[]={15,25,35,45,55,65};
  int arr2[]={15,25,35,45,55,65};

  int size = 7;
  copy_array(arr, size);
  return true;
}

bool test_arrayString()
{

}

// bool test_printArray(bool debug = false)
// {
//   int arr[5]={1,2,3,4,5};
//   int *a = arr;
//   print_array(a,5, 5);

//   return true;

// }


// TEST(TEST_PRINTARRAY, test_printArray){
//   EXPECT_EQ(1, test_printArray(false));
// }

TEST(TEST_COPYARRAY, Test_CopyArray) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_copyArray(false));
}

TEST(TEST_SHIFTRIGHTPOINTER, Test_ShiftRightPointer) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shiftRightPointer(false));
}

TEST(TEST_SHIFTRIGHT, Test_ShiftRight) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shiftRight(false));
}

TEST(TEST_SHIFTLEFTPOINTER, Test_ShiftLeftPointer) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shiftLeftPointer(false));
}

TEST(TEST_SHIFTLEFT, Test_ShiftLeft) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shiftLeft(false));
}
  

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_ALLOCATE, TestAllocate) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_allocate(false));
}

TEST(TEST_REALLOCATE, TestReallocate) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_reallocate(false));
}

TEST(TEST_PRINT, TestPrint) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_print(false));
}

TEST(TEST_SEARCH_ENTRY, test_search_entry) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_search_entry(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}